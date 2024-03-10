#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#define DATA_PATH "data.csv"
#include "Date.hpp"

void    check_value_validity(std::string portion, double &value)
{
    if (portion.empty())
        throw ("invalid csv format");
    value = atof(portion.c_str());
    if (value < 0 || value > 1000)
        throw "invalid value format";
}

std::map<std::string, Date*> map;

Date *date_parser(std::string portion)
{
    std::stringstream date(portion);
    std::string year,month,day;
    getline(date, year,'-');
    if (date.eof())
        throw "invalid format";
    getline(date, month,'-');
    if (date.eof())
        throw "invalid format";
    date >> day;
    Date * a = NULL;
    try {
        a = new Date(year, month, day);
    }
    catch (const char *e)
    {
        throw e;
    }
    return (a);
}

bool csv_parser(std::string &line)
{
    Date *a=NULL;
    std::stringstream l(line);
    std::string portion;
    l >> portion;
    try
    {
        a = date_parser(portion);
    }
    catch(const char *e)
    {
        throw e;
    }
    l >> portion;
    if (portion.empty() || l.eof())
    {
        delete a;
        throw "incomplete params";
    }
    l >> portion;
    try
    {
        check_value_validity(portion, a->value);
    }
    catch(const char *e)
    {
        delete a;
        throw e;
    }
    map[a->date] = a;
    return (true);
}

void read_data(std::ifstream &s)
{
    std::string line;
    getline(s, line);
    std::stringstream a(line);
    a >> line;
    if (line != "date")
        throw "invalid csv file\n";
    a >> line;
    if (line != "|")
        throw "invalid csv file\n";
    a >> line;
    if (line != "value")
        throw "invalid csv file\n";
    do
    {
        getline(s, line);
        try
        {
            csv_parser(line);
            // std::cout << sDate.year << "-" << sDate.mounth << "-" << sDate.day << " | " << value << "\n";
        }
        catch(const char *e)
        {
            std::cerr << e << '\n';
        }
    }
    while (!s.eof());
    std::map<std::string, Date*>::iterator it = map.begin();
    while (it != map.end())
    {
        std::cout << *it->second << std::endl;
        it++;
    }
}

int main(int argc, char const *argv[])
{
    std::ifstream data(DATA_PATH);
    if (!data.is_open())
    {
        std::cerr << "No such file data.csv\n";
        return (1);
    }
    if (argc != 2)
    {
        std::cerr << "USAGE : ./btc <input_file>\n";
        return (2);
    }
    std::ifstream target(argv[1]);
    if (!target.is_open())
    {
        std::cerr << "No such file " + std::string(argv[1]) + "\n";
        return (3);
    }
    try
    {
        read_data(target);
    }
    catch(const char *e)
    {
        std::cerr << e;
    }
    

    return 0;
}
