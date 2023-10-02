#pragma once

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

bool    get_value(std::string &value, std::string key);

class PhoneBook
{
	private :
		Contact contacts[8];
		int contact_count;
	public :
		int		get_contact_count();
		Contact	get_contact(int index);
		void		set_contact();
		void		set_contact(Contact contact);
		void		set_contact_count(int contact_count);
		PhoneBook();
		~PhoneBook();
		bool			add_contact(PhoneBook &phonebook);
		bool			search_contact(PhoneBook phonebook);
		void			printContactShortDesc(int index);
		void			printContactDesc(int index);
};