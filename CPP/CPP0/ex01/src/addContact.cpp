/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:11:57 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 09:11:58 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void	setContactInfo(const std::string& display,
						void (Contact::*setInfo)(const std::string&),
						Contact *newContact);

void	contactAdd(PhoneBook *phoneBook)
{
	Contact		newContact;
	std::string	input;

	if (!phoneBook)
	{
		std::cout << "Please, insert a valid contact." << std::endl;
		return ;
	}

	setContactInfo("First name: ", &Contact::setFirstName, &newContact);
	setContactInfo("Last name: ", &Contact::setLastName, &newContact);
	setContactInfo("Nickname: ", &Contact::setNickname, &newContact);
	setContactInfo("Email: ", &Contact::setMail, &newContact);
	setContactInfo("Address: ", &Contact::setAddress, &newContact);
	setContactInfo("Number: ", &Contact::setNumber, &newContact);

	phoneBook->addContact(newContact);
}

void	setContactInfo(const std::string& display,
						void (Contact::*setInfo)(const std::string&),
						Contact *newContact)
{
	std::string	input;

	std::cout << display;
	std::getline(std::cin, input);
	(newContact->*setInfo)(input);
}
