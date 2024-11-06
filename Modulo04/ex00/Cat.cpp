/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:05:47 by aeid              #+#    #+#             */
/*   Updated: 2024/11/06 19:20:07 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
    std::cout << "Cat constructor called" << std::endl;
    return ;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    return ;
}

Cat::Cat(const Cat & src) : Animal(src) {
    std::cout << "Cat copier called" << std::endl;
    return ;
}

Cat & Cat::operator=(const Cat & src) {
    Animal::operator=(src);
    return *this ;
}

void Cat::makeSound() const {
    std::cout << "Cat: Meow Meow" << std::endl;
    return ;
}