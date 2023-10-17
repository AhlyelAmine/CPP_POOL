#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

int    getValue(std::string &value, std::string key);

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
		int			addContact(PhoneBook &phonebook);
		bool			searchContact(PhoneBook phonebook);
		void			printContactShortDesc(int index);
		void			printContactDesc(int index);
};