/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:06:32 by aeid              #+#    #+#             */
/*   Updated: 2024/12/10 23:47:58 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}
AForm::AForm(const AForm &src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {}
AForm::~AForm() {}
AForm::AForm(std::string name, int gradeTosign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeTosign), _gradeToExecute(gradeToExecute) {
    checkGrade(gradeTosign);
    checkGrade(gradeToExecute);
}
AForm &AForm::operator=(const AForm &src) {
    if (this != &src) {
        _signed = src.getSigned();
    }
    return (*this);
}

std::string AForm::getName() const {
    return (this->_name);
}

bool AForm::getSigned() const {
    return (this->_signed);
}

int AForm::getGradeToSign() const {
    return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const {
    return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > this->getGradeToSign()) {
        throw AForm::GradeTooLowException();
    } else if (this->getSigned() == false) {
        _signed = true;
    } else {
        std::cout << "Form is already signed" << std::endl;
    }
}

void AForm::checkGrade(int grade) {
    if (grade < 1) {
        throw AForm::GradeTooHighException();
    } else if (grade > 150) {
        throw AForm::GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

const char *AForm::FormNotSignedException::what() const throw() {
    return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &out, const AForm &src) {
    out << "Form: " << src.getName() << " is: " << (src.getSigned() ? "signed" : "not signed") << std::endl;
    out << "Grade to sign: " << src.getGradeToSign() << std::endl;
    out << "Grade to execute: " << src.getGradeToExecute() << std::endl;
    return (out);
}