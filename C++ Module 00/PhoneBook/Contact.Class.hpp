/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:52:12 by aeid              #+#    #+#             */
/*   Updated: 2024/10/08 17:14:44 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include "Fields.hpp"
#include <iostream>
#include <string>

class Contact {
	
public:
	Contact(void);
	~Contact(void);
	void setfield(std::string& input, Fields field);
	void ClearObject(void);
	std::string getfield(Fields field);
private:
	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNum;
	std::string _DarkestSecret;
	std::string _Underwear;
};

#endif