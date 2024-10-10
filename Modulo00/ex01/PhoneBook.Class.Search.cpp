/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.Search.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 15:21:36 by aeid              #+#    #+#             */
/*   Updated: 2024/10/09 18:18:56 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"

std::string len_checker(std::string str)
{
	if (str.length() > 10)
	{
		std::string new_str = str.substr(0, 9);
		new_str.append(".");
		return new_str;
	}
	return str;
}

void show_contact(Contact contacts[], int id)
{
	const std::string color = "\033[1;34m";
	const std::string reset = "\033[0m";

	std::cout << color << std::setfill('=') << "" << reset << std::endl;
	std::cout << std::setfill(' ');
	std::cout << "Here are details of contact: " << color << id << reset << std::endl;
	std::cout << "First Name: " << color << contacts[id].getfield(FIRSTNAME) << reset << std::endl;
	std::cout << "Last Name: " << color << contacts[id].getfield(LASTNAME) << reset << std::endl;
	std::cout << "Nickname: " << color << contacts[id].getfield(NICKNAME) << reset << std::endl;
	std::cout << "Phone Number: " << color << contacts[id].getfield(PHONENUM) << reset << std::endl;
	std::cout << "Darkest Secret: " << color << contacts[id].getfield(DARKESTSECRET) << reset << std::endl;
	std::cout << "Underwear Color: " << color << contacts[id].getfield(UNDERWEAR) << reset << std::endl;
	std::cout << color << std::setfill('=') << "" << reset << std::endl;
	std::cout << std::setfill(' ');
}

int PhoneBook::get_id()
{
	std::string input = "";
	int id = 0;
	bool flag = false;
	do {
		std::cout << "\033[1;34mInsert the ID of the contact: \033[0m" << std::endl;
		std::getline(std::cin, input);
		try {
			id = std::stoi(input, nullptr, 10);
			if (id < 0 || id > (MAX_CONTACTS - 1))
				throw std::invalid_argument("😠😠😠😠😠😠😠😠😠");
			else if (id > _index % MAX_CONTACTS || _contacts[id].getfield(FIRSTNAME).empty())
				throw std::out_of_range("😠😠😠😠😠😠😠😠😠😠😠😠😠😠😠");
			else
				flag = true;
		} catch (std::invalid_argument &e) {
			std::cout << "\033[1;31mOnly insert acceptable characters..Smart Ass😠.\033[0m" << std::endl;
			input.clear();
		} catch (std::out_of_range &e) {
			std::cout << "\033[1;31mOnly insert acceptable characters..Smart Ass😠.\033[0m" << std::endl;
			input.clear();
		}
	} while (!flag);
	return id;
}

void PhoneBook::_print_contact(Contact contacts[], int id)
{
	const std::string red = "\033[1;31m";
	const std::string reset = "\033[0m";
	
	if (id == -1)
	{
		std::cout << red << std::setw((MAX_WIDTH * 4) + 5) << std::setfill('-') << "" << reset << std::endl;
		std::cout << std::setfill(' ');
		std::cout << red << "|" << reset << std::setw(10) << "ID" << red << "|" << reset;
		std::cout << std::setw(MAX_WIDTH) << "First Name" << red << "|" << reset;
		std::cout << std::setw(MAX_WIDTH) << "Last Name" << red << "|" << reset;
		std::cout << std::setw(MAX_WIDTH) << "Nickname" << red << "|" << reset << std::endl;
		std::cout << red << std::setw((MAX_WIDTH * 4) + 5) << std::setfill('-') << "" << reset << std::endl;
		std::cout << std::setfill(' ');
		for (int i = 0; i <= _index && i < MAX_CONTACTS; i++)
		{
			if (contacts[i].getfield(FIRSTNAME).empty())
				break;
			std::cout << red << "|" << reset << std::setw(MAX_WIDTH) << i << red << "|" << reset;
			std::cout << std::setw(MAX_WIDTH) << len_checker(contacts[i].getfield(FIRSTNAME)) << red << "|" << reset;
			std::cout << std::setw(MAX_WIDTH) << len_checker(contacts[i].getfield(LASTNAME)) << red << "|" << reset;
			std::cout << std::setw(MAX_WIDTH) << len_checker(contacts[i].getfield(NICKNAME)) << red << "|" << reset << std::endl;
			std::cout << red << std::setw((MAX_WIDTH * 4) + 5) << std::setfill('-') << "" << reset << std::endl; 
			std::cout << std::setfill(' ');
		}
	}
	else
		show_contact(contacts, id);
}


void PhoneBook::search_contact(PhoneBook &phonebook)
{
	const std::string color = "\033[1;34m";
	const std::string reset = "\033[0m";
	
	if (_index == -1)
	{
		std::cout << "\033[1;31mEMPTY LIST OF CONTACTS.\033[0m" << std::endl;
		return;
	}
	int id = 0;
	phonebook._print_contact(phonebook._contacts, -1);
	id = get_id();
	std::cout << color << "The inserted ID is: " << reset << id << color << " belongs to: " << reset << phonebook._contacts[id].getfield(FIRSTNAME) << std::endl;
	std::cout << color << "Please wait...🕒" << reset << std::endl;
	sleep(2);
	phonebook._print_contact(phonebook._contacts, id);
}
