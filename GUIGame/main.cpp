//
//  main.cpp
//  GUIGame
//
//  Created by max dietz on 9/16/16.
//  Copyright © 2016 PGD. All rights reserved.
//

#include <iostream>

#include <GL/glew.h>
#include <glfw3.h>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif


//#version 330 

//layout (location = 0) in vec3 position;

void key_callback(GLFWwindow* window, int key, int scancode, int action , int mode);

int main(int argc, const char* argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
//    GLFWwindow
    GLFWwindow* window = glfwCreateWindow(800, 600, "BlackJack", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        std::cout << "Failed to initalize GLEW" << std::endl;
        return -1;
    }
    
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);
    
    glViewport(0, 0, width, height);
    
    
    // callback function for keypress
    glfwSetKeyCallback(window, key_callback);
    
    
    
    // Rendering a Triangle for now. Can switch out later.
    // draw a triangle vertices here for now.
    GLfloat vertices[] =
    {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };
    
    // Generate a Vertex Array Object (VAO)
    GLuint VAO;
    glGenVertexArrays(1, &VAO);

    //  As soon as we want to draw an object,
    // - we simply bind the VAO with the prefered settings
    // - before drawing the object and that is it.
glBindVertexArray(VAO);
    
    // Generate unique ID for vertex obj.
    GLuint VBO;
    glGenBuffers(1,&VBO);
    
    // bind the vertex buffer object using GL_ARRAY_BUFFER
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    // copy the previously defined vertex data into the buffer's memory
    //GL_STATIC_DRAW: the data will most likely not change at all or very rarely.
    //GL_DYNAMIC_DRAW: the data is likely to change a lot.
    //GL_STREAM_DRAW: the data will change every time it is drawn.
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    /*
     
     As of now we stored the vertex data within memory on the graphics card as managed by a vertex buffer object named VBO. Next we want to create a vertex and fragment shader that actually processes this data, so let's start building those.
    */
    
    // Vertex Shader
    const GLchar* vertex_shader =
    "#version 330 core\n"
    
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\n";
    
    // create a shader object
    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    
    // attach the shader source code to the shader object and compile the shader:
    glShaderSource(vertexShader, 1, &vertex_shader, NULL);
    glCompileShader(vertexShader);
    
    
    // check for compile time errors
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    
    // infolog should store error message if we get one, by using glGetShaderiv to check,
    // - glGetShaderInfoLog will retrieve error and message
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    // If no errors were detected while compiling the vertex shader it is now compiled.
    
    // Fragment Shader for color output
    const GLchar* fragment_shader =
    "#version 330 core\n"
    
    "out vec4 color;\n"
    
    "void main()\n"
    "{\n"
    "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n";
    
    // compiling fragment shader
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
    glCompileShader(fragmentShader);
    
    // Shader program to link the vertex and fragment shaders
    GLuint shaderProgram;
    shaderProgram = glCreateProgram(); // returns ID: reference to newly created program
    
    // Attach previously complied shaders and link them
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    // Error checking to see if linking the program failed.
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    }
    
    // Can delete shader objects since we already linked them info the program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    // We need to tell OpenGL how it should interpret the vertex data using attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);
// Unbind the Vertex Array Object (VAO);
glBindVertexArray(0);

    

    // Draw Square Code
    GLfloat verticesSquare[] =
    {
        0.5f,  0.5f, 0.0f, // top right
        0.5f, -0.5f, 0.0f, // bottom right
       -0.5f, -0.5f, 0.0f // bottom left
       -0.5f,  0.5f, 0.0f  // top left
    };
    
    GLuint indicesSquare[] =
    {
        0, 1, 3, // we start from 0
        1, 2, 3
    };
    
    glGenVertexArrays(1, &VAO);
    // Create element buffer object for our square
    GLuint EBO;
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesSquare), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesSquare), indicesSquare, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (GLvoid*)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    
glBindVertexArray(0);
    
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
    // Program loop
    while(!glfwWindowShouldClose(window))
    {
        // Check and call events.
        glfwPollEvents();
        
        // Rendering commands here
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // Drawing Code
        // activate the program object
        // - every shader and rendering call after this will now use this program object and shaders.
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
        
        // Swap the buffers
        glfwSwapBuffers(window);
    }
    // properly deallocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    
    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // When a user presses the space key, we set the window should close property to true,
    // closing the application
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


