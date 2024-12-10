/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:40:51 by aeid              #+#    #+#             */
/*   Updated: 2024/12/11 00:46:33 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default Target") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)  {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
    AForm::operator=(src);
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
    if (!this->getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    
    std::cout <<  _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}