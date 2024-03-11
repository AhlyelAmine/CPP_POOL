#ifndef BTCDATABASE_HPP
#define BTCDATABASE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include "Date.hpp"

struct data
{
    Date* date;
    double value;

    void self_init(Date* date, double value)
    {
        this->date = date;
        this->value = value;
    };
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

#endif
