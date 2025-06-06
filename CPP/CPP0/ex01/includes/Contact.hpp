/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:11:49 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 09:11:50 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	mail;
		std::string	address;
		std::string	number;
	public:
		Contact(const std::string& firstName = "(null)",
				const std::string& lastName = "(null)",
				const std::string& nickname = "(null)",
				const std::string& mail = "(null)",
				const std::string& address = "(null)",
				const std::string& number = "xxxxxxxxxx");

		Contact(const Contact& contact);

		Contact& operator=(const Contact& newContact);

		inline void					setFirstName(const std::string& firstName){this->firstName = firstName;}
		inline void					setLastName(const std::string& lastName){this->lastName = lastName;}
		inline void					setNickname(const std::string& nickname){this->nickname = nickname;}
		inline void					setMail(const std::string& mail){this->mail = mail;}
		inline void					setAddress(const std::string& address){this->address = address;}
		inline void					setNumber(const std::string& number){this->number = number;}

		inline const std::string&	getFirstName() const {return (firstName);}
		inline const std::string&	getLastName() const {return (lastName);}
		inline const std::string&	getNickname() const {return (nickname);}
		inline const std::string&	getMail() const {return (mail);}
		inline const std::string&	getAddress() const {return (address);}
		inline const std::string&	getNumber() const {return (number);}

		~Contact();
};
#endif
