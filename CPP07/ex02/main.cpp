#include "Array.hpp"

#define SIZE 1337

int main(int, char**)
{
    srand(time(NULL));

    Array<int> array(SIZE);
    int* ptr = new int[SIZE];
    /*
        fill the array and ptr with same values
        and check that operator[] works as excepted
    */    
    for (int i = 0; i < SIZE; i++)
    {
        int tmp = rand();
        array[i] = tmp;
        ptr[i] = tmp;
    }
    /*
        tests to make sure that copy constructor and assignement operator work as excepted and show the use of deep copy
    */
    {
        Array<int> tmp = array;
        Array<int> newArray(tmp);
    }

    /*
        double check that array and ptr contains the same values ;) 
    */
    for (int i = 0; i < SIZE; i++)
    {
        if (ptr[i] != array[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }

    /*
        trying to access to inaccessible memory
        here try should catch the outofrange exception ;)
    */
    try
    {
        array[-1] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        array[SIZE] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    /*
        modify the values of the array to make sure that our operator[] works as excepted
    */
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand();
    }

    delete [] ptr;
    return 0;
}