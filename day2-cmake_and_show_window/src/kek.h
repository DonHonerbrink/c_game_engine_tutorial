#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum KEKReturn KEKReturn;

enum KEKReturn {
    KEK_OK,
    KEK_ERROR,
    KEK_INIT_ERROR,
    KEK_BAD_PARAM,
    KEK_UNKNOWN_ERROR,
    KEK_NOT_IMPLEMENTED,
    KEK_WINDOW_OPEN_FAIL,
    KEK_WINDOW_ALREADY_OPEN,
    KEK_WINDOW_NOT_OPEN,
    KEK_WINDOW_SWAP_BUFFER_ERROR,
    KEK_WINDOW_POLL_ERROR,
    KEK_WINDOW_SET_SIZE_ERROR,
    KEK_WINDOW_GET_SIZE_ERROR,

};

//**********************************************************
// window 
//**********************************************************
KEKReturn kek_window_set_title(const char *title);
KEKReturn kek_window_set_size(unsigned int width, unsigned int height);
KEKReturn kek_window_get_size(unsigned int *width, unsigned int *height);
KEKReturn kek_window_open(const char *title, unsigned int width, unsigned int height);

