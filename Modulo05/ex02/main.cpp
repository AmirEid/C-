/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:49:48 by aeid              #+#    #+#             */
/*   Updated: 2024/12/11 00:48:25 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Bureaucrat.hpp"
# include "./includes/AForm.hpp"
# include "./includes/ShrubberyCreationForm.hpp"
# include "./includes/RobotmyRequestForm.hpp"
# include "./includes/PresidentialPardonForm.hpp"

int main () {
    // Test ShrubberyCreationForm
    std::cout << "---ShrubberyCreationForm---" << std::endl;
    {
    try {
        ShrubberyCreationForm form1;
        std::cout << form1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test parameterized constructor with valid target
    try {
        ShrubberyCreationForm form2("Home");
        std::cout << form2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test copy constructor
    try {
        ShrubberyCreationForm form3("Garden");
        ShrubberyCreationForm form4 = form3;
        std::cout << form4 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test assignment operator
    try {
        ShrubberyCreationForm form5("Park");
        ShrubberyCreationForm form6;
        form6 = form5;
        std::cout << form6 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test beSigned method with valid and invalid grades
    try {
        Bureaucrat bureaucrat1("Alice", 40);
        ShrubberyCreationForm form7("Office");
        form7.beSigned(bureaucrat1); // Should succeed
        std::cout << form7 << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat2("Bob", 150);
        ShrubberyCreationForm form8("School");
        form8.beSigned(bureaucrat2); // Should throw GradeTooLowException
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test execute method with valid and invalid grades
    try {
        Bureaucrat bureaucrat3("Charlie", 40);
        ShrubberyCreationForm form9("Yard");
        form9.beSigned(bureaucrat3);
        form9.execute(bureaucrat3); // Should succeed
        std::cout << "Shrubbery created successfully" << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat bureaucrat4("Dave", 150);
        ShrubberyCreationForm form10("Forest");
        form10.beSigned(bureaucrat4);
        form10.execute(bureaucrat4); // Should throw GradeTooLowException
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Test execute method without signing the form
    try {
        Bureaucrat bureaucrat5("Eve", 40);
        ShrubberyCreationForm form11("Beach");
        form11.execute(bureaucrat5); // Should throw FormNotSignedException
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    }
    std::cout << std::endl;
    std::cout << "---RobotomyRequestForm---" << std::endl;
    // Test RobotomyRequestForm
    {
        try {
            Bureaucrat bureaucrat1("Frank", 40);
            RobotomyRequestForm form1("Target1");
            form1.beSigned(bureaucrat1);
            form1.execute(bureaucrat1); // Should succeed
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            Bureaucrat bureaucrat2("George", 150);
            RobotomyRequestForm form2("Target2");
            form2.beSigned(bureaucrat2);
            form2.execute(bureaucrat2); // Should throw GradeTooLowException
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        try {
            Bureaucrat bureaucrat3("Hannah", 40);
            RobotomyRequestForm form3("Target3");
            form3.execute(bureaucrat3); // Should throw FormNotSignedException
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    // Test executeForm method in Bureaucrat class
        try {
            Bureaucrat bureaucrat4("Ivy", 40);
            RobotomyRequestForm form4("Target4");
            form4.beSigned(bureaucrat4);
            bureaucrat4.executeForm(form4); // Should succeed
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            Bureaucrat bureaucrat5("Jack", 150);
            RobotomyRequestForm form5("Target5");
            form5.beSigned(bureaucrat5);
            bureaucrat5.executeForm(form5); // Should throw GradeTooLowException
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }

        try {
            Bureaucrat bureaucrat6("Kate", 40);
            RobotomyRequestForm form6("Target6");
            bureaucrat6.executeForm(form6); // Should throw FormNotSignedException
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << "---PresidentialPardonForm---" << std::endl;
    // Test PresidentialPardonForm
    {
        try {
            Bureaucrat bureaucrat1("Laura", 5);
            PresidentialPardonForm form1("Target1");
            form1.beSigned(bureaucrat1);
            form1.execute(bureaucrat1); // Should succeed
            std::cout << "Presidential pardon executed successfully" << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}