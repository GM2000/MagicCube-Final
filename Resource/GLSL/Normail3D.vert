#version 330 core  

uniform mat4 Frustum;
uniform mat4 Translate;
uniform mat4 Rotate;

out vec3 FColor;

layout(location = 0) in  vec4 in_position;

void  main()  
{  
	FColor=vec3(0.0,1.0,0.0);
	gl_Position = in_position * Rotate * Translate * Frustum;  
}  