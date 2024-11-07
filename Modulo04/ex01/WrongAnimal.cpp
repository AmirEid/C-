/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:59:26 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 15:26:23 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal (void) : _type("undefined") {
    std::cout << "default constructor initiated" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal (std::string type) : _type(type) {
    std::cout << "string constructor called with this name " << this->_type << std::endl;
    return ;
}

WrongAnimal::~WrongAnimal () {
    std::cout << "destructor called by " << this->_type << std::endl;
    return ;
}

WrongAnimal::WrongAnimal (const WrongAnimal & src) {
    *this = src;
    std::cout << "copier called by " << this->_type << std::endl;
    return ;
}

WrongAnimal & WrongAnimal::operator=(const WrongAnimal & src) {
    if (this != &src)
        this->_type = src.getType();
    return *this;
}

void WrongAnimal::setType (const std::string type) {
    this->_type = type ;
    return ;
}

std::string WrongAnimal::getType() const {
    return this->_type;
}

void WrongAnimal::makeSound() const {
    std::cout << "generic soung" << std::endl;
    return ;
}