/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:14:45 by aeid              #+#    #+#             */
/*   Updated: 2024/10/07 22:39:00 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"

PhoneBook::PhoneBook(void): _index(0) {
	std::cout << "Why would a phonebook apply for a job?" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "It wanted to make some contacts! 📖😄" << std::endl;
	return;
}

void PhoneBook::addcontact(std::string& input, Fields field)
{
	if (_index >= 0 && _index < MAX_CONTACTS) {
	if (field == FIRSTNAME)
		_contacts[_index].setfield(input, FIRSTNAME);
	else if (field == LASTNAME)
		_contacts[_index].setfield(input, LASTNAME);
	else if (field == NICKNAME)
		_contacts[_index].setfield(input, NICKNAME);
	else if (field == PHONENUM)
		_contacts[_index].setfield(input, PHONENUM);
	else if (field == DARKESTSECRET)
		_contacts[_index].setfield(input, DARKESTSECRET);
	else if (field == UNDERWEAR)
		_contacts[_index].setfield(input, UNDERWEAR);
	}
}

void PhoneBook::increase_index(void)
{
	std::cout << "\033[1;36mNew Contact Added!\nContact ID: \033[0m" << _index << std::endl;
	_index++;
}

void PhoneBook::checkindex(void)
{
	std::string input = "";
	if (_index == MAX_CONTACTS)
	{
		std::cout << "\033[1;31mPhoneBook is full! We will start overwriting.\033[0m" << std::endl;
		std::cout << "\033[1;34mDo you want to continue? (y/n)\033[0m" << std::endl;
		std::getline(std::cin, input);
		if (!input.compare("y"))
			_index = _index % MAX_CONTACTS;
	}
}