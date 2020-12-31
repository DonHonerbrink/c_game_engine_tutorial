#if defined(PAL_WINDOW_USE_GLFW)
#include "pal_window_glfw.h"
#else
#error "UNDEFINED PRIVATE WINDOW API"
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef enum PALReturn PALReturn;
typedef struct PALFileChange PALFileChange;
typedef struct PALTCPSocket PALTCPSocket;
typedef struct PALUDPSocket PALUDPSocket;
typedef struct PALWindow PALWindow;

enum PALReturn {
    PAL_OK,
    PAL_ERROR,
    PAL_UNKNOWN,
    PAL_GLFW_INIT_ERROR,
    PAL_GLFW_WINDOW_CREATE_ERROR,
    PAL_GLFW_NOT_INITIALIZED_ERROR,
    PAL_WINDOW_SIZE_INVALID,
    PAL_BAD_PARAM,
    PAL_COMPILE_ERROR,
    PAL_LINK_ERROR,
    PAL_FILE_NOT_FOUND,
    PAL_PERMISSION_DENIED,
    PAL_NOT_INITIALIZED,
    //todo: add more return codes as necessary
};

struct PALWindow {
    PALWindowPrivate priv;
};

// Window Management
PALReturn pal_window_init(PALWindow *window);
PALReturn pal_window_is_open(PALWindow *window, bool *open);
PALReturn pal_window_open(PALWindow *window, const char *title, unsigned int width, unsigned int height);
PALReturn pal_window_terminate(PALWindow *window);
PALReturn pal_window_set_title(PALWindow *window, const char *title);
PALReturn pal_window_get_size(PALWindow *window, unsigned int *width, unsigned int *height);
PALReturn pal_window_set_size(PALWindow *window, unsigned int width, unsigned int height);
PALReturn pal_window_get_framebuffer_size(PALWindow *window, unsigned int *width, unsigned int *height);
PALReturn pal_window_poll(PALWindow *window);
PALReturn pal_window_swap_buffers(PALWindow *window);

