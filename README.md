# Funky GLSL

FGLSL is a single-header preprocessor for GLSL. It manages multiple shader versions of the same file, file merging, conditional code and dynamic constants. To conform to existing IDE highlighters, FGLSL instructions are written in comments. This also allows you to convert FGLSL shaders to pure GLSL with little effort and minimizes (often eliminates) turning your file red with errors and warnings.

```ad-note
FGLSL does not interact with OpenGL! It only provides operations on the raw source code. Compiling shaders has to be performed by the user. FGLSL provides a way to dynamically generate valid GLSL shaders.
```

## Documentation
FGLSL has preprocessor instructions that can be added to GLSL shaders. The C++ FGLSL implementation is separated into three distinct phases:
1. The path to a shader is passed to FGLSL. It will load the shader content, tokenize the preprocessor instructions and stich the files together if includes are present.
2. This step generates possible shaders. This can be done in one of two ways:
   - All possible scenarios are defined. This can, for example, include a shader version with and without lights and shader versions with 3, 4 or 5 game objects. These parameters are passed to FGLSL and all possible shader variants are generated (in this case: 3 versions with different number of game objects * 2 versions (with and without lighting) = 6 shader versions). This has the advantage of all shaders being ready once needed.
     All shader versions should be compiled and the OpenGL program ID saved for near instantaneous response times.
   - If the number of possible combinations is very high, or parameter combinations are unpredictable, this step can be performed once the shader is needed, not in advance. This might introduce lag while the shader is processed by FGLSL and compiled by OpenGL.
3. When multiple shaders were generated, the correct shader can be returned by the FGLSL shader data structure. With the example above, once it is known exactly which shader is needed, the shader struct would be set to the correct settings and FGLSL would return the correct shader. The struct could, for example, be set to having no lighting and 4 game objects and the correct shader for this configuration is returned.


## FGLSL Instructions

### Include
***Include*** allows separation of code.

```GLSL
// A.shader

struct Light{
	vec3 position;
	vec3 color;
};
```
```GLSL
// B.shader

//$INCLUDE A.shader
uniform Light lights[20];

...
```

### Define
***Define*** allows dynamic definition of constants.
```GLSL
//$DEFINE GLSL_VARIABLE $FGLSL_VARIABLE
//$DEFINE LIGHT_COUNT $LIGHT_COUNT
uniform Light lights[LIGHT_COUNT];
```

### If
***If*** allows for static branching and more dynamic code generation. 
```GLSL
//$IF LightsDetailed
struct Light{
	vec3 position;
	vec3 color;
	float falloff;
};
//$ELSE
struct Light{
	vec3 position;
	vec3 color;
};
//$END_IF

```
When Lights is not defined or set to false, everything between the IF and END_IF statement is removed from the shader.

### Example
Combining these instruction allows for very dynamic implementations.
```GLSL
// simple_light.shader

vec3 GetLightColor(Light l, vec3 normal, vec3 pt){
	return l.color;
}
```
```GLSL
// phong_light.shader
uniform float exposure;
uniform float falloff;

vec3 GetLightColor(Light l, vec3 normal, vec3 pt){
	vec3 dir = l.position - pt;
	
	float dist2 = dot(lightDir, lightDir);
	float dist = sqrt(dist2);
	lightDir = lightDir / dist;

	float inc = clamp(dot(ptNormal, lightDir), 0., 1.);
	float diff = inc * (1.0 / (4.0 * 3.141569 * dist2 * falloff))
	reutrn diff * exposure * l.color;
} 

```
```GLSL
// main.shader

//$IF Lights

//$DEFINE LIHGT_COUNT $LIGHT_COUNT
struct Light{
	vec3 position;
	vec3 color;
}
uniform Light lights[LIHGT_COUNT];

//$IF Phong
//$INCLUDE phong_light.shader
//$ELSE
//$INCLUDE simple_light.shader
//$END_IF

//$END_IF

void main(){
	vec4 color = vec4(0, 0, 0, 1);
	//$IF Lights
	for(int i = 0; i < LIGHT_COUNT; i++){
		color += GetLightColor(lights[i], normal, pt);
	}
	//$END_IF
	...
}

```


