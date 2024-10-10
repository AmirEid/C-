/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 00:14:45 by aeid              #+#    #+#             */
/*   Updated: 2024/10/10 00:12:54 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"

PhoneBook::PhoneBook(void): _index(-1) {
	std::cout << "Why would a phonebook apply for a job?" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	std::cout << "It wanted to make some contacts! 📖😄" << std::endl;
	return;
}

void PhoneBook::addcontact(std::string& input, Fields field)
{
	int actual_index = _index % MAX_CONTACTS;
	
	if (field == FIRSTNAME)
		_contacts[actual_index].setfield(input, FIRSTNAME);
	else if (field == LASTNAME)
		_contacts[actual_index].setfield(input, LASTNAME);
	else if (field == NICKNAME)
		_contacts[actual_index].setfield(input, NICKNAME);
	else if (field == PHONENUM)
		_contacts[actual_index].setfield(input, PHONENUM);
	else if (field == DARKESTSECRET)
		_contacts[actual_index].setfield(input, DARKESTSECRET);
	else if (field == UNDERWEAR)
		_contacts[actual_index].setfield(input, UNDERWEAR);
}

bool PhoneBook::checkindex()
{
	std::string input = "";
	if (_index == MAX_CONTACTS - 1)
	{
		std::cout << "\033[1;31mPhoneBook is full! We will start overwriting.\033[0m" << std::endl;
		std::cout << "\033[1;34mTO continue (y), or press anything else to skip\033[0m" << std::endl;
		std::getline(std::cin, input);
		if (!input.compare("y"))
		{
			_index++;
			return true;
		}
		return false;
	}
	_index++;
	return true;
}
