#version 330 core 

out vec4 fColor;
in vec2 tx_position;

uniform sampler2D tex;

void  main()  
{  
	fColor =texture2D(tex,tx_position); 
}  