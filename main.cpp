#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/circular_buffer.hpp>
#include <iostream>
using namespace boost::interprocess;
int main()
{
    typedef boost::circular_buffer<int> circular_buffer;
    try
    {
        shared_memory_object::remove("Boost");
        managed_shared_memory managed_shm{open_or_create, "Boost", sizeof(circular_buffer) * sizeof(int)};
        circular_buffer* buffer = managed_shm.construct<circular_buffer>("Buffer")(5);
    }
    catch (boost::interprocess::bad_alloc &ex)
    {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}