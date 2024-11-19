//
// Created by dev on 23/09/24.
//
#include <cstdint>

class channel final{
private:
  typedef union {
    std::uint data_char;
    char data_uchar;
    short data_short;
    int data_int;
    unsigned
    long long data_long;
    float data_float;
    double data_double;
  } channel_data;

  typedef struct{
    channel_data data;

public:
    // Avoid copy constructor and copy assigment
    channel(const channel &) = delete;
    channel &operator=(const channel &) = delete;
    // Avoid move constructor and move assigment
    channel(channel &&) = delete;
    channel &operator=(channel &&) = delete;


};