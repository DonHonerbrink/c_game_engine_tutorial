cmake_minimum_required(VERSION 3.4.1)

project(pj)

message("Generating for system " ${CMAKE_SYSTEM_NAME})
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Werror -Wsign-compare -O3")
if(!MSVC)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wsign-compare -O3")
endif()

set(GLFW_BUILD_SHARED_LIBS OFF)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
set(GLFW_VULKAN_STATIC OFF)

#3rd party files
add_subdirectory(deps/glfw)
add_library(glad STATIC deps/glfw/deps/glad_gl.c)

# includes 
set(KEK_INCLUDE ${KEK_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(KEK_INCLUDE ${KEK_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR}/deps) 
set(KEK_INCLUDE ${KEK_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR}/deps/glfw/include)
set(KEK_INCLUDE ${KEK_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR}/deps/glfw/deps)
set(KEK_INCLUDE ${KEK_INCLUDE} ${CMAKE_CURRENT_SOURCE_DIR}/deps/glfw/deps/glad)

include_directories(${KEK_INCLUDE})


#source files
file(GLOB KEK_SOURCE src/*.c)


set(KEK_LIBRARIES glad glfw)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(OS_LIBRARIES dl m pthread X11 GL glfw glad)
endif()


add_library(kek STATIC ${KEK_SOURCE})

#target_link_libraries(kek ${KEK_LIBRARIES} ${OS_LIBRARIES})
add_executable(game ${KEK_SOURCE})
target_link_libraries(game ${KEK_LIBRARYS} ${OS_LIBRARIES})

add_compile_definitions(PAL_WINDOW_USE_GLFW)


