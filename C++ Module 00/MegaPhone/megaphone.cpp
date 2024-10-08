/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:48:15 by aeid              #+#    #+#             */
/*   Updated: 2024/10/04 18:21:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void message_write(char *argv, int argc)
{
	for (int i = 0; argv[i]; i++)
		std::cout << (char)toupper(argv[i]) << std::flush;
	if (argc != 1)
		std::cout << " ";
}

int main (int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		for (int i = 1; i < argc; i++)
			message_write(argv[i], (argc - i));	
	std::cout << std::endl;
	return (0);
}

