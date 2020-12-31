#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum KEKReturn KEKReturn;

enum KEKReturn {
    KEK_OK,
    KEK_BAD_PARAM,
    KEK_UNKNOWN_ERROR
};

