/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:12:01 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 09:12:02 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Contact.hpp"

Contact::Contact(const std::string& firstName, const std::string& lastName, const std::string& nickname,
				const std::string& mail, const std::string& address, const std::string& number)
: firstName(firstName), lastName(lastName), nickname(nickname), mail(mail), address(address), number(number)
{

}

Contact::Contact(const Contact& NewContact)
{
	firstName = NewContact.firstName;
	lastName = NewContact.lastName;
	nickname = NewContact.nickname;
	mail = NewContact.mail;
	address = NewContact.address;
	number = NewContact.number;
}

Contact&	Contact::operator=(const Contact& NewContact)
{
	if (this != &NewContact)
	{
		firstName = NewContact.firstName;
		lastName = NewContact.lastName;
		nickname = NewContact.nickname;
		mail = NewContact.mail;
		address = NewContact.address;
		number = NewContact.number;
	}
	return (*this);
}

Contact::~Contact()
{

}
