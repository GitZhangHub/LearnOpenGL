#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <learnopengl/shader_s.h>
#include <iostream>
#include <cmath>
extern void processInput(GLFWwindow *window);
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//namespace  ShadersSpace {
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;





int shaders()
{

    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    //build and compile our shader program
    Shader ourShader("../../../../data/shaders/03shader.vs","/Users/apple/workspace/LearnOpenGL/data/shaders/03shader.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes

    float vertices[] = {
        // 位置              // 颜色
         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
    };


    unsigned int VAO, VBO;//顶点数组对象、顶点缓冲区、索引缓冲区（又称IBO)

    //生成 并 绑定 顶点数组对象
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);

    //使用glGenBuffers函数和一个缓冲ID生成一个VBO对象
    //OpenGL允许我们同时绑定多个缓冲，只要它们是不同的缓冲类型。
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);

    /*把之前定义的顶点数据复制到缓冲的内存
     * args:1目标缓冲的类型，2数据大小（单位：字节），3数据源，4我们希望显卡管理给定数据的方式
     * GL_STATIC_DRAW ：数据不会或几乎不会改变。
     * GL_DYNAMIC_DRAW：数据会被改变很多。
     * GL_STREAM_DRAW ：数据每次绘制时都会改变。
     */
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    //位置属性
    //参数说明:location ,属性个数,属性类型，，步长（一组数据长度），偏移量（在本组数据中的偏移量）
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);

    //颜色属性
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6 *sizeof(float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);


    //    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);


    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // 清除颜色缓冲
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //激活着色器
        ourShader.use();



        //更新uniform 颜色
        float timeValue =glfwGetTime();//获取运行秒数
        float greenValue = sin(timeValue/2.0f +0.5f);//使颜色在0.0-1 之间
        int vertexColorLocation=glGetUniformLocation(ourShader.ID,"setColor");//查询uniform ourColor 的位置
        glUniform4f(vertexColorLocation,0.0f,greenValue,0.0f,0.5f);//设置uniform 值



        //绘制三角形
        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
        glDrawArrays(GL_TRIANGLES, 0, 3);
        // glBindVertexArray(0); // no need to unbind it every time

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;





}

//} //namespace