# C++ API
The API is relatively simple. The first step is to load, tokenize and combine the shader.
```C++
FGLSL::LoadFGLSL(std::filesystem::path path, PreprocessFlags flags)
```

Currently, flags only includes the ability to select whether and absolute or relative path was passed. Example:

```C++
auto fglsl = FGLSL::LoadFGLSL("cs.comp")
auto fglsl = FGLSL::LoadFGLSL("C://cs.comp", FGLSL::PreprocessFlags::ABSOLUTE_PATH)
```

Next, the FGLSL shader can be configured with all possible values. There are two functions for this:

```C++
fglsl.SetValue("SOME_DEFINED_CONSTANT", "1")
fglsl.SetValue("SOME_DEFINED_CONSTANT", "2")
fglsl.SetValue("SOME_DEFINED_CONSTANT", "3")
fglsl.SetCondition("SOME_IF_CONDITION", true)
fglsl.SetCondition("SOME_IF_CONDITION", false)
```

Once all parameters are configured, the GLSL shader code for all possible combinations can be generated (in the example above, this will generate 6 shader versions):

```C++
auto shaders = FGLSL::GenerateShaders(fglsl);
```

Once a specific shader is needed, it can be obtained by first defining the specific configuration:

```C++
shaders.SetValue("SOME_DEFINED_CONSTANT", "1")
shaders.SetCondition("SOME_IF_CONDITION", true)
```

And then calling:

```C++
auto shader = shaders.GetShader();
```

# Full Example

The example shaders are defined as:

```GLSL
//structs.comp

//$IF LIGHTS
struct PointLight{
	vec3 color;
	vec3 position;
	float falloff;
};
struct DirectionalLight{
	vec3 color;
	vec3 direction;
};
//$END_IF
```

```GLSL
//main.comp

#version 330

//$INCLUDE structs.comp

//$DEFINE POINT_LIGHT_COUNT $LIGHT_COUNT
//$DEFINE DIR_LIGHT_COUNT $LIGHT_COUNT

//$IF LIGHTS

uniform PointLight pls[POINT_LIGHT_COUNT];
uniform DirectionalLight dls[DIR_LIGHT_COUNT];

//$ELSE
uniform vec3 ambient;
//$END_IF

out vec4 color;

void main(){
	vec4 col = vec4(0, 0, 0, 1);
	
	//$IF lights
	for(int i = 0; i < POINT_LIGHT_COUNT; i++){
		...
	}
	...
    //$ELSE
    col += vec4(ambient.xyz, 0);
	//$END_IF

	color = col;
}


```

We want various versions of these shaders. We first load the main shader file:

```C++
auto fglsl = FGLSL::LoadFGLSL("main.comp");
```

Then we want to set all parameters:
```C++
fglsl.SetCondition("LIGHTS", true);
fglsl.SetCondition("LIGHTS", false);
```
This means, that we want both versions with and without lights for this shader.
```C++
fglsl.SetValue("LIGHT_COUNT", "3");
fglsl.SetValue("LIGHT_COUNT", "4");
fglsl.SetValue("LIGHT_COUNT", "5");
fglsl.SetValue("LIGHT_COUNT", "6");
fglsl.SetValue("LIGHT_COUNT", "7");
fglsl.SetValue("LIGHT_COUNT", "8");
fglsl.SetValue("LIGHT_COUNT", "9");
fglsl.SetValue("LIGHT_COUNT", "10");
```
This will generate the shader with all LIGHT_COUNT values from three to ten.

Now, that we have setup all parameters, we can generate all shaders:
```C++
auto shaders = FGLSL::GenerateShaders(fglsl);
```
If we want lag-free shader program switching, all these shaders should now be compiled.
```C++
for(int i = 0; i < shaders.shaders.size(); i++){
	// Your compile shader function
	int programID = CompileOpenGLShader(shaders.shaders[i]); 
	shaders.SetShaderID(i, programID);
}
```

Once a shader program is needed, it can be obtained by calling:
```C++
shaders.SetValue("LIGHT_COUNT", "4");
shaders.SetCondition("LIGHTS", true);
auto shader = shaders.GetShader();
int programID = shader.programID;
```



# TODO
- [ ] Recursive includes lead to stackoverflow.
- [ ] Smarter shader generation (currently, multiple shaders that are technically the same can be generated. For example if a define is in an if statement).