#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include "BtcDatabase.hpp"
#define DATA_PATH "data.csv"

class BitcoinExchange : public BtcDatabase
{
    static BitcoinExchange* bitcoinExchange;

    BitcoinExchange(BitcoinExchange const &);
    BitcoinExchange& operator=(BitcoinExchange const &copy){(void)copy;return *this;}
    BitcoinExchange(){};
    public :
        static void                InstanceBitcoinExchange(std::ifstream&);
        static BitcoinExchange*    getBitcoinExchangeInstance();
        ~BitcoinExchange();
};

void    check_value_validity(std::string portion, double &value);
Date *date_parser(std::string portion);
bool csv_parser(std::string const &line);
void    checkCsvHeader(std::string const &line);
void read_data(std::ifstream &s);

#endif
