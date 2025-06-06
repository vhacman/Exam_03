/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintaur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:11:44 by apintaur          #+#    #+#             */
/*   Updated: 2025/06/06 09:11:45 by apintaur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i] != NULL; i++)
		{
			for (int j = 0; argv[i][j] != '\0'; j++)
				argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i];
		}
	}
	std::cout << std::endl;
}
