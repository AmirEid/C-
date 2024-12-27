/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:41:57 by amireid           #+#    #+#             */
/*   Updated: 2024/12/27 17:09:20 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/MutantStack.hpp"

template < typename T >
MutantStack<T>::MutantStack() : std::stack<T>() {}

template < typename T >
MutantStack<T>::~MutantStack() {}

template < typename T >
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {}

template < typename T >
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
    if (this != &src)
        std::stack<T>::operator=(src);
    return *this;
}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::begin() {return std::stack<T>::c.begin();}

template < typename T >
typename MutantStack<T>::iterator MutantStack<T>::end() {return std::stack<T>::c.end();}

template < typename T >
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {return std::stack<T>::c.begin();}

template < typename T >
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {return std::stack<T>::c.end();}

template < typename T >
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {return std::stack<T>::c.rbegin();}

template < typename T >
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {return std::stack<T>::c.rend();}

template < typename T >
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {return std::stack<T>::c.rbegin();}

template < typename T >
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {return std::stack<T>::c.rend();}