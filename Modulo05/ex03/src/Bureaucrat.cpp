/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:57:45 by aeid              #+#    #+#             */
/*   Updated: 2024/12/11 00:34:00 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Bureaucrat.hpp"
# include "../includes/AForm.hpp"


Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}
Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName()), _grade(src.getGrade()) {}
Bureaucrat::~Bureaucrat() {}
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
    checkGrade(grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    if (this != &src) {
        _grade = src.getGrade();
    }
    return (*this);
}

std::string Bureaucrat::getName() const {
    return (this->_name);
}

int Bureaucrat::getGrade() const {
    return (this->_grade);
}

void Bureaucrat::incrementGrade() {
    checkGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade() {
    checkGrade(_grade + 1);
    _grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
    out << src.getName() << ", bureaucrat grade " << src.getGrade();
    return (out);
}

void Bureaucrat::checkGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException(); 
}

void Bureaucrat::signForm(AForm &form) {
    checkGrade(_grade);
    if (form.getSigned()){
        std::cout << _name << " cannot sign " << form.getName() << " because it's already signed" << std::endl;
        return;
    } else if (form.getGradeToSign() < _grade) {
        std::cout << _name << " cannot sign " << form.getName() << " because bureaucrat's grade is too low" << std::endl;
        return;
    }
    form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cerr << _name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
