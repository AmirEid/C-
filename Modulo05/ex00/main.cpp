/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:49:48 by aeid              #+#    #+#             */
/*   Updated: 2024/12/09 21:19:46 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Bureaucrat.hpp"

int main () {
    // Should throw GradeTooHighException
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade(); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Should throw GradeTooLowException
    try {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        b2.decrementGrade(); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Working example
    try {
        Bureaucrat b3("Charlie", 75);
        std::cout << b3 << std::endl;
        b3.incrementGrade();
        std::cout << b3 << std::endl;
        b3.decrementGrade();
        std::cout << b3 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Should throw GradeTooHighException
    try {
        Bureaucrat b4("Dave", 0); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Should throw GradeTooLowException
    try {
        Bureaucrat b5("Eve", 151); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Copy constructor
    try {
        Bureaucrat b6("Frank", 100);
        Bureaucrat b7 = b6; 
        std::cout << b7 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Assignment operator
    try {
        Bureaucrat b8("Grace", 50);
        Bureaucrat b9("Hank", 60);
        b9 = b8; 
        std::cout << b9 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Test for the redirect operator
    try {
        Bureaucrat b10("Ivy", 42);
        std::cout << "Testing operator<<: " << b10 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}