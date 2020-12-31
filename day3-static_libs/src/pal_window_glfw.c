#include "pal.h"
#include "glad/gl.h"
#include "GLFW/glfw3.h"
#include <assert.h>
#include <stdio.h>

PALReturn pal_window_init(PALWindow *window)
{
    assert(window);

    window->priv.window = NULL;

    if(!glfwInit())
        return PAL_GLFW_INIT_ERROR;


}

PALReturn pal_window_open(PALWindow *window, const char *title, unsigned int width, unsigned int height)
{
    GLFWwindow *gw;

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_SAMPLES, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_DECORATED, GL_FALSE);

    gw = glfwCreateWindow(width, height, title, NULL, NULL);

    if(!gw)
    {
        glfwTerminate();
        return PAL_GLFW_WINDOW_CREATE_ERROR;
    }
    
    glfwMakeContextCurrent(gw);

    glfwSetWindowUserPointer(gw, window); 

    gladLoadGL((GLADloadfunc)glfwGetProcAddress);

    window->priv.window = gw;

    return PAL_OK;
}

PALReturn pal_window_is_open(PALWindow *window, bool *open)
{
    if(*open)
        *open = false;

    if(window == NULL || open == NULL)
        return PAL_BAD_PARAM;

    if(window->priv.window == NULL)
        return PAL_OK;

    *open = true;

    return PAL_OK;
}

PALReturn pal_window_terminate(PALWindow *window)
{
    assert(window);

    window->priv.window = NULL;

    glfwTerminate();

    return PAL_OK;
}

PALReturn pal_window_set_title(PALWindow *window, const char *title)
{
     glfwSetWindowTitle(window->priv.window, title);
}

PALReturn pal_window_set_size(PALWindow *window, unsigned int width, unsigned int height)
{
    int fbwidth;
    int fbheight; 
    int glfw_error;

    assert(window);
    assert(width);
    assert(height);

    if(!window->priv.window)
        return PAL_GLFW_NOT_INITIALIZED_ERROR;

    glfwSetWindowSize(window->priv.window, (int)width, (int)height);

    glfw_error = glfwGetError(NULL);

    if(glfw_error != GLFW_NO_ERROR)
        return PAL_ERROR;

    return PAL_OK;
}

PALReturn pal_window_get_size(PALWindow *window, unsigned int *width, unsigned int *height)
{
    int glfw_error;

    assert(window);
    assert(width);
    assert(height);

    if(!window->priv.window)
        return PAL_GLFW_NOT_INITIALIZED_ERROR;

    // todo: any reason as to why even cache the window width/height
    glfwGetWindowSize(window->priv.window, width, height);

    glfw_error = glfwGetError(NULL);

    if(glfw_error != GLFW_NO_ERROR)
        return PAL_ERROR;

    return PAL_OK;
}

PALReturn pal_window_get_framebuffer_size(PALWindow *window, unsigned int *width, unsigned int *height)
{
    int glfw_error;

    assert(window);
    assert(width);
    assert(height);

    if(!window->priv.window)
        return PAL_GLFW_NOT_INITIALIZED_ERROR;

    glfwGetFramebufferSize(window->priv.window, width, height);
    glfw_error = glfwGetError(NULL);

    if(glfw_error != GLFW_NO_ERROR)
        return PAL_ERROR;

    return PAL_OK;
}

PALReturn pal_window_poll(PALWindow *window)
{
    int glfw_error;

    glfwPollEvents();
    glfw_error = glfwGetError(NULL);

    if(glfw_error != GLFW_NO_ERROR)
        return PAL_ERROR;

    return PAL_OK;
}

PALReturn pal_window_swap_buffers(PALWindow *window)
{
    int glfw_error;

    glfwSwapBuffers(window->priv.window);

    if(glfw_error != GLFW_NO_ERROR)
        return PAL_ERROR;
    
    return PAL_OK;
}

