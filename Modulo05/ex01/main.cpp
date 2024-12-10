/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:49:48 by aeid              #+#    #+#             */
/*   Updated: 2024/12/09 22:50:41 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Bureaucrat.hpp"
# include "./includes/Form.hpp"

int main () {
    // Test default constructor
    try {
        Form form1;
        std::cout << form1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test parameterized constructor with valid grades
    try {
        Form form2("Form2", 50, 100);
        std::cout << form2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test parameterized constructor with invalid grades
    // Should throw GradeTooHighException
    try {
        Form form3("Form3", 0, 100);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Should throw GradeTooLowException
    try {
        Form form4("Form4", 50, 151); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test copy constructor
    try {
        Form form5("Form5", 50, 100);
        Form form6 = form5;
        std::cout << form6 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test assignment operator
    try {
        Form form7("Form7", 50, 100);
        Form form8;
        form8 = form7;
        std::cout << form8 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test beSigned method with valid and invalid grades
    // Should succeed
    try {
        Bureaucrat bureaucrat1("Alice", 40);
        Form form9("Form9", 50, 100);
        form9.beSigned(bureaucrat1); 
        std::cout << form9 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Should throw GradeTooLowException
    try {
        Bureaucrat bureaucrat2("Bob", 60);
        Form form10("Form10", 50, 100);
        form10.beSigned(bureaucrat2); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test signForm method in Bureaucrat class
    // Should succeed
    try {
        Bureaucrat bureaucrat3("Charlie", 40);
        Form form11("Form11", 50, 100);
        bureaucrat3.signForm(form11); 
        std::cout << form11 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // Should throw GradeTooLowException
    try {
        Bureaucrat bureaucrat4("Dave", 60);
        Form form12("Form12", 50, 100);
        bureaucrat4.signForm(form12); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Additional test for signForm method
    // Eve signs the form
    // Should print that the form is already signed
    try {
        Bureaucrat bureaucrat5("Eve", 30);
        Form form13("Form13", 40, 100);
        form13.beSigned(bureaucrat5); 
        bureaucrat5.signForm(form13); 
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}