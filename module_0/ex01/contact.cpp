/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:54:54 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/21 09:56:33 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

contact::contact(void){
	_exist = 0;
	return ;
}

contact::~contact(void){
	return ;
}

void contact::rm_contact(void)
{
	_first_name = "";
	_last_name = "";
	_nickname = "";
	_phone_number = "";
	_secret = "";
}

void contact::new_contact(void)
{
	if (_exist == 1)
		contact::rm_contact();
	_exist = 1;

	while (_first_name == "")
	{
		std::cout << "Insert first name : ";
		std::getline(std::cin, _first_name);
	}
	while (_last_name == "")
	{
	std::cout << "Insert last name : ";
	std::getline(std::cin, _last_name);
	}
	while (_nickname == "")
	{
	std::cout << "Insert nickname : ";
	std::getline(std::cin, _nickname);
	}
	while (_phone_number == "")
	{
	std::cout << "Insert phone number : ";
	std::getline(std::cin, _phone_number);
	}
	while (_secret == "")
	{
	std::cout << "Insert darkest secret : ";
	std::getline(std::cin, _secret);
	}
	std::cout << "---Contact added !---\n";
}

void contact::print_str10(std::string str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (j < 10 - i)
	{
		std::cout << " ";
		j++;
	}
	i = 0;
	while (j + i < 9)
	{
		std::cout << str[i];
		i++;
	}
	if (str[10])
		std::cout << ".";
	else
		std::cout << str[i];
}

void contact::show_contact(int index)
{
	index++;
	if (_exist == 1)
	{
		std::cout << "|         " << index << "|";
		print_str10(_first_name);
		std::cout << "|";
		print_str10(_last_name);
		std::cout << "|";
		print_str10(_nickname);
		std::cout << "|\n";
	}
	else
		std::cout << "|         " << index << "|          |          |          |\n";
	std::cout << "|----------|----------|----------|----------|\n";
}

void contact::print_contact(void)
{
	if (_exist == 1)
	{
		std::cout << "First name : : " << _first_name << std::endl;
		std::cout << "Last name : " << _last_name << std::endl;
		std::cout << "Nickname : " << _nickname << std::endl;
		std::cout << "Phone number : " << _phone_number << std::endl;
		std::cout << "Darkest secret : " << _secret << std::endl;
	}
	else
		std::cout << "This contact is empty, add more contact to fill your phonebook\n";
}