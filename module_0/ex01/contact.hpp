/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:44:20 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/21 09:52:21 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class contact
{
private:
	int			_exist;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_secret;
public:
	contact(void);
	~contact(void);

	void new_contact(void);
	void rm_contact(void);
	void show_contact(int index);
	void print_contact(void);
	void print_str10(std::string str);
};


#endif