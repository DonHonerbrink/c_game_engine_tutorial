#include "kek.h"
#include "kek_private.h"
#include "pal.h"
#include <stdio.h>

static KEKReturn kek_init(int argc, char **argv);
static KEKReturn kek_run(void);
static KEKReturn kek_terminate(void);
static void kek_print_screen_size(void);

extern KEKReturn kek_user_enter(int argc, char **argv);
extern KEKReturn kek_user_update(void);
extern KEKReturn kek_user_exit(void);

void pal_main(int argc, char **argv)
{
    
    kek_init(argc, argv);
    kek_run();
    kek_terminate();
}

static KEKReturn kek_init(int argc, char **argv)
{
    PALReturn pal_ret;

    printf("initializing...\n");

    kek_window_init();

    return kek_user_enter(argc, argv);
}

static KEKReturn kek_run(void)
{
    printf("running...\n");

    for(;;)
    {
        kek_window_poll();

        kek_user_update();

        kek_window_swap_buffers();
    }

    return KEK_OK;
}

static KEKReturn kek_terminate(void)
{
    printf("exiting...\n");
    
    return kek_user_exit();
}
    
