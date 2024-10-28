/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:19:15 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 20:45:37 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
    this->_hp = 100;
    this->_mana = 50;
    this->_dmg = 20;
    std::cout << YELLOW << "Robot : " << this->_name << " appeared!" << RESET << std::endl;
    return ;
}

ScavTrap::~ScavTrap() {
    std::cout << YELLOW << "Robot: " << this->_name << " disappeared!" << RESET << std::endl;
    return ;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->_mana > 0 && this->_hp > 0) {
        --this->_mana;
        std::cout << RED << "Robot : " << this->_name << " attacks : " << target << ", causing " << this->_dmg << " damage!" << RESET << std::endl;
    }
    else if (this->_mana <= 0)
        std::cout << "Robot : " << this->_name << " is out of mana!" << std::endl;
    else
        std::cout << "Robot : " << this->_name << " is dead!" << std::endl;
    return ;
}

void ScavTrap::guardGate() {
    std::cout << GREEN << "Robot is now in Gate keeper mode" << RESET << std::endl;
    return ;
}

ScavTrap::ScavTrap() {
    std::cout << "Private constructor called" << std::endl;
    return ;
}