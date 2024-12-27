/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:18:30 by amireid           #+#    #+#             */
/*   Updated: 2024/12/27 14:46:36 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./inc/Span.hpp"

int main () {
    //trial constructors and add number with exceptions.
    {
        Span sp(5);
        std::srand(time(NULL));
        for (int i = 0; i < 4; i++)
        {
            try {
                int number = rand() % 1000;
                sp.addNumber(number);   
            } catch (std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
        sp.addNumber(-900);
        try {
            int i = sp.shortestSpan();
            std::cout << BLUE << "Shortest span is: " << i << RESET << std::endl;
            int j = sp.longestSpan();
            std::cout << GREEN << "Longest span is: " << j << RESET << std::endl;
        }catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        sp.printVector();
        Span sp2(sp);
        sp2.printVector();
        Span sp3 = sp2;
        sp3.printVector();
    }
    
}