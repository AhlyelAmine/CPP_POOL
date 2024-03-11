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


void    check_value_validity(std::string portion, double &value)
{
    value = atof(portion.c_str());
    if (value < 0)
        throw std::string("Error: not a positive number.");
    if (value > 1000)
        throw std::string("Error: too large a number.");
}

Date *date_parser(std::string portion)
{
    std::stringstream date(portion);
    std::string year,month,day;
    getline(date, year,'-');
    if (date.eof())
        throw portion;
    getline(date, month,'-');
    if (date.eof())
        throw portion;
    date >> day;
    Date * a = NULL;
    try
    {
        a = new Date(year, month, day);
    }
    catch (const std::string &e)
    {
        throw portion;
    }
    return (a);
}

bool csv_parser(std::string const &line)
{
    struct data data;
    data.date = NULL;
    std::stringstream l(line);
    std::string portion;
    l >> portion;
    try
    {
        data.date = date_parser(portion);
    }
    catch (const std::string &e)
    {
        throw "Error: bad input => " + e;
    }
    l >> portion;
    if (portion != "|")
    {
        delete data.date;
        throw std::string("invalid format");
    }
    if (l.eof())
    {
        delete data.date;
        throw std::string("Error: missing number");
    }
    l >> portion;
    try
    {
        check_value_validity(portion, data.value);
    }
    catch (const std::string &e)
    {
        delete data.date;
        throw e;
    }
    try
    {
        std::cout << *data.date << " => " << data.value * BitcoinExchange::getBitcoinExchangeInstance()->getLowerBoundOf(*data.date) << std::endl;
    }
    catch (const std::string &e)
    {
        delete data.date;
        throw e;
    }
    delete data.date;
    return (true);
}

void    checkCsvHeader(std::string const &line)
{
    std::string tmp;
    
    std::stringstream stream(line);
    stream >> tmp;
    if (tmp == "date")
    {
        stream >> tmp;
        if (tmp == "|")
        {
            stream >> tmp;
            if (tmp != "value")
            {
                try
                {
                    csv_parser(line);
                }
                catch (const std::string &e)
                {
                    std::cerr << e << '\n';
                }
            }
        }
    }
}

void read_data(std::ifstream &s)
{
    std::string line;

    getline(s, line);


    checkCsvHeader(line);

    do
    {
        getline(s, line);
        try
        {
            csv_parser(line);
        }
        catch (const std::string &e)
        {
            std::cerr << e << '\n';
        }
    }
    while (!s.eof());
}
