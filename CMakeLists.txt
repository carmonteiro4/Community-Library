cmake_minimum_required(VERSION 3.26)
project(CSC-212-Project)

set(CMAKE_CXX_STANDARD 17)

include_directories("C:/Program Files/Graphviz/include")
link_directories("C:/Program Files/Graphviz/lib")

add_executable(CSC-212-Project main.cpp
        BookTree.cpp
        BookTree.h
        Book.cpp
        Book.h
)

target_link_libraries(CSC-212-Project gvc cgraph)