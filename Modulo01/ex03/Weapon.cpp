/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:15:20 by aeid              #+#    #+#             */
/*   Updated: 2024/10/10 19:46:48 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return ;
}

Weapon::~Weapon()
{
	return ;
}

const std::string& Weapon::getType()
{
	if (this->_type.empty())
		this->_type = "No Weapon";
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	return ;
}