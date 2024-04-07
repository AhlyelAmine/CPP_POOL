#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <map>
#include <fstream>
#include <cstdlib>
#include <ostream>
#define DATA_PATH "data.csv"

class Date
{
    Date();
    bool validateDate(void);
    Date(Date const &);
    Date& operator=(Date const &copy){(void)copy;return (*this);}
    public:
        std::string sYear, sMonth, sDay;
        std::string date;
        Date(std::string, std::string, std::string);
        ~Date(void);
};

std::ostream &operator<<(std::ostream &, const Date&);

struct data
{
    Date* date;
    double value;
};

class BtcDatabase
{
    std::map<std::string, struct data*>  _map;

    BtcDatabase(BtcDatabase const &);
    BtcDatabase& operator=(BtcDatabase const &copy){(void)copy;return *this;};

    double valueParser(std::string const &);
    void fileParser(std::ifstream&);
    void lineParser(std::string const &);
    Date* dateParser(std::string const &);

    protected :

        BtcDatabase(){};
        void initDatabase(std::ifstream&);
        virtual ~BtcDatabase();

    public :

        double getLowerBoundOf(Date const &);
};

std::ostream& operator<<(std::ostream&, std::map<std::string, struct data*> const&);

class BitcoinExchange : public BtcDatabase
{
    static BitcoinExchange* bitcoinExchange;

    BitcoinExchange(BitcoinExchange const &);
    BitcoinExchange& operator=(BitcoinExchange const &copy){(void)copy;return *this;}
    BitcoinExchange(){};
    public :
        static void                InstanceBitcoinExchange(std::ifstream&);
        static BitcoinExchange*    getBitcoinExchangeInstance();
        static void DeleteBitcoinExchange();
        ~BitcoinExchange();
};

void    check_value_validity(std::string portion, double &value);
Date    *date_parser(std::string portion);
void    csv_parser(std::string const &line);
void    checkCsvHeader(std::string const &line);
void    read_data(std::ifstream &s);

#endif
