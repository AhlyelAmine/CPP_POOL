#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include <iostream>

typedef struct my_data
{
    int data;
}   Data;

class Serializer
{
    Serializer();
    public : 
        ~Serializer();
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif