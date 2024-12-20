/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:22:35 by aeid              #+#    #+#             */
/*   Updated: 2024/12/20 17:36:04 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./inc/iter.hpp"
# include <iostream>

int main() {
    {    
        int array[] = {1, 2, 3, 4, 5};
        iter(array, 5, printer<int>);
    }
    std::cout << std::endl;
    {
        char array[] = {'a', 'b', 'c', 'd', 'e'};
        iter(array, 5, printer<char>);
    }
    std::cout << std::endl;
    {
        std::string array[] = {"Hello", "World", "42", "is", "awesome"};
        iter(array, 5, printer<std::string>);
    }
}