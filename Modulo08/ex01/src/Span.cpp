/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:13:28 by amireid           #+#    #+#             */
/*   Updated: 2024/12/27 14:46:48 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Span.hpp"

Span::Span() : _n(0), _vec() {}
Span::~Span() {}
Span::Span(unsigned int n) : _n(n), _vec() {}
Span::Span(const Span &src) : _n(src._n), _vec(src._vec) {}
Span &Span::operator=(const Span &src) {
    if (this != &src) {
        this->_n = src._n;
        this->_vec = src._vec;
    }
    return *this;
}
//debug
void Span::printVector() {
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int Span::shortestSpan() {
    std::vector<int>::iterator it = this->_vec.begin();
    int min = std::abs(*it - *(it + 1));
    if (this->_vec.size() <= 1)
        throw SingleEmpVec();
    else {
        it++;
        for (; it < this->_vec.end(); it++)
        {
            int diff = std::abs(*it - *(it + 1));
            if (diff < min)
                min = diff;
        }
    }
    return min;
}

int Span::longestSpan() {
    std::vector<int>::iterator it = this->_vec.begin();
    int max = std::abs(*it - *(it + 1));
    if (this->_vec.size() <= 1)
        throw SingleEmpVec();
    else {
        it++;
        for (; it < this->_vec.end(); it++)
        {
            int diff = std::abs(*it - *(it + 1));
            if (diff > max)
                max = diff;
        }
    }
    return max;
}

void Span::addNumber(int n) {
    if (this->_vec.size() >= this->_n)
    {
        throw FullVector();
        return ;
    }
    this->_vec.push_back(n);
}

const char* Span::FullVector::what() const throw () {
    return "Error: Vector is full";
}

const char* Span::SingleEmpVec::what() const throw() {
    return "Error: Vector too small";
}