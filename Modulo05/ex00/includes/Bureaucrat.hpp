/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:50:07 by aeid              #+#    #+#             */
/*   Updated: 2024/12/09 21:15:42 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>


class Bureaucrat {
    private:
        const std::string _name;
        int _grade;
        
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat();
        Bureaucrat &operator=(const Bureaucrat &src);

        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void checkGrade(int grade);

        class GradeTooHighException : public std::exception {
            public:
            virtual const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
            virtual const char *what() const throw();
        };
};
std::ostream &operator<<(std::ostream &out, const Bureaucrat &src);

#endif