#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main( void )
{
    int	const           set[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const        set_size( sizeof(set) / sizeof(int) );
	std::vector<int>    target( set, set + set_size );
	
	try 
	{
		std::cout << *easyfind( target, 12345 ) << std::endl;
	}
	catch (const char* e) 
	{
		std::cout << e;
	}

	return 0;
}
