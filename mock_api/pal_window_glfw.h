#include "glad/gl.h"
#include "GLFW/glfw3.h"

typedef struct PALWindowPrivate PALWindowPrivate;

struct PALWindowPrivate
{
    GLFWwindow *window;
};
