/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:54:44 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 13:42:24 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point() : _x(0), _y(0) {
    return ;
}

Point::Point(const float x, const float y) : _x(Fixed(x)), _y(Fixed(y)) {
    return ;    
}

Point::Point(const Point &src) {
    *this = src;
    return ;
}

Point::~Point(void) {
    return ;
}

Point & Point::operator=(const Point &src) {
    if (this != &src)
    {
        //this->_x = src.get_x(); This cant work, because it is const
        //so i need to create a new one.
        new (this) Point(src.get_x().toFloat(), src.get_y().toFloat());
    }
    return *this ;
}

const Fixed Point::get_x() const {
    return this->_x;
}

const Fixed Point::get_y() const {
    return this->_y;
}

std::ostream & operator<<(std::ostream &o, const Point &src) {
    o << "x : " << src.get_x() << " & y : " << src.get_y() << std::endl;
    return o ;
}