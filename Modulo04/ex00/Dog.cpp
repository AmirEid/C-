/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:11:39 by aeid              #+#    #+#             */
/*   Updated: 2024/11/06 18:13:41 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    std::cout << "Dog constructor called" << std::endl;
    return ;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

Dog::Dog(const Dog & src) : Animal(src) {
    std::cout << "Dog copier called" << std::endl;
    return ;
}

Dog & Dog::operator=(const Dog & src) {
    if (this != &src)
        Animal::operator=(src);
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog: HawHaw" << std::endl;
    return ;
}
