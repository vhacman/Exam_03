/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:12:12 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 09:14:33 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <cstdlib>

void	displayHeader();
void	displayTab(const PhoneBook& phoneBook);
void	displayContact(const Contact& contactFound);
void	displayColumn(const Contact& contactFound, const std::string& (Contact::*getInfo)() const);

void	contactSearch(const PhoneBook& phoneBook)
{
	Contact		tmp;
	std::string	s;

	if (phoneBook.isEmpty())
	{
		std::cout << "\n***Phonebook is empty***" << std::endl;
		return ;
	}

	displayTab(phoneBook);

	std::cout << "\nPlease insert the contact's index to search for: ";
	std::getline(std::cin, s);

	tmp = phoneBook.getContact(atoi(s.c_str()));
	if (tmp.getFirstName() != "(null)" && tmp.getLastName() != "(null)")
	{
		std::cout << "\n***Contact found***" << std::endl;
		displayContact(tmp);
	}
	else
		std::cout << "\n***Contact not found***" << std::endl;
	std::cout << std::endl;
}

void	displayTab(const PhoneBook& phoneBook)
{
	Contact	tmp;

	displayHeader();

	for (int i = 0; i < MAX_CONTACTS && i < phoneBook.getSize(); i++)
	{
		tmp = phoneBook.getContact(i);
		if (tmp.getFirstName() != "(null)")
		{
			std::cout << "|         " << i;

			displayColumn(tmp, &Contact::getFirstName);
			displayColumn(tmp, &Contact::getLastName);
			displayColumn(tmp, &Contact::getNickname);

			std::cout << "|" << std::endl;
		}
	}
	std::cout << " ------------------------------------------- " << std::endl;
}
void	displayHeader()
{
	std::cout << "\n***Stored Contacts***" << std::endl;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void	displayColumn(const Contact& contactFound, const std::string& (Contact::*getInfo)() const)
{
	std::string info;

	info = (contactFound.*getInfo)();
	if (info.length() > 10)
		info = info.substr(0, 9) + ".";
	std::cout << "|" << std::string(10 - info.length(), ' ') << info;
}

void	displayContact(const Contact& contactFound)
{
	std::cout << "Name: " << contactFound.getFirstName() << std::endl;
	std::cout << "Surname: " << contactFound.getLastName() << std::endl;
	std::cout << "Nickname: " << contactFound.getNickname() << std::endl;
	std::cout << "Email: " << contactFound.getMail() << std::endl;
	std::cout << "Address: " << contactFound.getAddress() << std::endl;
	std::cout << "Number: " << contactFound.getNumber() << std::endl;
}
