//
// Created by dev on 03/06/24.
//

#ifndef DOC_ANONYMOUS_SEMAPHORE_SHARED_DATA_H
#define DOC_ANONYMOUS_SEMAPHORE_SHARED_DATA_H
#include <boost/interprocess/sync/interprocess_semaphore.hpp>

struct shared_memory_buffer
{
    enum { NumItems = 10 };

    shared_memory_buffer()
       : mutex(1), nempty(NumItems), nstored(0)
    {}

    //Semaphores to protect and synchronize access
    boost::interprocess::interprocess_semaphore
       mutex, nempty, nstored;

    //Items to fill
    int items[NumItems];
};


#endif //DOC_ANONYMOUS_SEMAPHORE_SHARED_DATA_H
