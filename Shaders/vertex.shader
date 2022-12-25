#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec4 in_color;

out vec4 out_color;

void main(){
    gl_Position = vec4(position.x, position.y, position.z, 1.0);
    out_color = in_color;
}