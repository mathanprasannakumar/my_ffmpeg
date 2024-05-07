#include<iostream>
#include <GLFW/glfw3.h>


int main(int argc,char**argv)
{
   GLFWwindow* window;

   if(!glfwInit())
   {
    std::cout<<"Not able to initialize the glfw"<<std::endl;
    return 0;
   }

   window = glfwCreateWindow(640,480,"Helloworld",NULL,NULL);

   if(!window)
   {
    std::cout<<"Not able to create a window "<<std::endl;
    return 0;
    }

    unsigned char* data = new unsigned char[100*100*3];

    for(int y = 0;y<100;y++)
    {
        for(int x = 0;x<100;x++)
        {
           data[y*100*3+x*3] = 0xff;
           data[y*100*3+x*3+1] = 0x00;
           data[y*100*3+x*3+2] = 0x00;
        }
    }

    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window))    
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glDrawPixels(100,100,GL_RGB,GL_UNSIGNED_BYTE,data);
        // swapping the drawn buffer(back) to the front 
        glfwSwapBuffers(window);
        glfwWaitEvents();
    }

    return 0;
}