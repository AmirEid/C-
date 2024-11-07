/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:08:54 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 22:56:55 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : _type(type) {
    printer(std::string(YELLOW) + S_CONSTRUCTOR, _type);
    return ;
}

AMateria::AMateria(const AMateria & src) : _type(src.getType()) {
    printer(std::string(YELLOW) + C_CONSTRUCTOR, _type);
    return ;
}

AMateria::~AMateria() {
    printer(std::string(RED) + DCONSTRUCTOR, _type);
    return ;
}

AMateria & AMateria::operator=(const AMateria & src) {
    if (this != &src)
        this->_type = src.getType();
    return *this ;
}

void AMateria::use(ICharacter & target) {
    printer ("Ice: shoots an ice bolt at ", GREEN + target.getName());
    printer ("Cure: heals wounds of ", GREEN + target.getName());
    return ;
}

std::string const & AMateria::getType() const {
    return this->_type;
}

void AMateria::printer(std::string text, std::string type) const
{
    std::cout << text << type << RESET << std::endl;
    return ;
}