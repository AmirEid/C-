/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 19:36:11 by aeid              #+#    #+#             */
/*   Updated: 2024/11/08 20:08:38 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"
# include "Ice.hpp"

Ice::Ice() : AMateria("Ice") {
    printer(std::string(MAGENTA) + ICECONST, this->getType());
    return ;
}

Ice::~Ice() {
    printer(std::string(MAGENTA) + ICEDECON, this->getType());
    return ;
}

Ice::Ice(const Ice & src) : AMateria(src) {
    printer(std::string(MAGENTA) + ICECPY, this->getType());
    return ;
}

Ice & Ice::operator=(const Ice & src) {
    if (this != &src)
        AMateria::operator=(src);
    return *this ;
}

AMateria* Ice::clone() const {
    AMateria* ice = new Ice(*this);
    return ice ;
}

void Ice::use(ICharacter & target) {
    std::cout << MAGENTA << "* shoots an ice bolt at " << target.getName() << RESET << std::endl;
    return ;
}