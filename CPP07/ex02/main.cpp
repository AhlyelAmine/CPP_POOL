#include "Array.hpp"


int main(void)
{
    Array<int> emptyArray(0);
    const Array<int> constEmptyArray(0);
    Array<int> oneElemArray(1);
    const Array<int> constOneElemArray(1);
    Array<int> manyElemsArray(100);
    const Array<int> constManyElemsArray(100);

    std::cout << "emptyArray.size() : " << emptyArray.size() << std::endl;
    std::cout << "constEmptyArray.size() : " << constEmptyArray.size() << std::endl;
    try
    {
        std::cout << "emptyArray[0] : " << emptyArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout  << e.what() << std::endl;
    }
    try
    {
        std::cout << "constEmptyArray[0] : " << constEmptyArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "oneElemArray.size() : " << oneElemArray.size() << std::endl;
    std::cout << "constOneElemArray.size() : " << constOneElemArray.size() << std::endl;
    try
    {
        std::cout << "oneElemArray[0] : " << oneElemArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "constOneElemArray[0] : " << constOneElemArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "emptyArray.size() : " << emptyArray.size() << std::endl;
    std::cout << "constEmptyArray.size() : " << constEmptyArray.size() << std::endl;
    try
    {
        std::cout << "emptyArray[0] : " << emptyArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout  << e.what() << std::endl;
    }
    try
    {
        std::cout << "constEmptyArray[0] : " << constEmptyArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "manyElemsArray.size() : " << manyElemsArray.size() << std::endl;
    std::cout << "constManyElemsArray.size() : " << constManyElemsArray.size() << std::endl;
    try
    {
        manyElemsArray[0] = 5484;
        std::cout << "manyElemsArray[0] : " << manyElemsArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        constManyElemsArray[0] = 5484;
        std::cout << "constManyElemsArray[0] : " << constManyElemsArray[0] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

}

// #define SIZE 1337

// int main()
// {
//     srand(time(NULL));

//     Array<int> array(SIZE);
//     int* ptr = new int[SIZE];
//     /*
//         fill the array and ptr with same values
//         and check that operator[] works as excepted
//     */    
//     for (unsigned int i = 0; i < array.size(); i++)
//     {
//         int tmp = rand();
//         array[i] = tmp;
//         ptr[i] = tmp;
//     }
//     /*
//         tests to make sure that copy constructor and assignement operator work as excepted and show the use of deep copy
//     */
//     {
//         Array<int> tmp = array;
//         Array<int> newArray(tmp);
//     }

//     /*
//         double check that array and ptr contains the same values ;) 
//     */
//     for (unsigned int i = 0; i < array.size(); i++)
//     {
//         if (ptr[i] != array[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }

//     /*
//         trying to access to inaccessible memory
//         here try should catch the outofrange exception ;)
//     */
//     try
//     {
//         array[-1] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         array[SIZE] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     /*
//         modify the values of the array to make sure that our operator[] works as excepted
//     */
//     for (unsigned int i = 0; i < array.size(); i++)
//     {
//         array[i] = rand();
//     }

//     delete [] ptr;
//     return 0;
// }
