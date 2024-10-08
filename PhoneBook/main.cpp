/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 22:32:16 by aeid              #+#    #+#             */
/*   Updated: 2024/10/08 15:24:37 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"

static int exit_function() {
	std::string input = "";
	std::cout << "\033[1;36mAre you sure you want to exit? (y/n)\033[0m" << std::endl;
	std::getline(std::cin, input);
	if (!input.compare("y"))
	{
		std::cout << "\033[1;36mYou just lost all the contacts..Goodbye! 😛\033[0m" << std::endl;
		return 1;
	}
	else
		return 0;
}


int main (void) {	
	PhoneBook phonebook;
	std::string input = "";
	
	sleep(2);
	std::cout << "\033[1;36mYou may find the answer in the PhoneBook... Welcome!\033[0m" << std::endl;
	std::cout << "\033[1;36mHit ENTER to continue...\033[0m" << std::endl;
	std::getline(std::cin, input);
	while (true)
	{
		std::cout << "\033[1;33mHow can I help you today?\033[0m" << std::endl;
		std::cout << "\033[1;33m> \033[0m";
		std::getline(std::cin, input);
		if (!input.compare("EXIT"))
		{
			if (exit_function())
				break;
		}
		else if (!input.compare("ADD"))
			add_function(phonebook);
		else if (!input.compare("SEARCH"))
			phonebook.search_contact(phonebook);
		else
			std::cout << "\033[1;31mInvalid command. Only try ADD, SEARCH, EXIT.\033[0m" << std::endl;		
	}
	return 0;
}
