#ifndef __OPENGL330API_H__
#define __OPENGL330API_H__

#include<GLFW/glfw3.h>

#include<vector>
#include<utility>
#include<unordered_map>
int helloWindow();

int triangle();
int triangle_with_EBO();
int shaders();
int textures();
bool translation();
int coordinateSystems();
int camera();

//check Endian
extern int bigOrLittle();
extern int bigOrLittle2();
int minPathSum(int (*array)[4],int row,int column);
int minPathSum2(int* pArray,int row,int column);






#endif//__OPENGL330API_H__



