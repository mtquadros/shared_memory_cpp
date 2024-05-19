//
// Created by dev on 18/05/24.
//
#include <boost/circular_buffer.hpp>
#include <iostream>
int main()
{
    typedef boost::circular_buffer<int> circular_buffer;
    std::cout << "size_of(circular_buffer): " << sizeof(circular_buffer) << '\n';
    circular_buffer cb{3};
    std::cout << "Capacity: " << cb.capacity() << '\n';
    std::cout << "Size: " << cb.size() << '\n';
    std::cout << "size_of(circular_buffer): " << sizeof(circular_buffer) << '\n';
    cb.push_back(0);
    cb.push_back(1);
    cb.push_back(2);
    std::cout << cb.size() << '\n';
    cb.push_back(3);
    cb.push_back(4);
    cb.push_back(5);
    std::cout << cb.size() << '\n';
    for (int i : cb)
        std::cout << i << '\n';

    return 0;
}
