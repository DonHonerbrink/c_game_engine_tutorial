#include "kek.h"
#include <stdio.h>

extern void kek_user_init(int argc, char **argv);
extern void kek_user_terminate(void);

int main(int argc, char **argv)
{
    // init engine here
    printf("initializing...\n");
    kek_user_init(argc, argv);
    
    printf("running...\n");
    // run game loop here
    
    printf("exiting...\n");
    kek_user_terminate();
}

