#include "../fglsl.h"
#include <cassert>
#include <iostream>
int main() {
    // SINGLE CONDITIONAL
    //{
    //    auto fglsl = FGLSL::LoadFGLSL("single_if.comp");

    //    fglsl.SetCondition("LIGHTS", true);
    //    auto shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 70);

    //    auto fshader = shaders.GetShader();
    //    assert(fshader == NULL);

    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 70);

    //    shaders.SetCondition("LIGHTSS", true);
    //    shaders.SetCondition("LIGHT", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 70);



    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 35);

    //    fshader = shaders.GetShader();
    //    assert(shaders.shaders.size() == 1);
    //    assert(fshader->code.length() == 35);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);

    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(shaders.shaders.size() == 1);
    //    assert(fshader->code.length() == 35);



    //    fglsl.ClearValues();
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 35);

    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 35);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);

    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 35);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("LIGHTS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.length() == 70);
    //    assert(shaders.shaders[1].code.length() == 35);

    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 35);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 70);

    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 35);
    //}
    //// MULTI CONDITIONAL

    //{
    //    auto fglsl = FGLSL::LoadFGLSL("multi_if.comp");
    //    auto shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 32);

    //    auto fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 32);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 32);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 32);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 32);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 32);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 32);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 84);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(shaders.shaders[0].code.length() == 84);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 84);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.length() == 84);
    //    assert(shaders.shaders[1].code.length() == 32);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 84);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(shaders.shaders[0].code.length() == 84);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 32);



    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", true);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 124);

    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 124);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 124);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", true);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.length() == 124);
    //    assert(shaders.shaders[1].code.length() == 32);


    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 32);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 124);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 124);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 32);



    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("MATERIALS", true);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 176);



    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 176);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", true);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.length() == 176);
    //    assert(shaders.shaders[1].code.length() == 124);



    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", true);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 4);
    //    assert(shaders.shaders[0].code.length() == 176);
    //    assert(shaders.shaders[1].code.length() == 124);
    //    assert(shaders.shaders[2].code.length() == 84);
    //    assert(shaders.shaders[3].code.length() == 32);



    //    fshader = shaders.GetShader();

    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 124);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 176);

    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 84);

    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 124);

    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 32);
    //}












    //// SINGLE CONDITIONAL IF_ELSE
    //{
    //    auto fglsl = FGLSL::LoadFGLSL("single_if_else.comp");

    //    fglsl.SetCondition("LIGHTS", true);
    //    auto shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 69);

    //    auto fshader = shaders.GetShader();
    //    assert(fshader == NULL);

    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 69);

    //    shaders.SetCondition("LIGHTSS", true);
    //    shaders.SetCondition("LIGHT", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 69);



    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 88);

    //    fshader = shaders.GetShader();
    //    assert(shaders.shaders.size() == 1);
    //    assert(fshader->code.length() == 88);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);

    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(shaders.shaders.size() == 1);
    //    assert(fshader->code.length() == 88);



    //    fglsl.ClearValues();
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 88);

    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 88);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);

    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 88);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("LIGHTS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.length() == 69);
    //    assert(shaders.shaders[1].code.length() == 88);

    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 88);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 69);

    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 88);
    //}
    //// MULTI CONDITIONAL

    //{
    //    auto fglsl = FGLSL::LoadFGLSL("multi_if_else.comp");
    //    auto shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 179);

    //    auto fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 179);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 179);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 179);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 179);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 179);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 179);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 159);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(shaders.shaders[0].code.length() == 159);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 159);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.length() == 159);
    //    assert(shaders.shaders[1].code.length() == 179);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 159);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(shaders.shaders[0].code.length() == 159);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 179);



    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", true);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 193);

    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 193);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 193);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", true);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.length() == 193);
    //    assert(shaders.shaders[1].code.length() == 179);


    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 179);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 193);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 193);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 179);



    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("MATERIALS", true);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 173);



    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 173);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);


    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", true);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.length() == 173);
    //    assert(shaders.shaders[1].code.length() == 193);



    //    fglsl.ClearValues();
    //    fglsl.SetCondition("LIGHTS", true);
    //    fglsl.SetCondition("LIGHTS", false);
    //    fglsl.SetCondition("MATERIALS", true);
    //    fglsl.SetCondition("MATERIALS", false);
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 4);
    //    assert(shaders.shaders[0].code.length() == 173);
    //    assert(shaders.shaders[1].code.length() == 193);
    //    assert(shaders.shaders[2].code.length() == 159);
    //    assert(shaders.shaders[3].code.length() == 179);



    //    fshader = shaders.GetShader();

    //    shaders.SetCondition("MATERIALS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 193);

    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 173);

    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", true);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 159);

    //    shaders.SetCondition("MATERIALS", true);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 193);

    //    shaders.SetCondition("MATERIALS", false);
    //    shaders.SetCondition("LIGHTS", false);
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 179);
    //}











    //{
    //    auto fglsl = FGLSL::LoadFGLSL("define.comp");
    //    fglsl.SetValue("TEST_COUNT", "20");
    //    auto shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 53);
    //    assert(shaders.shaders[0].code.find("#define TEST_COUNT 20") != std::string::npos);

    //    auto fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "11");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNTS", "20");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "20");
    //    fshader = shaders.GetShader();
    //    assert(fshader != NULL);
    //    assert(fshader->code.length() == 53);




    //    fglsl.ClearValues();
    //    fglsl.SetValue("TEST_COUNT", "200");
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 54);

    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "11");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNTS", "200");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "200");
    //    fshader = shaders.GetShader();
    //    assert(fshader != NULL);
    //    assert(fshader->code.length() == 54);




    //    fglsl.ClearValues();
    //    fglsl.SetValue("TEST_COUNT", "20");
    //    fglsl.SetValue("TEST_COUNT", "200");
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.length() == 53);
    //    assert(shaders.shaders[1].code.length() == 54);

    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "11");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNTS", "200");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "200");
    //    fshader = shaders.GetShader();
    //    assert(fshader != NULL);
    //    assert(fshader->code.length() == 54);
    //    shaders.SetValue("TEST_COUNT", "20");
    //    fshader = shaders.GetShader();
    //    assert(fshader != NULL);
    //    assert(fshader->code.length() == 53);



    //    fglsl.ClearValues();
    //    fglsl.SetValue("TEST_COUNT", "21");
    //    fglsl.SetValue("TEST_COUNT", "543");
    //    fglsl.SetValue("TEST_COUNT", "9876");
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 3);
    //    assert(shaders.shaders[0].code.length() == 53);
    //    assert(shaders.shaders[0].code.find("#define TEST_COUNT 21") != std::string::npos);
    //    assert(shaders.shaders[1].code.length() == 54);
    //    assert(shaders.shaders[1].code.find("#define TEST_COUNT 543") != std::string::npos);
    //    assert(shaders.shaders[2].code.length() == 55);
    //    assert(shaders.shaders[2].code.find("#define TEST_COUNT 9876") != std::string::npos);

    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "11");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNTS", "200");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "543");
    //    fshader = shaders.GetShader();
    //    assert(fshader != NULL);
    //    assert(fshader->code.length() == 54);
    //    shaders.SetValue("TEST_COUNT", "21");
    //    fshader = shaders.GetShader();
    //    assert(fshader != NULL);
    //    assert(fshader->code.length() == 53);
    //    shaders.SetValue("TEST_COUNT", "9876");
    //    fshader = shaders.GetShader();
    //    assert(fshader != NULL);
    //    assert(fshader->code.length() == 55);
    //}

    //{
    //    auto fglsl = FGLSL::LoadFGLSL("multi_define.comp");
    //    fglsl.SetValue("TEST_COUNT", "20");
    //    auto shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 0);

    //    auto fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "20");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "20");
    //    shaders.SetValue("MAT_COUNT", "20");
    //    shaders.SetValue("MOD_COUNT", "20");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);



    //    fglsl.ClearValues();
    //    fglsl.SetValue("TEST_COUNT", "20");
    //    fglsl.SetValue("MOD_COUNT", "30");
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 0);

    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "20");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("MOD_COUNT", "30");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);


    //    fglsl.ClearValues();
    //    fglsl.SetValue("TEST_COUNT", "20");
    //    fglsl.SetValue("MOD_COUNT", "30");
    //    fglsl.SetValue("MAT_COUNT", "40");
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.find("#define TEST_COUNT 20") != std::string::npos);
    //    assert(shaders.shaders[0].code.find("#define MOD_COUNT 30") != std::string::npos);
    //    assert(shaders.shaders[0].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[0].code.length() == 99);


    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "20");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("MOD_COUNT", "30");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("MAT_COUNT", "40");
    //    fshader = shaders.GetShader();
    //    assert(fshader != NULL);
    //    assert(fshader->code.length() == 99);
    //    shaders.SetValue("MOD_COUNT", "20");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);



    //    fglsl.ClearValues();
    //    fglsl.SetValue("TEST_COUNT", "20");
    //    fglsl.SetValue("TEST_COUNT", "21");
    //    fglsl.SetValue("MOD_COUNT", "30");
    //    fglsl.SetValue("MAT_COUNT", "40");
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 2);
    //    assert(shaders.shaders[0].code.find("#define TEST_COUNT 20") != std::string::npos);
    //    assert(shaders.shaders[1].code.find("#define TEST_COUNT 21") != std::string::npos);
    //    assert(shaders.shaders[0].code.find("#define MOD_COUNT 30") != std::string::npos);
    //    assert(shaders.shaders[1].code.find("#define MOD_COUNT 30") != std::string::npos);
    //    assert(shaders.shaders[0].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[1].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[0].code.length() == 99);


    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("TEST_COUNT", "20");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("MOD_COUNT", "30");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);
    //    shaders.SetValue("MAT_COUNT", "40");
    //    fshader = shaders.GetShader();
    //    assert(fshader != NULL);
    //    assert(fshader->code.length() == 99);
    //    shaders.SetValue("TEST_COUNT", "21");
    //    fshader = shaders.GetShader();
    //    assert(fshader->code.length() == 99);
    //    shaders.SetValue("TEST_COUNT", "22");
    //    fshader = shaders.GetShader();
    //    assert(fshader == NULL);

    //    fglsl.ClearValues();
    //    fglsl.SetValue("TEST_COUNT", "20");
    //    fglsl.SetValue("TEST_COUNT", "21");
    //    fglsl.SetValue("MOD_COUNT", "30");
    //    fglsl.SetValue("MOD_COUNT", "31");
    //    fglsl.SetValue("MAT_COUNT", "40");
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 4);
    //    assert(shaders.shaders[0].code.find("#define TEST_COUNT 20") != std::string::npos);
    //    assert(shaders.shaders[1].code.find("#define TEST_COUNT 21") != std::string::npos);
    //    assert(shaders.shaders[2].code.find("#define TEST_COUNT 20") != std::string::npos);
    //    assert(shaders.shaders[3].code.find("#define TEST_COUNT 21") != std::string::npos);
    //    assert(shaders.shaders[0].code.find("#define MOD_COUNT 30") != std::string::npos);
    //    assert(shaders.shaders[1].code.find("#define MOD_COUNT 30") != std::string::npos);
    //    assert(shaders.shaders[2].code.find("#define MOD_COUNT 31") != std::string::npos);
    //    assert(shaders.shaders[3].code.find("#define MOD_COUNT 31") != std::string::npos);
    //    assert(shaders.shaders[0].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[1].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[2].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[3].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[0].code.length() == 99);
    //    assert(shaders.shaders[1].code.length() == 99);
    //    assert(shaders.shaders[2].code.length() == 99);
    //    assert(shaders.shaders[3].code.length() == 99);



    //    fglsl.ClearValues();
    //    fglsl.SetValue("TEST_COUNT", "20");
    //    fglsl.SetValue("TEST_COUNT", "21");
    //    fglsl.SetValue("MOD_COUNT", "30");
    //    fglsl.SetValue("MOD_COUNT", "31");
    //    fglsl.SetValue("MAT_COUNT", "40");
    //    fglsl.SetValue("MAT_COUNT", "41");
    //    shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 8);
    //    assert(shaders.shaders[0].code.find("#define TEST_COUNT 20") != std::string::npos);
    //    assert(shaders.shaders[1].code.find("#define TEST_COUNT 21") != std::string::npos);
    //    assert(shaders.shaders[2].code.find("#define TEST_COUNT 20") != std::string::npos);
    //    assert(shaders.shaders[3].code.find("#define TEST_COUNT 21") != std::string::npos);
    //    assert(shaders.shaders[4].code.find("#define TEST_COUNT 20") != std::string::npos);
    //    assert(shaders.shaders[5].code.find("#define TEST_COUNT 21") != std::string::npos);
    //    assert(shaders.shaders[6].code.find("#define TEST_COUNT 20") != std::string::npos);
    //    assert(shaders.shaders[7].code.find("#define TEST_COUNT 21") != std::string::npos);
    //    assert(shaders.shaders[0].code.find("#define MOD_COUNT 30") != std::string::npos);
    //    assert(shaders.shaders[1].code.find("#define MOD_COUNT 30") != std::string::npos);
    //    assert(shaders.shaders[2].code.find("#define MOD_COUNT 30") != std::string::npos);
    //    assert(shaders.shaders[3].code.find("#define MOD_COUNT 30") != std::string::npos);
    //    assert(shaders.shaders[4].code.find("#define MOD_COUNT 31") != std::string::npos);
    //    assert(shaders.shaders[5].code.find("#define MOD_COUNT 31") != std::string::npos);
    //    assert(shaders.shaders[6].code.find("#define MOD_COUNT 31") != std::string::npos);
    //    assert(shaders.shaders[7].code.find("#define MOD_COUNT 31") != std::string::npos);
    //    assert(shaders.shaders[0].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[1].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[2].code.find("#define MATERIAL_COUNT 41") != std::string::npos);
    //    assert(shaders.shaders[3].code.find("#define MATERIAL_COUNT 41") != std::string::npos);
    //    assert(shaders.shaders[4].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[5].code.find("#define MATERIAL_COUNT 40") != std::string::npos);
    //    assert(shaders.shaders[6].code.find("#define MATERIAL_COUNT 41") != std::string::npos);
    //    assert(shaders.shaders[7].code.find("#define MATERIAL_COUNT 41") != std::string::npos);
    //    assert(shaders.shaders[0].code.length() == 99);
    //    assert(shaders.shaders[1].code.length() == 99);
    //    assert(shaders.shaders[2].code.length() == 99);
    //    assert(shaders.shaders[3].code.length() == 99);
    //    assert(shaders.shaders[4].code.length() == 99);
    //    assert(shaders.shaders[5].code.length() == 99);
    //    assert(shaders.shaders[6].code.length() == 99);
    //    assert(shaders.shaders[7].code.length() == 99);
    //}

    //{
    //    auto fglsl1 = FGLSL::LoadFGLSL(std::filesystem::current_path().append("include_test.comp"), FGLSL::PreprocessFlags::ABSOLUTE_PATH);
    //    auto fglsl = FGLSL::LoadFGLSL("include_test.comp");
    //    
    //    auto shaders1 = FGLSL::GenerateShaders(fglsl1);
    //    auto shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders1.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 63);
    //    assert(shaders.shaders[0].code == shaders1.shaders[0].code);
    //}

    //{
    //    auto fglsl = FGLSL::LoadFGLSL("multi_include_test.comp");
    //    auto shaders = FGLSL::GenerateShaders(fglsl);
    //    assert(shaders.shaders.size() == 1);
    //    assert(shaders.shaders[0].code.length() == 119);
    //}

    {
        auto fglsl = FGLSL::LoadFGLSL("if_define_include.comp");
        fglsl.SetValue("LIGHT_COUNT", "22");
        fglsl.SetCondition("LIGHTS", true);
        auto shaders = FGLSL::GenerateShaders(fglsl);
        assert(shaders.shaders.size() == 1);
        assert(shaders.shaders[0].code.length() == 125);

        fglsl.ClearValues();

        fglsl.SetValue("LIGHT_COUNT", "222");
        fglsl.SetCondition("LIGHTS", true);
        shaders = FGLSL::GenerateShaders(fglsl);
        assert(shaders.shaders.size() == 1);
        assert(shaders.shaders[0].code.length() == 126);

        fglsl.ClearValues();

        fglsl.SetValue("LIGHT_COUNT", "222");
        fglsl.SetCondition("LIGHTS", false);
        shaders = FGLSL::GenerateShaders(fglsl);
        assert(shaders.shaders.size() == 1);
        assert(shaders.shaders[0].code.length() == 145);

        fglsl.ClearValues();

        fglsl.SetValue("LIGHT_COUNT", "22");
        fglsl.SetCondition("LIGHTS", false);
        shaders = FGLSL::GenerateShaders(fglsl);
        assert(shaders.shaders.size() == 1);
        assert(shaders.shaders[0].code.length() == 145);
    }
}