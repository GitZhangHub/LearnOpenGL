#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <learnopengl/shader_s.h>
#include <iostream>

#include <stb_image.h>

#include <iostream>
#include <glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>


extern void processInput(GLFWwindow *window);
extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;





bool translation()
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
    Shader ourShader("../../../../data/shaders/05transformations.vs",
                     "/Users/apple/workspace/LearnOpenGL/data/shaders/05transformations.fs");

    // set up vertex data (and buffer(s)) and configure vertex attributes

    float vertices[] = {
    //     ---- 位置 ----       - 纹理坐标 -
         0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // 右上
         0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // 左下
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f    // 左上
    };
    unsigned int indices[] = {
        0, 1, 3, // first triangle
        1, 2, 3  // second triangle
    };

    unsigned int VAO, VBO,EBO;//顶点数组对象、顶点缓冲区、索引缓冲区（又称IBO)
    glGenVertexArrays(1,&VAO);
    glGenBuffers(1,&VBO);
    glGenBuffers(1,&EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);


    //位置属性
    //参数说明:location ,属性个数,属性类型，，步长（一组数据长度），偏移量（在本组数据中的偏移量）
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)0);
    glEnableVertexAttribArray(0);


    //纹理属性
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);






    //创建纹理ID 并绑定
    unsigned int texture1;
    glGenTextures(1,&texture1);


    // all upcoming GL_TEXTURE_2D operations now have effect on this texture object
    glBindTexture(GL_TEXTURE_2D,texture1);

    //为当前绑定的纹理对象设置环绕、过滤方式
    //环绕模式：GL_REPEAT --对纹理的默认行为。重复纹理图像。
    //		  GL_MIRRORED_REPEAT --和GL_REPEAT一样，但每次重复图片是镜像放置的。
    //	GL_CLAMP_TO_EDGE --纹理坐标会被约束在0到1之间，超出的部分会重复纹理坐标的边缘，产生一种边缘被拉伸的效果。
    //	GL_CLAMP_TO_BORDER -- 超出的坐标为用户指定的边缘颜色。还需要指定一个边缘的颜色(glTexParameterfv函数)。
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);//2D 纹理，S轴方向环绕模式为GL_REPEAT
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

    //过滤方式： GL_NEAREST（也叫邻近过滤，Nearest Neighbor Filtering）是OpenGL默认的纹理过滤方式。
    // 		   GL_LINEAR（也叫线性过滤，(Bi)linear Filtering）
    //         它会基于纹理坐标附近的纹理像素，计算出一个插值，近似出这些纹理像素之间的颜色。
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);//2D纹理，缩小时的过滤方式
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);//放大时的过滤方式

    //读取图片数据
    int width ,height,nrChannels;
    // tell stb_image.h to flip loaded texture's on the y-axis. 反转Y轴
    stbi_set_flip_vertically_on_load(true);

    unsigned char* data= stbi_load("../../../../data/image/container.jpg",&width,&height,&nrChannels,0);

    if(data)
    {
        //生成纹理
        //args: 1指定纹理目标，2指定多级渐远的纹理级别，3纹理存储格式，，4纹理宽度，5纹理高度，6历史遗留设为0，
        //      7源图格式，8源图数据类型，9图片数据
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);

        //为当前绑定的纹理自动生成所需的多级渐远纹理
        glGenerateMipmap(GL_TEXTURE_2D);
    }else{
        std::cout<<"Failed to load texture."<<std::endl;
    }
    //释放图形内存
    stbi_image_free(data);



    //激活着色器
    ourShader.use();
    ourShader.setFloat("texture1",0);
//    glUniform1i(glGetUniformLocation(ourShader.ID,"texture1"),0);//手动设置

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

        //绑定前先激活纹理单元（0默认总是被激活,opengl 支持至少0-15 共16个纹理单元）
        // bind textures on corresponding texture units
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);


        //创建变形矩阵
        //下面就是矩阵初始化的一个例子，使用的是0.9.9及以上版本
        glm::mat4 trans(1.0f);//初始化单位矩阵

        //矩阵旋转  args: 1.被处理的矩阵 ， 2 旋转的弧度（glm::radians(90.0f)可将角度转化为弧度） ，3旋转轴
        trans =glm::rotate(trans,(float)glfwGetTime(),glm::vec3(0.0f,0.0f,1.0f));//构建旋转矩阵
        trans =glm::scale(trans,glm::vec3(0.5f,0.5f,0.5f));


        //get matrix's uniform location and set matrix
//        ourShader.use();
        unsigned int transformLoc = glGetUniformLocation(ourShader.ID, "transform");
        // 把矩阵传递给着色器
        //args:1 uniform 位置值， 2发送矩阵个数，3 是否对矩阵进行转置（GLM默认列主序），4 真正的矩阵数据（使用value_ptr把矩阵转化为OpenGL需要的格式）
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));



        //绘制四边形
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1,&EBO);

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return true;





}














