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
    // Automaticaly leak shared memory
    shared_memory_provider shmm_garbage_collector ("MySharedMemory");

    //Create a shared memory object.
    shared_memory_object shm
       (create_only                  //only create
       ,"MySharedMemory"              //name
       ,read_write  //read-write mode
       );

    //Set size
    shm.truncate(sizeof(shared_memory_buffer));

    //Map the whole shared memory in this process
    mapped_region region
       (shm                       //What to map
       ,read_write //Map it as read-write
       );

    //Get the address of the mapped region
    void * addr       = region.get_address();

    //Construct the shared structure in memory
    shared_memory_buffer * data = new (addr) shared_memory_buffer;

    const int NumMsg = 100;

    //Insert data in the array
    for(int i = 0; i < NumMsg; ++i){
        data->nempty.wait();
        data->mutex.wait();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "Produz item : " << i << std::endl;
        data->items[i % shared_memory_buffer::NumItems] = i;
        data->mutex.post();
        data->nstored.post();
    }

    return 0;
}