/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:36:51 by aeid              #+#    #+#             */
/*   Updated: 2024/10/27 19:09:48 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed (void) : _value(0) {
    std::cout << "Default constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const int n) : _value(n << _nfraction) {
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed(const float n) : _value(static_cast<int>(roundf(n * (1 << _nfraction)))) {
    std::cout << "Float constructor called" << std::endl;
    return ;
}

Fixed::Fixed (const Fixed &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return ;
}

Fixed::~Fixed (void) {
    std::cout << "Desturctor called" << std::endl;
    return ;
}

Fixed & Fixed::operator=(const Fixed &src) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_value = src.getRawBits();
    return *this ;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value ;
}

void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

float Fixed::toFloat (void) const {
    return static_cast<float>(_value) / (1 << _nfraction);
}

int Fixed::toInt(void) const {
    return _value >> _nfraction;
}

std::ostream & operator<<(std::ostream &o, const Fixed &src) {
    o << src.toFloat();
    return o;
}