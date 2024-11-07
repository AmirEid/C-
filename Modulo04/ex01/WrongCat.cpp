/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:10:52 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 15:26:23 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
    std::cout << "default constructor initiated" << std::endl;
    return ;
}

WrongCat::~WrongCat() {
    std::cout << "deconstructor called with this name " << this->_type << std::endl;
    return ; 
}

WrongCat::WrongCat (const WrongCat & src) : WrongAnimal (src) {
    std::cout << "WrongCat copier called" << std::endl;
    return ;
}

WrongCat & WrongCat::operator=(const WrongCat & src) {
    WrongAnimal::operator=(src);
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "WrongCat: Meow Meow" << std::endl;
    return ;
}

