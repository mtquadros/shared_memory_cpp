//
// Created by dev on 03/06/24.
//

#ifndef _SHARED_MEM_BUFFER_H_
#define _SHARED_MEM_BUFFER_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <string>

namespace dscore
{
    struct shm_remove_on_create_and_destroy
    {
        std::string _shm_name;
        explicit shm_remove_on_create_and_destroy(const char *shm_name) : _shm_name(shm_name) { std::cout << "Removendo \n"; shared_memory_object::remove(_shm_name.c_str()); }
        ~shm_remove_on_create_and_destroy(){ std::cout << "Remover: Fim\n"; shared_memory_object::remove(_shm_name.c_str()); }
    } ;

    struct shm_remove_on_destroy
    {
        std::string _shm_name;
        explicit shm_remove_on_destroy(const char *shm_name) : _shm_name(shm_name) {};
        ~shm_remove_on_destroy(){ std::cout << "Remover: Fim\n"; shared_memory_object::remove(_shm_name.c_str()); }
    };

    struct shared_memory_buffer
    {
        enum { NumItems = 10 };

        shared_memory_buffer()
           : mutex(1), nempty(NumItems), nstored(0),items(0)
        {};

        //Semaphores to protect and synchronize access
        boost::interprocess::interprocess_semaphore
           mutex, nempty, nstored;

        //Items to fill
        int items[NumItems];
    };
};

#endif //_SHARED_MEM_BUFFER_H_
