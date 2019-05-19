#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

extern void processInput(GLFWwindow *window);
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);


int helloWindow()
{
    glfwInit();//初始化 GLFW

    //第一个参数代表选项的名称，我们可以从很多以GLFW_开头的枚举值中选择；第二个参数接受一个整形，用来设置这个选项的值。
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE);
#endif
    GLFWwindow* window = glfwCreateWindow(800 , 600,"LearnOpenGL",NULL,NULL);
    if(window == nullptr)
    {
        std::cout<<"Failed to  create GLFW window"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout<<"Failed to initialize GLAD"<<std::endl;
        return -1;
    }

    glViewport(100,100,700,500);//设置渲染窗口的纬度(Dimension)

    glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);


    //render Loop
    while(!glfwWindowShouldClose(window))
    {
        processInput(window); //输入esc 退出

        //渲染指令
        glClearColor(0.2f,0.3f,0.3f,1.0f);//状态设置函数
        glClear(GL_COLOR_BUFFER_BIT);//状态使用函数清空颜色缓冲区

        glfwSwapBuffers(window);//交换颜色缓冲区
        glfwPollEvents();//检查有没有触发事件
    }
    glfwTerminate();


    return 0;
}


