/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:36:51 by aeid              #+#    #+#             */
/*   Updated: 2024/10/27 20:33:59 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed (void) : _value(0) {
    return ;
}

Fixed::Fixed(const int n) : _value(n << _nfraction) {
    return ;
}

Fixed::Fixed(const float n) : _value(static_cast<int>(roundf(n * (1 << _nfraction)))) {
    return ;
}

Fixed::Fixed (const Fixed &src) {
    *this = src;
    return ;
}

Fixed::~Fixed (void) {
    return ;
}

Fixed & Fixed::operator=(const Fixed &src) {
    if (this != &src)
        this->_value = src.getRawBits();
    return *this ;
}

int Fixed::getRawBits(void) const {
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
/// comparison operators///
bool Fixed::operator>(const Fixed &src) const {
    if (this->_value > src._value)
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &src) const {
    if (this->_value >= src._value)
        return true;
    return false;
}

bool Fixed::operator<(const Fixed &src) const {
    if (this->_value < src._value)
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &src) const {
    if (this->_value <= src._value)
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &src) const {
    if (this->_value == src._value)
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &src) const {
    if (this->_value != src._value)
        return true;
    return false;
}

///arithmetic operators///

Fixed Fixed::operator+(const Fixed &src) const {
    Fixed res;
    res.setRawBits(this->getRawBits() + src.getRawBits());
    return res;
}

Fixed Fixed::operator-(const Fixed &src) const {
    Fixed res;
    res.setRawBits(this->getRawBits() - src.getRawBits());
    return res;
}

Fixed Fixed::operator*(const Fixed &src) const {
    Fixed res;
    res.setRawBits((this->getRawBits()) * (src.getRawBits()) >> _nfraction);
    return res;
}

Fixed Fixed::operator/(const Fixed &src) const {
    if (src.getRawBits() == 0)
        throw std::logic_error("ERROR, You cant divide by zero!");
    return Fixed(this->toFloat() / src.toFloat());
}

/// post and pre increment///

Fixed & Fixed::operator++() {
    ++this->_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    ++this->_value;
    return temp;
}

Fixed & Fixed::operator--() {
    --this->_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp (*this);
    --this->_value;
    return temp;
}

/// minimum and maximum 

Fixed & Fixed::min(Fixed & n1, Fixed & n2) {
    if (n1 > n2)
        return n2;
    return n1 ;
}

const Fixed & Fixed::min(const Fixed & n1, const Fixed & n2) {
    if (n1 > n2)
        return n2;
    return n1 ;
}

Fixed & Fixed::max(Fixed & n1, Fixed & n2) {
    if (n1 > n2)
        return n1;
    return n2 ;
}

const Fixed & Fixed::max(const Fixed & n1, const Fixed & n2) {
    if (n1 > n2)
        return n1;
    return n2 ;
}
