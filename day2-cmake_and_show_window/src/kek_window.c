#include "kek.h"
#include "pal.h"
#include "kek_private.h"
#include <string.h>

#define MAX_TITLE_LEN 1024

static PALWindow window;

KEKReturn kek_window_init(void)
{
    PALReturn pal_ret;
    pal_ret = pal_window_init(&window);

    if(pal_ret != PAL_OK)
        return KEK_INIT_ERROR;

    return KEK_OK;
}

KEKReturn kek_window_set_title(const char *title)
{
    bool open = false;
    pal_window_is_open(&window, &open);
    
    if(!open)
        return KEK_WINDOW_NOT_OPEN;

    pal_window_set_title(&window, title);

    return KEK_OK;
}

KEKReturn kek_window_set_size(unsigned int width, unsigned int height)
{
    bool open = false;
    pal_window_is_open(&window, &open);
    
    if(!open)
        return KEK_WINDOW_NOT_OPEN;

    PALReturn pal_ret;

    pal_ret = pal_window_set_size(&window, width, height);

    if(pal_ret != PAL_OK)
        return KEK_WINDOW_SET_SIZE_ERROR;

    return KEK_OK;
}

KEKReturn kek_window_get_size(unsigned int *width, unsigned int *height)
{
    bool open = false;
    pal_window_is_open(&window, &open);
    
    if(!open)
        return KEK_WINDOW_NOT_OPEN;

    PALReturn pal_ret;

    pal_ret = pal_window_get_size(&window, width, height);

    if(pal_ret != PAL_OK)
        return KEK_WINDOW_GET_SIZE_ERROR;

    return KEK_OK;
}

KEKReturn kek_window_poll(void)
{
    bool open = false;
    pal_window_is_open(&window, &open);
    
    if(!open)
        return KEK_WINDOW_NOT_OPEN;

    PALReturn pal_ret;
    
    pal_ret = pal_window_poll(&window);

    if(pal_ret != PAL_OK)
        return KEK_WINDOW_POLL_ERROR;

    return KEK_OK;
}

KEKReturn kek_window_swap_buffers(void)
{
    bool open = false;
    pal_window_is_open(&window, &open);
    
    if(!open)
        return KEK_WINDOW_NOT_OPEN;

    PALReturn pal_ret;

    pal_ret = pal_window_swap_buffers(&window);

    if(pal_ret != PAL_OK)
        return KEK_WINDOW_SWAP_BUFFER_ERROR;

    return KEK_OK;
}

KEKReturn kek_window_open(const char *title, unsigned int width, unsigned int height)
{
    bool open = false;
    pal_window_is_open(&window, &open);
    
    if(open)
        return KEK_WINDOW_ALREADY_OPEN;

    PALReturn pal_ret;
    pal_ret = pal_window_open(&window, title, width, height);


    if(pal_ret != PAL_OK)
        return KEK_WINDOW_OPEN_FAIL;

    return KEK_OK;
}
