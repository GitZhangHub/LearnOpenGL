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
namespace CHAPTER0_CAMERAMA {
int camera2();
};
namespace  CHAPTER1_LIGHT {
int light();
}
namespace CHAPTER3_GEOMETRYSHADER {
int ball();
}

int light();










#endif//__OPENGL330API_H__



