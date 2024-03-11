#include "BtcDatabase.hpp"

BtcDatabase::~BtcDatabase()
{
    for (std::map<std::string, struct data*>::iterator it = this->_map.begin(); it != this->_map.end(); it++)
    {
        delete it->second->date;
        delete it->second;
    }
}

Date* BtcDatabase::dateParser(std::string const &portion)
{
    std::stringstream dateStream(portion);
    std::string year,month,day;

    getline(dateStream, year,'-');
    getline(dateStream, month,'-');
    dateStream >> day;

    Date * date = NULL;
    try
    {
        date = new Date(year, month, day);
    }
    catch (const std::string &e)
    {
        throw portion;
    }

    return (date);
}

double    BtcDatabase::valueParser(std::string const&portion)
{
    return (atof(portion.c_str()));
}

void BtcDatabase::lineParser(std::string const &line)
{
    struct data *objet = new struct data;
    std::stringstream l(line);
    std::string portion;
    getline(l, portion, ',');

    try
    {
        objet->date = this->dateParser(portion);
    }
    catch (const std::string &e)
    {
        delete objet;
        throw e;
    }
    getline(l, portion, ',');

    try
    {
        objet->value = valueParser(portion);
    }
    catch (const std::string &e)
    {
        delete objet;
        throw e;
    }
    this->_map[objet->date->date] = objet;
}

void BtcDatabase::fileParser(std::ifstream& stream)
{
    std::string line;
    getline(stream, line);
    do
    {
        getline(stream, line);
        try
        {
            this->lineParser(line);
        }
        catch (const std::string &e)
        {
            std::cerr << e << '\n';
        }
    }
    while (!stream.eof());
}

void BtcDatabase::initDatabase(std::ifstream& stream)
{
    this->fileParser(stream);
}

double BtcDatabase::getLowerBoundOf(Date const &date)
{
    return (this->_map.lower_bound(date.date)->second->value);
}

std::ostream& operator<<(std::ostream& stream, std::map<std::string, struct data*> const& objet)
{
    for (std::map<std::string, struct data*>::const_iterator it = objet.begin(); it != objet.end(); it++)
    {
        stream << *it->second->date << "," << it->second->value << "\n";
    }
    return stream;
}
