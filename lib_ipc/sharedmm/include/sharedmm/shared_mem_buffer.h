//!
//! Created by dev on 03/06/24.
//!
#ifndef _SHARED_MEM_BUFFER_H_
#define _SHARED_MEM_BUFFER_H_

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>

#include <tuple>
#include <unistd.h>

#include <sharedmm/shared_memory_client.h>
#include <sharedmm/shared_memory_provider.h>
#include <sharedmm/shmmdef.h>

using namespace boost::interprocess;

namespace sharedmm
{
    template <typename bufferData_t, processNumber_t numOfProc, bufferSize_t bufferSize>
    class shared_memory_buffer final
    {
    public:
        shared_memory_buffer()
            : mutex(1), nempty(bufferSize), nstored(0)
        {};
        ~shared_memory_buffer()= default;

        //! Only those two class have access to the buffer
        friend class shared_memory_client;
        friend class shared_memory_server;

    private:
        //! Semaphores to protect and synchronize access
        boost::interprocess::interprocess_semaphore mutex, nempty, nstored;

        constexpr processNumber_t _numProcesses = numOfProc;
        constexpr bufferSize_t    _bufferSize = bufferSize;

        //! Friendly indexes of the columns in the rows of the buffer
        enum { processID = 0, isProcessValid = 1, dataPad = 2};

        //! A row contains an input buffer of a process for receiving messages from others processes
        //! Each process reads its buffer (flagged with its pid) and writes in the buffers of others processes
        //! Each process can write bufferSize items of type bufferData_t
        using Row = std::tuple<processId_t,validProcess_t,std::array<bufferData_t,bufferSize>>;
        using PoolBuffer = std::array<Row,numOfProc>;

        //! It's the buffer
        //! An array of tuples where each row is [ pid, flag_is_proc_connected, array_of_data ]
        // TODO How Does a process know the pid of the process he wants to send message to?
        PoolBuffer bufferPool;
    };
}; //namespace sharedmm

#endif //_SHARED_MEM_BUFFER_H_
