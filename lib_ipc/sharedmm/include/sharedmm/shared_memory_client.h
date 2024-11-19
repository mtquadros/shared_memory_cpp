//
// Created by dev on 28/09/24.
//

#ifndef SHARED_MEMORY_CLIENT_H
#define SHARED_MEMORY_CLIENT_H

#include <boost/interprocess/shared_memory_object.hpp>
#include <sharedmm/shared_mem_buffer.h>
#include <iostream>

using namespace boost::interprocess;

//! Manages automatic destruction of the shared memory when the leaves the scope where it is declared
class shared_memory_client
{
private:
    const char* _shm_name;

public:
    explicit shared_memory_client(const char *shm_name) : _shm_name(shm_name) {};
    ~shared_memory_client()
    {
        std::cout << "Remover: Fim\n";
        shared_memory_object::remove(_shm_name);
    }
};

#endif //SHARED_MEMORY_CLIENT_H
