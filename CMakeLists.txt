cmake_minimum_required(VERSION 3.22)
project(shared_memory_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(EXEC_NAME shm_mut.out)

#set up the dslib folder
add_subdirectory(dslib)

add_executable(${EXEC_NAME} main.cpp)

add_executable(producer.out producer.cpp
        anonymous_semaphore.h)

add_executable(consumer.out consumer.cpp
        anonymous_semaphore.h)

# set up the Boost library root folder
if (DEFINED $ENV{ROOT_BOOST})
    set(ROOT_BOOST $ENV{ROOT_BOOST})
else()
    set(ROOT_BOOST "/home/dev/Projects/boost_1_85_0")
endif()

message(STATUS "Caminho da biblioteca BOOST configurado para: ${ROOT_BOOST}")
target_include_directories(${EXEC_NAME} PUBLIC ${ROOT_BOOST})
target_include_directories(producer.out PUBLIC ${ROOT_BOOST})
target_include_directories(consumer.out PUBLIC ${ROOT_BOOST})


