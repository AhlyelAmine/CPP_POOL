#include "BitcoinExchange.hpp"

bool check_format(size_t size, std::string maxV, std::string minV, std::string target)
{
    if (target.size() != size || target > maxV || target < minV || target.find_first_not_of("0123456789") != std::string::npos)
    {
        return false;
    }
    return true;
}

bool Date::validateDate(void)
{
    int iYear = atoi(this->sYear.c_str());
    int iMonth = atoi(this->sMonth.c_str());

    if (!check_format(4, "2024", "1900", this->sYear))
        return false;
    if (!check_format(2, "12", "01", this->sMonth))
        return false;
    if (!check_format(2, "31", "01", this->sDay))
        return false;
    if (this->sMonth == "02" && this->sDay > "29")
        return false;
    if ((iYear % 4) && this->sMonth == "2" && this->sDay == "29")
        return false;
    if (this->sMonth <= "07" && this->sMonth >= "01" && !(iMonth % 2) && this->sDay == "31")
        return false;
    if (this->sMonth <= "12" && this->sMonth >= "08"  && (iMonth % 2) && this->sDay == "31")
        return false;
    return true;
}

Date::Date(std::string year, std::string month, std::string day) : sYear(year), sMonth(month), sDay(day), date(year + "-" + month + "-" + day)
{
    if (!this->validateDate())
    {
        throw std::string("");
    }
}

Date::~Date(){}

std::ostream &operator<<(std::ostream &s, const Date&d)
{
    s << d.sYear << "-" << d.sMonth << "-" << d.sDay;
    return s;
}

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
