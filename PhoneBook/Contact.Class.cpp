/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:59:42 by aeid              #+#    #+#             */
/*   Updated: 2024/10/07 22:25:37 by aeid             ###   ########.fr       */
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

