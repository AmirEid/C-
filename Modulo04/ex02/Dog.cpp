/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:11:39 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 17:32:38 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
    _brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
    return ;
}

Dog::~Dog() {
    delete _brain;
    std::cout << "Dog destructor called" << std::endl;
    return ;
}

Dog::Dog(const Dog & src) : Animal(src) {
    _brain =  new Brain(*src._brain);
    std::cout << "Dog copier called" << std::endl;
    return ;
}

Dog & Dog::operator=(const Dog & src) {
    if (this != &src) {
        Animal::operator=(src);
        delete _brain;
        _brain = new Brain(*src._brain);
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Dog: HawHaw" << std::endl;
    return ;
}
