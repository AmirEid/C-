/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:08:49 by aeid              #+#    #+#             */
/*   Updated: 2024/12/20 17:46:49 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream>
#define COLOR "\033[1;34m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

template <typename Array, typename ArrayLength, typename Function>
void iter(Array *array, ArrayLength length, Function func) {
    std::cout << RED << "using template one" << RESET << std::endl;
    for (ArrayLength i = 0; i < length; i++)
        func(array[i]);
}

template <typename Value>
void printer(Value const &a) {
    std::cout << RED << "using specialisation template function" << RESET << std::endl;
    std::cout << COLOR << a << RESET << std::endl;
}

// in case i have another version of printer function where it takes different parameter, i will need to 
// cast the function in the main , so the compiler can know which function to use
// cast should be like this for example:
// iter(array, 5, static_cast<void (*)(std::string const &)>(&printer));
// or
// iter(array, 5, static_cast<void (*)(char const &)>(&printer));
// or
// iter(array, 5, static_cast<void (*)(int const &)>(&printer);

#endif