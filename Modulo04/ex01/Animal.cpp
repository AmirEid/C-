/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:41:54 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 22:50:52 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal(void) : _type("undefigned") {
    std::cout << "default constructor initiated" << std::endl;
    return ;
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << "string constructor called with this name " << this->_type << std::endl;
    return ;
}

Animal::~Animal() {
    std::cout << "destructor called by " << this->_type << std::endl;
    return ;
}

Animal::Animal (const Animal & src) : _type(src.getType()) {
    std::cout << "copier called by " << this->_type << std::endl;
    return ;
}

Animal & Animal::operator=(const Animal &src) {
    if (this != &src)
        this->_type = src.getType();
    return *this ;
}

void Animal::setType(const std::string type) {
    this->_type = type;
    return ;
}

std::string Animal::getType() const {
    return this->_type;
}

void Animal::makeSound() const {
    std::cout << "generic soung" << std::endl;
    return ;
}