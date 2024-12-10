/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreation.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:29:02 by aeid              #+#    #+#             */
/*   Updated: 2024/12/11 00:11:27 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery", 145, 137), _target("Default Target") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
    if (this != &src) {
        AForm::operator=(src);
        _target = src._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::ofstream file((_target + "_shrubbery").c_str());
    if (file.is_open()){
        file << "      &&&        " << std::endl;
        file << "     &&&&&       " << std::endl;
        file << "    &&&&&&&      " << std::endl;
        file << "   &&&&&&&&&     " << std::endl;
        file << "  &&&&&&&&&&&    " << std::endl;
        file << "      |||        " << std::endl;
        file << "      |||        " << std::endl;
        file << "      |||        " << std::endl;
        file << "______|||________" << std::endl;
        file.close();
    } else {
        std::cerr << "Error opening file" << std::endl;
    }
}