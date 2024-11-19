//
// Created by dev on 28/09/24.
//

#ifndef SHARED_MEMORY_PROVIDER_H
#define SHARED_MEMORY_PROVIDER_H

#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <memory>
#include <sharedmm/shared_mem_buffer.h>

using namespace boost::interprocess;

namespace sharedmm
{
    //! Manages creation an automatic destruction of shared memory in the scope where it is declared
    //!
    template <typename bufferData_t, processNumber_t numOfProcesses, bufferSize_t bufferSize>
    class shared_memory_provider final
    {
    private:
        //! Stores the shared memory name managed by this class
        std::string _shm_name;
        shared_memory_buffer<char,numOfProcesses, bufferSize> *_buffer;
        processNumber_t _numProcesses = numOfProcesses;
        bufferSize_t _bufferSize = bufferSize;

    public:
        //! Avoids some constructors
        shared_memory_provider(const shared_memory_provider&) = delete;
        shared_memory_provider& operator=(const shared_memory_provider&) = delete;
        shared_memory_provider(shared_memory_provider&&) = delete;
        shared_memory_provider() = delete;

        explicit shared_memory_provider(const char* name);

        //! The shared memory is destroyed when the execution leaves the scope where this class is declared
        ~shared_memory_provider();
    };

}; //namespace sharedmm

#endif //SHARED_MEMORY_PROVIDER_H
