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
file(GLOB KEK_SOURCE src/kek*)
file(GLOB PAL_SOURCE src/pal*)
file(GLOB GAME_SOURCE src/game*)

#pal libraies
set(PAL_LIBRARIES glad glfw)

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(PAL_LIBRARIES ${PAL_LIBRARIES} dl m pthread X11 GL glfw glad)
endif()


#library declartions
add_library(kek_lib STATIC ${KEK_SOURCE})
add_library(pal_lib STATIC ${PAL_SOURCE})

#linking
target_link_libraries(pal_lib ${PAL_LIBRARIES})

add_executable(game ${GAME_SOURCE})
target_link_libraries(game kek_lib pal_lib kek_lib)

add_compile_definitions(PAL_WINDOW_USE_GLFW)


