#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

// texture samplers
uniform sampler2D texture1;//采样器
uniform sampler2D texture2;
  
void main()
{
//texture:采样纹理的颜色，它第一个参数是纹理采样器，第二个参数是对应的纹理坐标。
//mix: 输出（1-arg3)*纹理1 + arg3*纹理2 的混合颜色
	FragColor = mix(texture(texture1, TexCoord),texture(texture2,TexCoord),0.2);
}