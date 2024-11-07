/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:05:47 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 17:27:51 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    _brain = new Brain();
    std::cout << "Cat constructor called" << std::endl;
    return ;
}

Cat::~Cat() {
    delete _brain;
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

Cat::Cat(const Cat & src) : Animal(src) {
    _brain = new Brain(*src._brain);
    std::cout << "Cat copier called" << std::endl;
    return ;
}

Cat & Cat::operator=(const Cat & src) {
    if (this != &src) {
        Animal::operator=(src);
        delete _brain;
        _brain = new Brain(*src._brain);
    }
    return *this ;
}

void Cat::makeSound() const {
    std::cout << "Cat: Meow Meow" << std::endl;
    return ;
}