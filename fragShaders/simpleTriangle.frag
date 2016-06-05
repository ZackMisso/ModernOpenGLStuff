#version 410 core

//in VS_OUT
//{
//  vec4 color;
//} fs_in;

in vec4 tes_color;

out vec4 color;

void main(void) {
  color = tes_color;
}
