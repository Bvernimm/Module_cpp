/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:27:11 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/13 10:54:02 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"

class phonebook
{
private:
	contact _contacts[8];
public:
	phonebook(void);
	~phonebook(void);

	void add_contact(void);
	void search_contact(void);
};

#endif