/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:24:30 by aeid              #+#    #+#             */
/*   Updated: 2024/12/23 16:09:18 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &src) : _array(new T[src._size]), _size(src._size) {
    for (unsigned int i = 0; i < src._size; i++)
        _array[i] = src._array[i];
}

template <typename T>
Array<T>::~Array() {
    delete[] _array;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &src) {
    if (this != &src)
    {
        if (_array != NULL)
            delete[] _array;
        _array = new T[src._size];
        _size = src._size;
        for (unsigned int i = 0; i < src._size; i++)
            _array[i] = src._array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw OutOfLimitsException();
    return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

template <typename T>
const char* Array<T>::OutOfLimitsException::what() const throw() {
    return "Error: index out of limits";
}