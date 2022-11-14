/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvernimm <bvernimm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 09:42:32 by bvernimm          #+#    #+#             */
/*   Updated: 2022/06/03 10:09:50 by bvernimm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	full_maj(char *str)
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; argv[i]; i++)
	{
		full_maj(argv[i]);
		std::cout << argv[i];
	}
	std::cout << "\n";
	return 0;
}