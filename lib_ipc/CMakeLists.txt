
add_library(lib_interprocess_comm)

target_include_directories(lib_interprocess_comm PUBLIC sharedmm/include)
target_include_directories(lib_interprocess_comm PUBLIC ${ROOT_BOOST})

target_sources(lib_interprocess_comm PUBLIC sharedmm/src/shared_mem_buffer.cpp)
target_sources(lib_interprocess_comm PUBLIC sharedmm/src/shared_memory_client.cpp)
target_sources(lib_interprocess_comm PUBLIC sharedmm/src/shared_memory_provider.cpp)

target_link_libraries(${PRODUCER} lib_interprocess_comm)
target_link_libraries(${CONSUMER} lib_interprocess_comm)
target_link_libraries(main.out lib_interprocess_comm)
