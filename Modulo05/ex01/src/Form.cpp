/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:06:32 by aeid              #+#    #+#             */
/*   Updated: 2024/12/09 22:34:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}
Form::Form(const Form &src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {}
Form::~Form() {}
Form::Form(std::string name, int gradeTosign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeTosign), _gradeToExecute(gradeToExecute) {
    checkGrade(gradeTosign);
    checkGrade(gradeToExecute);
}
Form &Form::operator=(const Form &src) {
    if (this != &src) {
        _signed = src.getSigned();
    }
    return (*this);
}

std::string Form::getName() const {
    return (this->_name);
}

bool Form::getSigned() const {
    return (this->_signed);
}

int Form::getGradeToSign() const {
    return (this->_gradeToSign);
}

int Form::getGradeToExecute() const {
    return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->getGradeToSign()) {
        throw Form::GradeTooLowException();
    } else if (this->getSigned() == false) {
        _signed = true;
    } else {
        std::cout << "Form is already signed" << std::endl;
    }
}

void Form::checkGrade(int grade) {
    if (grade < 1) {
        throw Form::GradeTooHighException();
    } else if (grade > 150) {
        throw Form::GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Form &src) {
    out << "Form: " << src.getName() << " is: " << (src.getSigned() ? "signed" : "not signed") << std::endl;
    out << "Grade to sign: " << src.getGradeToSign() << std::endl;
    out << "Grade to execute: " << src.getGradeToExecute() << std::endl;
    return (out);
}