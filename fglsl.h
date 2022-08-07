#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace FGLSL {

    enum PreprocessFlags : unsigned int {
        NONE = 0,
        ABSOLUTE_PATH = 1 << 0,
        //OUTPUT_COMPILED_SHADERS = 1 << 1,
    };
    namespace Internal {
        inline void _ltrim(std::string& s) {
            s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
                return !std::isspace(ch);
                }));
        }

        // trim from end (in place)
        inline void _rtrim(std::string& s) {
            s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
                return !std::isspace(ch);
                }).base(), s.end());
        }

        // trim from both ends (in place)
        inline void _trim(std::string& s) {
            _ltrim(s);
            _rtrim(s);
        }

        std::vector<std::string> ReadShader(std::filesystem::path file) {
            std::ifstream fs;
            std::string line;
            auto lines = std::vector<std::string>();
            fs.open(file, std::ifstream::in);
            if (fs.is_open()) {
                while (std::getline(fs, line))
                {
                    lines.push_back(line);
                }
                fs.close();
            }
            return lines;
        }

        struct FGSLToken {
            int line;
            std::string name;
            std::vector<std::string> values = std::vector<std::string>();

            FGSLToken(int line, std::string name) : line(line), name(name) {

            }
        };
        struct Range {
            int start, else_p, end;
            Range(int start, int else_p, int end) : start(start), else_p(else_p), end(end) {}
        };

        struct FGSLTokenResult {
            std::string name;
            std::string value;
            int line;

            FGSLTokenResult(std::string name, std::string value, int line) : name(name), value(value), line(line) {

            }
        };

        struct FGLSLConditionalResult {
            std::string name;
            bool active;
            FGLSLConditionalResult(std::string name, bool active) : name(name), active(active) {

            }
        };
        struct FGLSLConditional {
            std::vector<Range> ranges = std::vector<Range>();
            std::string name;
            int value = 0; // 0 = Not defined, 1 = False defined, 2 = True Defined, 3 = Both defined
            FGLSLConditional(std::string name) : name(name) {

            }
        };

        struct FGLSLShader {
            std::vector<std::string> content = std::vector<std::string>();
            std::vector<FGSLToken> tokens = std::vector<FGSLToken>();
            std::vector<FGLSLConditional> conditional = std::vector<FGLSLConditional>();

        private:
            int getToken(std::string name) {
                for (int i = 0; i < tokens.size(); i++) {
                    if (tokens[i].name == name) {
                        return i;
                    }
                }
                return -1;
            }
            int getConditional(std::string name) {
                for (int i = 0; i < conditional.size(); i++) {
                    if (conditional[i].name == name) {
                        return i;
                    }
                }
                return -1;
            }

        public:
            bool SetValue(std::string name, std::string value) {
                int index = getToken(name);
                if (index == -1)
                    return false;

                tokens[index].values.push_back(value);
            }
            bool SetCondition(std::string name, bool value) {
                int index = getConditional(name);
                if (index == -1)
                    return false;
                if ((value && conditional[index].value == 1) || (!value && conditional[index].value == 2)) {
                    conditional[index].value = 3;
                }
                else if (value) {
                    conditional[index].value = 2;
                }
                else {
                    conditional[index].value = 1;
                }
            }

            void ClearValues() {
                for (int i = 0; i < tokens.size(); i++) {
                    tokens[i].values.clear();
                }

                for (int i = 0; i < conditional.size(); i++) {
                    conditional[i].value = 0;
                }
            }
        };

        // Builds the full shader from the sub-shaders by copying files.
        std::vector<std::string> Resolve(std::vector<std::string> code, std::filesystem::path directory) {
            auto result = std::vector<std::string>();
            for (auto l : code) {
                if (l._Starts_with("//$")) {
                    l.erase(0, 3);
                    _trim(l);

                    std::string token = l.substr(0, l.find(" "));

                    if (token == "INCLUDE") {
                        std::string shader = l.substr(l.find(" ") + 1);
                        auto curDir = std::filesystem::path(directory).append(shader);
                        for (auto cl : Resolve(ReadShader(curDir), curDir.parent_path())) {
                            result.push_back(cl);
                        }
                    }
                    else {
                        result.push_back("//$" + l);
                    }
                }
                else {
                    result.push_back(l);
                }
            }
            return result;
        }


        struct Combination {
            std::vector<FGSLTokenResult> results = std::vector<FGSLTokenResult>();
            std::vector<FGLSLConditionalResult> cond_results = std::vector<FGLSLConditionalResult>();

            void Clone(Combination c) {
                for (auto cur : c.results) {
                    results.push_back(cur);
                }
                for (auto cur : c.cond_results) {
                    cond_results.push_back(cur);
                }
            }
        };

        struct GLSLShader {
            std::string code;
            int programID = -1;
            std::vector<FGSLTokenResult> settings = std::vector<FGSLTokenResult>();
            std::vector<FGLSLConditionalResult> conditions = std::vector<FGLSLConditionalResult>();
        };

        std::vector<Combination> GetCombinations(int i, std::vector<FGSLToken> tokens, std::vector<FGLSLConditional> cond, bool conditionals = true) {
            if (conditionals) {
                std::vector<Combination> c;
                if (i >= cond.size()) {
                    if (cond.size() > 0)
                        return c;
                    return GetCombinations(0, tokens, cond, false);
                }
                if (i == cond.size() - 1)
                    c = GetCombinations(0, tokens, cond, false);
                else
                    c = GetCombinations(i + 1, tokens, cond);
                if (c.empty()) {
                    if (cond[i].value == 0 || cond[i].value == 1) {
                        Combination co;
                        co.cond_results.push_back(FGLSLConditionalResult(cond[i].name, false));
                        c.push_back(co);
                        return c;
                    }
                    if (cond[i].value == 2) {
                        Combination co;
                        co.cond_results.push_back(FGLSLConditionalResult(cond[i].name, true));
                        c.push_back(co);
                        return c;
                    }
                    if (cond[i].value == 3) {
                        Combination co;
                        co.cond_results.push_back(FGLSLConditionalResult(cond[i].name, true));
                        c.push_back(co);
                        Combination co2;
                        co2.cond_results.push_back(FGLSLConditionalResult(cond[i].name, false));
                        c.push_back(co2);
                        return c;
                    }
                }
                else {
                    auto cc = std::vector<Combination>();
                    for (auto cur : c) {
                        Combination comb;
                        comb.Clone(cur);
                        if (cond[i].value == 0 || cond[i].value == 1) {
                            comb.cond_results.push_back(FGLSLConditionalResult(cond[i].name, false));
                            cc.push_back(comb);
                        }
                        if (cond[i].value == 2) {
                            comb.cond_results.push_back(FGLSLConditionalResult(cond[i].name, true));
                            cc.push_back(comb);
                        }
                        if (cond[i].value == 3) {
                            comb.cond_results.push_back(FGLSLConditionalResult(cond[i].name, true));
                            cc.push_back(comb);
                            Combination comb2;
                            comb2.Clone(cur);
                            comb2.cond_results.push_back(FGLSLConditionalResult(cond[i].name, false));
                            cc.push_back(comb2);
                        }
                    }
                    return cc;
                }
            }
            if (i >= tokens.size()) {
                auto c = std::vector<Combination>();
                return c;
            }
            if (i == tokens.size() - 1) {
                auto c = std::vector<Combination>();
                for (auto v : tokens[i].values) {
                    Combination co;
                    co.results.push_back(FGSLTokenResult(tokens[i].name, v, tokens[i].line));
                    c.push_back(co);
                }
                return c;
            }
            else {
                auto c = GetCombinations(i + 1, tokens, cond, false);
                if (c.empty()) {
                    for (auto v : tokens[i].values) {
                        Combination co;
                        co.results.push_back(FGSLTokenResult(tokens[i].name, v, tokens[i].line));
                        c.push_back(co);
                    }
                    return c;
                }
                else {
                    if (tokens[i].values.empty()) {
                        return c;
                    }
                    auto cc = std::vector<Combination>();
                    for (auto cur : c) {
                        for (auto v : tokens[i].values) {
                            Combination comb;
                            comb.Clone(cur);
                            comb.results.push_back(FGSLTokenResult(tokens[i].name, v, tokens[i].line));
                            cc.push_back(comb);
                        }
                    }
                    return cc;
                }
            }
        }

        struct GLSLTokenSetting {
            std::string value;
            std::string name;

            GLSLTokenSetting(std::string name, std::string value) : name(name), value(value) {}
        };

        struct GLSLShaders {
            std::vector<GLSLShader> shaders = std::vector<GLSLShader>();
            std::vector<GLSLTokenSetting> settings = std::vector<GLSLTokenSetting>();
            std::vector<FGLSLConditionalResult> conditional_settings = std::vector<FGLSLConditionalResult>();

            void SetShaderID(int index, int id) {
                shaders[index].programID = id;
            }

            void SetValue(std::string name, std::string value) {
                bool found = false;
                for (auto& s : settings) {
                    if (s.name == name) {
                        s.value = value;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    settings.push_back(GLSLTokenSetting(name, value));
            }
            void SetCondition(std::string name, bool value) {
                bool found = false;
                for (auto& s : conditional_settings) {
                    if (s.name == name) {
                        s.active = value;
                        found = true;
                        break;
                    }
                }
                if (!found)
                    conditional_settings.push_back(FGLSLConditionalResult(name, value));
            }

            GLSLShader* GetShader() {
                for (auto& s : shaders) {
                    bool foundS = true;
                    auto foundNames = std::vector<std::string>();
                    for (auto c : s.settings) {
                        bool found = false;
                        for (auto setting : settings) {
                            if (c.name == setting.name) {
                                foundNames.push_back(c.name);
                                if (c.value == setting.value && foundS) {
                                    found = true;
                                    break;
                                }
                            }
                        }
                        if (!found) {
                            foundS = false;
                        }
                    }

                    if (foundS) {
                        /*for (auto setting : settings) {
                            bool found = false;
                            for (auto name : foundNames) {
                                if (setting.name == name) {
                                    found = true;
                                    break;
                                }
                            }
                            if (!found) {
                                foundS = false;
                            }
                        }*/
                    }

                    if (foundS) {
                        foundNames = std::vector<std::string>();
                        bool found = true;
                        for (auto c : s.conditions) {
                            bool foundP = false;
                            bool foundN = false;
                            for (auto setting : conditional_settings) {
                                if (c.name == setting.name) {
                                    foundNames.push_back(c.name);
                                    foundN = true;
                                    if (c.active == setting.active && found) {
                                        foundP = true;
                                        break;
                                    }
                                }
                            }
                            if (!foundP) {
                                if (c.active || foundN)
                                    found = false;
                            }

                        }
                        if (found) {
                            for (auto condition : s.conditions) {
                                bool foundC = false;
                                for (auto name : foundNames) {
                                    if (condition.name == name) {
                                        foundC = true;
                                        break;
                                    }
                                }
                                if (!foundC && condition.active) {
                                    found = false;
                                }
                            }
                        }

                        if (found)
                            return &s;
                    }


                }
                return NULL;
            }
        };

    };

    // Takes the path to the entry shader.
    Internal::FGLSLShader LoadFGLSL(std::filesystem::path entry, PreprocessFlags flags = PreprocessFlags::NONE) {
        using namespace Internal;
        if (!(flags & PreprocessFlags::ABSOLUTE_PATH)) {
            entry = std::filesystem::current_path().append(entry.string());
        }

        // Code with resolved includes
        auto code = Resolve(ReadShader(entry), entry.parent_path());
        auto result = std::vector<std::string>();
        auto tokens = std::vector<FGSLToken>();
        auto conditionals = std::vector<FGLSLConditional>();
        auto open = std::vector<int>();
        for (int i = 0; i < code.size(); i++) {
            auto l = code[i];
            _trim(l);
            if (l._Starts_with("//$")) {
                l.erase(0, 3);

                std::string token = l.substr(0, l.find(" "));
                if (token == "DEFINE") {
                    std::string right_hand = l.substr(l.find(" ") + 1);
                    std::string identifier = right_hand.substr(0, right_hand.find(" "));
                    std::string value = right_hand.substr(right_hand.find(" ") + 1);
                    if (value[0] == '$') {
                        value.erase(0, 1);
                        tokens.push_back(FGSLToken(i, value));
                        result.push_back("#define " + identifier + " $" + value);
                    }
                    else {
                        result.push_back("#" + l);
                    }
                }
                else if (token == "IF") {
                    std::string right_hand = l.substr(l.find(" ") + 1);
                    bool found = false;
                    for (int j = 0; j < conditionals.size(); j++) {
                        if (conditionals[j].name == right_hand) {
                            conditionals[j].ranges.push_back(Range(i, -1, 0));
                            open.push_back(j);
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        auto f = FGLSLConditional(right_hand);
                        f.ranges.push_back(Range(i, -1, 0));
                        conditionals.push_back(f);
                        open.push_back(conditionals.size() - 1);
                    }
                    result.push_back("");
                }
                else if (token == "ELSE") {
                    auto cur = open[open.size() - 1];
                    conditionals[cur].ranges[conditionals[cur].ranges.size() - 1].else_p = i;
                    result.push_back("");
                }
                else if (token == "END_IF") {
                    auto cur = open[open.size() - 1];
                    open.pop_back();
                    conditionals[cur].ranges[conditionals[cur].ranges.size() - 1].end = i;
                    result.push_back("");
                }
                else {
                    result.push_back(l);
                }
            }
            else {
                result.push_back(code[i]);
            }
        }

        Internal::FGLSLShader sh;
        sh.content = result;
        sh.tokens = tokens;
        sh.conditional = conditionals;
        return sh;
    }

    Internal::GLSLShaders GenerateShaders(Internal::FGLSLShader sh) {
        using namespace Internal;

        auto shaders = GLSLShaders();
        auto combinations = GetCombinations(0, sh.tokens, sh.conditional);

        if (sh.conditional.size() == 0 && sh.tokens.size() == 0 && combinations.size() == 0)
        {
            GLSLShader sha;

            std::string result = "";
            for (int i = 0; i < sh.content.size(); i++) {
                result += sh.content[i] + "\n";
            }
            sha.code = result;
            shaders.shaders.push_back(sha);
        }

        bool all_present = true;
        for (auto a : sh.tokens) {
            bool present = false;
            for (auto c : combinations) {
                for (auto r : c.results) {
                    if (r.name == a.name)
                    {
                        present = true;
                        break;
                    }
                }
                if (present)
                    break;
            }
            if (!present) {
                all_present = false;
                break;
            }
        }

        if (!all_present) {
            std::cout << "Warning: FGLSL: Could not generate valid Combination. Did you set values for all defined constants in your shader? Make sure all defines from all sub-shaders are set aswell!" << std::endl;

            return shaders;
        }

        for (auto c : combinations) {
            std::string result = "";
            for (int i = 0; i < sh.content.size(); i++) {
                bool disabled = false;
                for (auto cond : c.cond_results) {
                    for (auto fullCond : sh.conditional) {
                        if (fullCond.name == cond.name) {
                            for (auto range : fullCond.ranges) {
                                if (range.start <= i && range.end >= i) {
                                    if (cond.active && range.else_p != -1 && range.else_p <= i) {
                                        disabled = true;
                                    }
                                    if (!cond.active && (range.else_p >= i || range.else_p == -1)) {
                                        disabled = true;
                                    }
                                    break;
                                }
                            }
                            if (disabled)
                                break;
                        }
                    }
                    if (disabled)
                        break;
                }

                if (disabled)
                    continue;

                auto l = sh.content[i];
                bool found = false;
                for (auto cc : c.results) {
                    if (cc.line == i) {
                        found = true;
                        auto token = l.find("$" + cc.name);
                        result += l.substr(0, token) + cc.value + l.substr(token + cc.name.length() + 1) + "\n";
                        break;
                    }
                }
                if (!found) {
                    result += l + "\n";
                }
            }
            GLSLShader sh;
            sh.code = result;
            for (auto cc : c.results) {
                sh.settings.push_back(FGSLTokenResult(cc.name, cc.value, cc.line));
            }
            for (auto cc : c.cond_results) {
                sh.conditions.push_back(FGLSLConditionalResult(cc.name, cc.active));
            }
            shaders.shaders.push_back(sh);
        }

        return shaders;
    }



    inline PreprocessFlags operator|(PreprocessFlags a, PreprocessFlags b)
    {
        return static_cast<PreprocessFlags>(static_cast<int>(a) | static_cast<int>(b));
    }
    PreprocessFlags operator&(PreprocessFlags lhs, PreprocessFlags rhs) {
        return static_cast<PreprocessFlags>(static_cast<std::underlying_type_t<PreprocessFlags>>(lhs) & static_cast<std::underlying_type_t<PreprocessFlags>>(rhs));
    }
}