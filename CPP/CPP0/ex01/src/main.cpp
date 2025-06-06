/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:12:04 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 09:24:29 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <limits>

int	main()
{
	PhoneBook	myPhonebook;
	std::string	input;

	std::cout << "Welcome to the PhoneBook Management System." << std::endl;

	while (1)
	{
		std::cout << "\nPlease select an option from the menu below:" << std::endl;
		std::cout << "1) ADD		->	to add a new contact" << std::endl;
		std::cout << "2) SEARCH	->	to search for a contact" << std::endl;
		std::cout << "3) EXIT		->	to close the phonebook" << std::endl;
		std::cout << std::endl;
		std::cin >> input;
		std::cin.ignore();

		if (input == "ADD")
			contactAdd(&myPhonebook);
		else if (input == "SEARCH")
			contactSearch(myPhonebook);
		else if (input == "EXIT")
			break ;
	}

	return (0);
}
