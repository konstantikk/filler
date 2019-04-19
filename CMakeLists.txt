cmake_minimum_required(VERSION 3.13)
project(filler C)

set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Wextra) # flags
include_directories(./libft) # directory with headers
FILE(GLOB LIBFT_SRCS ./libft/*.c)  # ADD LIBFT as sources
FILE(GLOB SRCS ./*.c)  # ADD LIBFT as sources

add_executable(filler ${LIBFT_SRCS} ${SRCS} find_optimal_place.c)