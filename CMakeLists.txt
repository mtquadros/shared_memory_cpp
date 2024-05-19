cmake_minimum_required(VERSION 3.22)
project(shared_memory_cpp)

set(CMAKE_CXX_STANDARD 20)

#add_subdirectory(lib)

add_executable(shmm.out main.cpp)
add_executable(buf.out main2.cpp)

# configura o caminho para a biblioteca BOOST
if (DEFINED $ENV{ROOT_BOOST})
    set(ROOT_BOOST $ENV{ROOT_BOOST})
else()
    set(ROOT_BOOST "/home/dev/Projects/boost_1_85_0")
endif()

message(STATUS "Caminho da biblioteca BOOST configurado para: ${ROOT_BOOST}")

target_include_directories(shmm.out PUBLIC ${ROOT_BOOST})
target_include_directories(buf.out PUBLIC ${ROOT_BOOST})
#target_link_libraries(shmm.out PUBLIC GroupCommLib)

