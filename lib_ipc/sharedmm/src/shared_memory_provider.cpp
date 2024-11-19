//
// Created by dev on 28/09/24.
//

#include <sharedmm/shared_memory_provider.h>
#include <iostream>
#include <string>

namespace sharedmm
{
    //! Constructor
    template<typename dataType, processNumber_t numProcesses, bufferSize_t bufferSize>
    shared_memory_provider<dataType, numProcesses, bufferSize>::shared_memory_provider(const char* name)
    {
        // Remove leak shared memory if it exists
        shared_memory_object::remove(name);

        // Create a shared memory object.
        shared_memory_object shm
           (create_only, name ,read_write);

        try
        {
            // Set size
            shm.truncate(sizeof(shared_memory_buffer<dataType,numProcesses,bufferSize>));
        }
        catch (const boost::interprocess::interprocess_exception& error)
        {
            // TODO: Implement Threatment of failure shared memory allocation
        }

        // Maps shared memory
        mapped_region region (shm,read_write);

        //Get the address of the mapped region
        _buffer = static_cast<shared_memory_buffer<dataType,numProcesses,bufferSize> *>(region.get_address());

        // If everything was done succefully saves
    };


    //! Destructor
    //! Automaticaly removes the shared memory managed when the scope finishes
    template<typename dataType, processNumber_t numProcesses, bufferSize_t bufferSize>
    shared_memory_provider<dataType, numProcesses, bufferSize>::~shared_memory_provider()
    {
        shared_memory_object::remove(_shm_name.c_str());
        std::cout << "Shared Memory removed with success\n";
    };
}; //namespace sharedmm