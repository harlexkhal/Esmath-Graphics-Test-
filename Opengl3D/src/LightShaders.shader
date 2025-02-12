#Shader Vertex

#version 330 core

layout(location = 0) in vec3 Position;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;

void main()
{
	gl_Position = Projection * View * Model * vec4(Position, 1.0f);

}

#Shader Fragment

#version 330 core
out vec4 FragColor;

void main()
{
	FragColor = vec4(1.0f);
}
