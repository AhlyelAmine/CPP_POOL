#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator> 
#include <vector> 

template <typename T>

typename T::iterator   easyfind(T& a, int b)
{
    typename T::iterator it = std::find(a.begin(), a.end(), b);
    if (it == a.end())
        throw "not found\n";
    return (it);
}

#endif
