/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:28:26 by aeid              #+#    #+#             */
/*   Updated: 2024/12/16 17:42:39 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ScalarConverter.hpp"

int main (int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        exit (1);
    }
    try {
        ScalarConverter::convert(argv[1]);
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;    
    }
}

// first step: I need to know what kind of string I am receiving. 
// is it a char or int or float or double. or nan stuff.
// to test: i need to pass a char ch = 5, and then check the output  of the program. 
///////////////(i need enum for this and a switch func to print)//////////////////
// after finding out i need to pass it to the convert function that prints the conversion. 
//each of the (char int float double) will have a line inside that makes the conversion