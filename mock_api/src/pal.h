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
typedef void (*PALKeyboardFunc)(void);
typedef void (*PALMouseButtonFunc)(void);
typedef void (*PALMousePositionFunc)(void);
typedef void (*PALMouseScrollFunc)(void);
typedef void (*PALGamepadFunc)(void);
typedef void (*PALThread)(void);
typedef void (*PALCharFunc)(void);
typedef void (*PALFileChangeFunc)(void);
typedef void (*PALThreadFunc)(void);

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
PALReturn pal_window_set_keyboard_callback(PALWindow *window, PALKeyboardFunc fn, void *context);
PALReturn pal_window_set_gamepad_callback(PALWindow *window, PALGamepadFunc fn, void *context);
PALReturn pal_window_set_mouse_button_callback(PALWindow *window, PALMouseButtonFunc fn, void *context);
PALReturn pal_window_set_mouse_position_callback(PALWindow *window, PALMousePositionFunc fn, void *context);
PALReturn pal_window_set_mouse_scroll_callback(PALWindow *window, PALMouseScrollFunc fn, void *context);
PALReturn pal_window_set_char_callback(PALWindow *window, PALCharFunc fn, void *context);

// Time
PALReturn pal_time_get_live(float *time);

// File management
PALReturn pal_file_to_buffer(const char *file, uint8_t *buffer, size_t *size_bytes, int capacity);
PALReturn pal_file_add_change_callback(PALFileChange *listener, const char *path, PALFileChangeFunc fn, void *context);
PALReturn pal_file_check_changes(PALFileChange *listener);
PALReturn pal_file_get_size(const char *file);

// Threading
PALReturn pal_thread_init(PALThread *thread, PALThreadFunc fn, void *context);
PALReturn pal_thread_start(PALThread *thread);
PALReturn pal_thread_join(PALThread *thread);

// TCP
PALReturn pal_tcp_socket_init(PALTCPSocket *sock);
PALReturn pal_tcp_socket_terminate(PALTCPSocket *sock);
PALReturn pal_tcp_server_start(PALTCPSocket *sock, uint16_t port);
PALReturn pal_tcp_server_accept(PALTCPSocket *sock, uint16_t port, PALTCPSocket *client);
PALReturn pal_tcp_client_connect(PALTCPSocket *sock, const char *server, uint16_t port);
PALReturn pal_tcp_send(PALTCPSocket *sock, const uint8_t *buffer, size_t size);
PALReturn pal_tcp_receive(PALTCPSocket *sock, uint8_t *buffer, size_t *size, size_t capacity);
PALReturn pal_tcp_receive_wait(PALTCPSocket *sock, uint8_t *buffer, size_t *size, size_t capacity, uint16_t timeout_ms);

// UDP
PALReturn pal_udp_init(PALUDPSocket *sock);
PALReturn pal_udp_terminate(PALUDPSocket *sock, uint16_t port);
PALReturn pal_udp_bind(PALUDPSocket *sock, uint16_t port);
PALReturn pal_udp_send(PALUDPSocket *sock, uint32_t ip, uint16_t port, uint8_t *payload, size_t size);
PALReturn pal_udp_receive(PALUDPSocket *sock, uint8_t *buffer, size_t capacity, size_t *size, uint32_t *ip, uint32_t *port);



