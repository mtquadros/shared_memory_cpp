# Process sincronization using `Shared Memory`, `Mutex` and `Semaphore` from `Boost` library in a `Linux` enviroment

## Requirements used on this project (earlier versions was not tested):
> - `Boost` Library;
> -  GNU GCC version 11 or later (C++ standard 11 or later);
> - `CMake` version 3.22 or later;
> -  GNU Make 4.3 or later;
> - `Ubuntu` version 22.04.4 LTS or later.

## Building steps:
On a terminal type:
```
git clone https://github.com/mtquadros/shared_memory_cpp.git
```
```
cd shared_memory_cpp/cmake-build-debug/
```
```
rm -rf *
```
```
cmake .. && make
```

## Progress of this project:

### IPC by Shared Memory and Mutex,Semaphore mechanisms
 
> This example we use shared memory technique to implement a buffer of 10 integers as a 
> comunication channel between `producer.out` and `consumer.out` processes.
> 
> 
`../interprocess_comm/sharedmm/include/sharedmm/shared_mem_buffer.h` header file
> time enough to another process enter in the critical region and show this
> behaviour.
> 
### Demonstration:
> The demonstration below shows two terminals, each one is running the program.
> 
> Since the program properly sincronize the critical region it's suppose that 
> both terminals never shows the same number.

![Demonstration](./sync_demo.gif)

### Serialization by Semaphore mechanism:
> In progress...
