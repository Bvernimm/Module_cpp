/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:34:02 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/21 09:56:48 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

phonebook::phonebook(void)
{
	return ;
}

phonebook::~phonebook(void)
{
	return ;
}

void	phonebook::add_contact(void)
{
	static int	index;

	_contacts[index].new_contact();
	index ++;
	if (index == 8)
		index = 0;
}

void	phonebook::search_contact(void)
{
	std::string	index;
	int			i;

	std::cout << "|----------|----------|----------|----------|\n";
	std::cout << "|  Index   |First name| Last name| Nickname |\n";
	std::cout << "|----------|----------|----------|----------|\n";
	i = 0;
	while (i < 8)
	{
		_contacts[i].show_contact(i);
		i++;
	}
	while (1)
	{
		std::cout << "Enter contact index : ";
		std::getline(std::cin, index);
		i = std::atoi(index.c_str());
		if (i >= 1 && i <= 8)
		{
			_contacts[i - 1].print_contact();
			break ;
		}
		else
			std::cout << "index invalid, please retry\n";
	}
}
