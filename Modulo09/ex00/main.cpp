/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:25:53 by amireid           #+#    #+#             */ 
/*   Updated: 2024/12/29 14:30:10 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//the program output is the vlue of a  certain amount of bitcoint on a date

# include "./inc/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << RED << "Error: invalid number of arguments" << RESET << std::endl;
        exit (1);
    }
    BitcoinExchange input_file(argv[1]);

    return (0);
}