#include "BitcoinExchange.hpp"

BitcoinExchange* BitcoinExchange::bitcoinExchange = NULL;

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::InstanceBitcoinExchange(std::ifstream&stream)
{
    if (!bitcoinExchange)
    {
        bitcoinExchange = new BitcoinExchange();
        bitcoinExchange->initDatabase(stream);
    }
}

BitcoinExchange*    BitcoinExchange::getBitcoinExchangeInstance()
{
    return (bitcoinExchange);
}
