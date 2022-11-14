/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 09:10:38 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/13 12:59:55 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int	main(void)
{
	phonebook	phonebook;
	std::string	command;

	std::cout << "Welcome to your new phonebook !\n";
	while (1)
	{
		std::cout << "Type ADD to add a new contact\n";
		std::cout << "Type SEARCH to search a contact\n";
		std::cout << "Type EXIT to quit the phonebook\n";
		std::cout << ">";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact();
		if (command == "SEARCH")
			phonebook.search_contact();
		if (command == "EXIT")
			break;
	}
	return (0);
}