/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:42:47 by aeid              #+#    #+#             */
/*   Updated: 2024/10/10 17:29:45 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
void Zombie::setName(std::string name)
{
	this->_name = name;
	return ;
}

Zombie::~Zombie()
{
	return ;
}

void Zombie::announce(int i)
{
	std::cout << this->_name << " " << i + 1 << ": BraiiiiiiinnnzzzZ...🧟" << std::endl;
}

//it is important to have a defualt constructor to be able to create an array of objects
Zombie::Zombie() : _name("")
{
	return ;
}