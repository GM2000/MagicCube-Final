#version 330 core  

uniform mat4 Frustum;
uniform mat4 Translate;
uniform mat4 Rotate;

out vec2 tx_position;

layout(location = 0) in  vec4 in_position;
layout(location = 1) in  vec2 in_ts_position;

void  main()  
{  
	tx_position = in_ts_position;
	gl_Position = in_position * Rotate * Translate * Frustum;  
}  