#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include "BitcoinExchange.hpp"
void leaks(){system("leaks identify");}
int main(int argc, char const *argv[])
{
    atexit(leaks);
    if (argc == 2)
    {
        std::ifstream data(DATA_PATH);
        std::ifstream target(argv[1]);

        if (!data.is_open() || !target.is_open())
            return (std::cerr << "Error: could not open file.\n", 1);

        try
        {
            BitcoinExchange::InstanceBitcoinExchange(data);
        }
        catch (const std::string &e)
        {
            std::cerr << e;
        }
        try
        {
            read_data(target);
        }
        catch (const std::string &e)
        {
            std::cerr << e;
        }
        BitcoinExchange::DeleteBitcoinExchange();
        return 0;
    }
    return (std::cerr << "Error: could not open file.\n", 1);
}
