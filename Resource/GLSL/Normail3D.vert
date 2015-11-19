#version 330 core  

uniform mat4 Frustum;
uniform vec3 Color;
out vec3 FColor;

layout(location = 0) in  vec4 in_position;

void  main()  
{  
	FColor=Color;
	gl_Position = in_position * Frustum;  
}  