/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:59:42 by aeid              #+#    #+#             */
/*   Updated: 2024/10/08 17:26:42 by aeid             ###   ########.fr       */
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

void Contact::ClearObject(void)
{
	_FirstName.clear();
	_LastName.clear();
	_NickName.clear();
	_PhoneNum.clear();
	_DarkestSecret.clear();
	_Underwear.clear();
}

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

