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
		int				getContactCount();
		Contact			getContact(int index);
		void			setContact(Contact contact);
		void			setContactCount(int contactCount);
		bool			addContact(PhoneBook &phonebook, int &ret);
		bool			searchContact(PhoneBook phonebook);
		void			printContactShortDesc(int index);
		void			printContactDesc(int index);
};