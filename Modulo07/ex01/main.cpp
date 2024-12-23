/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:22:35 by aeid              #+#    #+#             */
/*   Updated: 2024/12/23 14:17:11 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./inc/iter.hpp"
# include <iostream>

int main() {
    {    
        int array[] = {1, 2, 3, 4, 5};
        iter(array, 5, static_cast <void (*)(int const &)>(&printer));
    }
    std::cout << std::endl;
    {
        char array[] = {'a', 'b', 'c', 'd', 'e'};
        iter(array, 5, static_cast<void (*)(char const &)>(&printer));
    }
    std::cout << std::endl;
    {
        std::string array[] = {"Hello", "World", "42", "is", "awesome"};
        iter(array, 5, static_cast<void (*)(const std::string &)>(&printer));
    }
    {
        int array[] = {1, 2, 3, 4, 5};
        iter(array, 5, addition<int>);
    }
    std::cout << std::endl;
    {
        char array[] = {'a', 'b', 'c', 'd', 'e'};
        iter(array, 5, addition<char>);
    }
}