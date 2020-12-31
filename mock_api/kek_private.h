#pragma once

// this should only be included by .c files
// within the kek engine
KEKReturn kek_window_init(void);
KEKReturn kek_window_poll(void);
KEKReturn kek_window_swap_buffers(void);
