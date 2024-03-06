#pragma once
#include <iostream>

class Warlock
{
    std::string name;
    std::string title;
    Warlock();
    Warlock(const Warlock&);
    Warlock& operator=(const Warlock&){return *this;}
    public: 
        const std::string getName() const;
        const std::string getTitle() const;
        void setTitle(const std::string&);
        Warlock(const std::string&, const std::string&);
        void introduce() const;
        ~Warlock();
};
