/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:06:50 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 23:34:10 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"
# include "Cure.hpp"

Cure::Cure() : AMateria("Cure") {
    printer(std::string(BLUE) + CURECONST, this->getType());
    return ;
}

Cure::~Cure() {
    printer(std::string(BLUE) + CUREDECONT, this->getType());
    return ;
}

Cure::Cure(const Cure & src) : AMateria(src) {
    printer(std::string(BLUE) + CURECOPYCONST, this->getType());
    return ;
}

Cure & Cure::operator=(const Cure & src) {
    if (this != &src)
        AMateria::operator=(src);
    return *this;
}

AMateria* Cure::clone() const {
    Cure *AMateria = new Cure(*this);
    return AMateria;
}

void Cure::use(ICharacter & target) {
    std::cout << BLUE << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}