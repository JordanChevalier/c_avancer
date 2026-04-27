cmake_minimum_required(VERSION 3.10)

project(TheaterProject C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(TheaterProject
    main.c
    src/theater.c
)

target_include_directories(TheaterProject PRIVATE src)
target_link_libraries(TheaterProject PRIVATE m)
