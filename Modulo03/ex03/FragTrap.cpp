/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:16:29 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 23:31:02 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
# include "ClapTrap.hpp"


FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
    this->_hp = 100;
    this->_mana = 100;
    this->_dmg = 30;
    std::cout << YELLOW << "FragTrap : " << this->_name << " created!" << RESET << std::endl;
    return ;
}

FragTrap::~FragTrap () {
        std::cout << YELLOW << "FragTrap: " << this->_name << " disappeared!" << RESET << std::endl;
    return ;
}

void FragTrap::highFiveGuys() {
    std::cout << GREEN << "FragTrap : " << this->_name << "who is killing who?...high five!" << RESET << std::endl;
    --this->_mana;
    return;
}


FragTrap::FragTrap () {
    std::cout << "Private FragTrap constructor called" << std::endl;
    return ;
}