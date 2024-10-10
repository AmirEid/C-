/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:59:42 by aeid              #+#    #+#             */
/*   Updated: 2024/10/09 18:05:20 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.Class.hpp"

#include <iostream>

Contact::Contact(void) {	
	return;
}

Contact::~Contact(void) {
	return;
}

void Contact::setfield(std::string& input, Fields field)
{
	if (field == FIRSTNAME)
		_FirstName = input;
	else if (field == LASTNAME)
		_LastName = input;
	else if (field == NICKNAME)
		_NickName = input;
	else if (field == PHONENUM)
		_PhoneNum = input;
	else if (field == DARKESTSECRET)
		_DarkestSecret = input;
	else if (field == UNDERWEAR)
		_Underwear = input;
}

// void Contact::ClearObject(void)
// {
// 	this->_FirstName.clear();
// 	this->_LastName.clear();
// 	this->_NickName.clear();
// 	this->_PhoneNum.clear();
// 	this->_DarkestSecret.clear();
// 	this->_Underwear.clear();
// }

std::string Contact::getfield(Fields field)
{
	if (field == FIRSTNAME)
		return this->_FirstName;
	else if (field == LASTNAME)
		return this->_LastName;
	else if (field == NICKNAME)
		return this->_NickName;
	else if (field == PHONENUM)
		return this->_PhoneNum;
	else if (field == DARKESTSECRET)
		return this->_DarkestSecret;
	else
		return this->_Underwear;
}

