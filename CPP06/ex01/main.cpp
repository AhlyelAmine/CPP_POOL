#include "Serializer.hpp"

int main()
{
    Data* t = new Data;
    t->data = 5;

    std::cout<< t << " => data : " << t->data << std::endl;
    uintptr_t a = Serializer::serialize(t);
    std::cout << a << std::endl;
    t = Serializer::deserialize(a);
    std::cout<< t << " => data : " << t->data << std::endl;
    delete t;
}
