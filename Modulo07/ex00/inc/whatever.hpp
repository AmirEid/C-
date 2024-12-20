/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:08:44 by aeid              #+#    #+#             */
/*   Updated: 2024/12/20 16:57:54 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WHATEVER_HPP
# define WHATEVER_HPP

template < typename T, typename U >

void swap(T &a, U &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
//I wanted to use reference but it is better not, if we compare 2 different types such as int and float. so compare by value not reference
template < typename T, typename U >

U const min(T const a, U const b)
{
    return a < b? a : b;
}

template < typename T, typename U >

T const max(T const a, U const b)
{
    return a > b? a : b;
}

# endif