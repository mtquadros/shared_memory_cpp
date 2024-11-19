//
// Created by dev on 03/06/24.
//
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>
#include <thread>

#include <sharedmm/shared_mem_buffer.h>

using namespace boost::interprocess;
/******************************************************************
 * Important Note:
 * As the project is on working, this code is not using the library in folder lib_ipc yet.
 * This code is a example of using shared memory with Boost library
*************************************************************/

int main ()
{
    // Automatic manage allocation
    shared_memory_client shmm_garbage_collector ("MySharedMemory");

    //Create a shared memory object.
    shared_memory_object shm
       (open_only                    //only open
       ,"MySharedMemory"              //name
       ,read_write  //read-write mode
       );

    //Map the whole shared memory in this process
    mapped_region region
       (shm                       //What to map
       ,read_write //Map it as read-write
       );

    //Get the address of the mapped region
    void * addr       = region.get_address();

    //Obtain the shared structure
    shared_memory_buffer * data = static_cast<shared_memory_buffer*>(addr);

    const int NumMsg = 100;

    int extracted_data [NumMsg];

    //Extract the data
    for(int i = 0; i < NumMsg; ++i){
        data->nstored.wait();
        data->mutex.wait();
        extracted_data[i] = data->items[i % shared_memory_buffer::NumItems];
        std::cout << "Consome item: " << extracted_data[i] << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        data->mutex.post();
        data->nempty.post();
    }
    return 0;
}