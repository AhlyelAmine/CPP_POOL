#include "Contact.hpp"

void    Contact::setFirstName(const std::string firstName) {
    this->firstName = firstName;
}

void    Contact::setLastName(const std::string lastName) {
    this->lastName = lastName;
}

void    Contact::setNickName(const std::string nickName) {
    this->nickName = nickName;
}

void    Contact::setPhoneNumber(const std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void    Contact::setDarkestSecret(const std::string darkestSecret) {
    this->darkestSecret = darkestSecret;
}

const std::string Contact::getFirstName() const {
    return (this->firstName);
}

const std::string Contact::getLastName() const {
    return (this->lastName);
}

const std::string Contact::getNickName() const {
    return (this->nickName);
}

const std::string Contact::getPhoneNumber() const {
    return (this->phoneNumber);
}

const std::string Contact::getDarkestSecret() const {
    return (this->darkestSecret);
}
