/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Add.Function.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:25:20 by aeid              #+#    #+#             */
/*   Updated: 2024/10/07 22:35:26 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"

static bool is_empty(const std::string str)
{
	for (int i = 0; i < static_cast<int>(str.length()); i++)
	{
		if (!std::isspace(str[i]))
			return false;
	}
	std::cout << "\033[1;31mInsert something! WTF man!😡😡😡.\033[0m" << std::endl;
	return true;
}

static void add_first_name(PhoneBook &phonebook)
{
	std::string input = "";
	
	do {
		std::cout << "\033[1;34mEnter the first name: \033[0m" << std::endl;
		std::getline(std::cin, input);
	} while (is_empty(input));
	phonebook.addcontact(input, FIRSTNAME);
}

static void add_last_name(PhoneBook &phonebook)
{
	std::string input = "";
	
	do {
		std::cout << "\033[1;34mEnter the last name: \033[0m" << std::endl;
		std::getline(std::cin, input);
	} while (is_empty(input));
	phonebook.addcontact(input, LASTNAME);
}

static void add_nickname(PhoneBook &phonebook)
{
	std::string input = "";
	
	do {
		std::cout << "\033[1;34mEnter the nickname: \033[0m" << std::endl;
		std::getline(std::cin, input);
	} while (is_empty(input));
	phonebook.addcontact(input, NICKNAME);
}

static void add_phonenum(PhoneBook &phonebook)
{
	std::string input = "";
	
	do {
		std::cout << "\033[1;34mEnter the phone number: \033[0m" << std::endl;
		std::getline(std::cin, input);
	} while (is_empty(input));
	phonebook.addcontact(input, PHONENUM);
}

static void add_darkest_secret(PhoneBook &phonebook)
{
	std::string input = "";
	
	do {
		std::cout << "\033[1;34mEnter the darkest secret: \033[0m" << std::endl;
		std::getline(std::cin, input);
	} while (is_empty(input));
	phonebook.addcontact(input, DARKESTSECRET);
}

static void add_underwear(PhoneBook &phonebook)
{
	std::string input = "";
	
	do {
		std::cout << "\033[1;34mEnter favorite underwear color: \033[0m" << std::endl;
		std::getline(std::cin, input);
	} while (is_empty(input));
	phonebook.addcontact(input, UNDERWEAR);
}

void add_function(PhoneBook &phonebook)
{
	phonebook.checkindex();
	add_first_name(phonebook);
	add_last_name(phonebook);
	add_nickname(phonebook);
	add_phonenum(phonebook);
	add_darkest_secret(phonebook);
	add_underwear(phonebook);
	phonebook.increase_index();
}