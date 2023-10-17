#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

bool    getValue(std::string &value, std::string key, int &ret);

class PhoneBook
{
	private :
		Contact contacts[8];
		int contactCount;
	public :
		PhoneBook();
		~PhoneBook();
		int				getContactCount() const;
		Contact			getContact(int index) const;
		void			setContact(Contact contact);
		void			setContactCount(int contactCount);
		bool			addContact(PhoneBook &phonebook, int &ret);
		bool			searchContact(PhoneBook phonebook) const;
		void			printContactShortDesc(int index) const;
		void			printContactDesc(int index) const;
};