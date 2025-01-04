/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:46:54 by amireid           #+#    #+#             */
/*   Updated: 2025/01/04 13:09:24 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include <iostream>
// # include <sstream>
// # include <string>
// # include <vector>

# include "./inc/RPN.hpp"

//argument parsing:
//1- number of operands must be at least 1 more than the number of operators
//2- the first and last characters must be operands
//3- the operands must be separated by operators
//4- the operators must be separated by operands
//5- the operands and operators must be separated by spaces
//6- the operands must be integers
//7- the operators must be +, -, *, / 
//8- the first two operands must be integers
//9- the operands must be less than 10

int main (int argc, char **argv) {
    if (argc != 2 )
        std::cerr << RED << "Error: Invalid number of arguments" << RESET << std::endl;
    else {
        RPN rpn(argv[1]);
    }
}