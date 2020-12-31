#include "kek.h"
#include <stdio.h>

KEKReturn kek_user_enter(int argc, char **argv)
{
    printf("user enter\n");

    kek_window_open("Example", 1920, 1080);

    kek_window_set_title("Example1");
    kek_window_set_size(1280, 720);

    return KEK_OK;
}

KEKReturn kek_user_update(void)
{
    return KEK_OK;
}

KEKReturn kek_user_exit(void)
{
    return KEK_OK;
}

