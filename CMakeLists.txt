cmake_minimum_required(VERSION 3.22)
project(shared_memory_cpp)

set(CMAKE_CXX_STANDARD 20)
set(EXEC_NAME shm_mut.out)
#set up the lib folder
#add_subdirectory(lib)

add_executable(${EXEC_NAME} main.cpp)

# set up the Boost library root folder
if (DEFINED $ENV{ROOT_BOOST})
    set(ROOT_BOOST $ENV{ROOT_BOOST})
else()
    set(ROOT_BOOST "/home/dev/Projects/boost_1_85_0")
endif()

message(STATUS "Caminho da biblioteca BOOST configurado para: ${ROOT_BOOST}")
target_include_directories(${EXEC_NAME} PUBLIC ${ROOT_BOOST})

# Add the library to shared memory executable compilation
#target_link_libraries(${EXEC_NAME} PUBLIC IPCLib)

