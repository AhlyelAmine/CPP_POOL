#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include "BtcDatabase.hpp"

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

#endif
