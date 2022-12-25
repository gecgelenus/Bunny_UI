#version 330 core

out vec4 FragColor;

in vec4 out_color;

void main(){
    FragColor = vec4(out_color);
}