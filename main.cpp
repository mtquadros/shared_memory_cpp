#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/named_mutex.hpp>
#include <iostream>
#include <thread>
#include <chrono>
using namespace boost::interprocess;
using namespace std::chrono_literals;
/*
 * This programs increments a integer variable in the shared memory 15 times, before each increment the
 * process waits for 2 secs. The waiting time allow us to see the sincronization of two processes running this program.
 */
int main()
{
    constexpr char shm_name[] = "mydata";
    constexpr char mtx_name[] = "mymtx";
    constexpr char obj_name[] = "Integer";
    constexpr u_int32_t shm_size = 1024;
    // The first process to start running is going to create the shared memory named "mydata" and the object
    // named "Integer" as well the mutex "mymtx" which is used by each process to serialize the access to the critical region.
    // The others processes will use the same shared memory "mydata".
    managed_shared_memory managed_shm{open_or_create, shm_name, shm_size};

    int *i = managed_shm.find_or_construct<int>(obj_name)();
    named_mutex named_mtx{open_or_create, mtx_name};

    for(int k = 0; k < 15; k++)
    {
        std::this_thread::sleep_for(2000ms);
        named_mtx.lock();
        // critical region serialized by mutex
        ++(*i);
        std::cout << *i << '\n';
        // end of the critical region
        named_mtx.unlock();
    }
    // the last process running will remove the shared memory
    if (shared_memory_object::remove(shm_name))
        std::cout << "Shared memory removed successfully." << std::endl;
}