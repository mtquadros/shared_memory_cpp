cmake_minimum_required(VERSION 3.22)
project(shared_memory_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(PRODUCER producer.out)
set(CONSUMER consumer.out)
# set up the Boost library root folder
if (DEFINED $ENV{ROOT_BOOST})
    set(ROOT_BOOST $ENV{ROOT_BOOST})
else()
    set(ROOT_BOOST "/home/dev/Projects/boost_1_85_0")
endif()
message(STATUS "Caminho da biblioteca BOOST configurado para: ${ROOT_BOOST}")

add_executable(${PRODUCER} producer.cpp)

add_executable(${CONSUMER} consumer.cpp)

add_executable(main.out main.cpp)

# Add to the building the subdirectory of interprocess comunication (ipc) library
add_subdirectory(lib_ipc)

# Link the ipc library to the building targets
target_link_libraries(${PRODUCER} lib_interprocess_comm)
target_link_libraries(${CONSUMER} lib_interprocess_comm)

#set up the boost include directories
target_include_directories(main.out PUBLIC ${ROOT_BOOST})
target_include_directories(${PRODUCER} PUBLIC ${ROOT_BOOST} PUBLIC lib_ipc/sharedmm/include)
target_include_directories(${CONSUMER} PUBLIC ${ROOT_BOOST} PUBLIC lib_ipc/sharedmm/include)


