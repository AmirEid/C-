/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:31:01 by aeid              #+#    #+#             */
/*   Updated: 2024/10/29 20:03:20 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp" 

DiamondTrap::DiamondTrap (std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name) {
    this->_name = name;
    this->ClapTrap::_name = name + "_clap_name";
    FragTrap::_hp = 100;
    ScavTrap::_mana = 50;
    FragTrap::_dmg = 20;
    std::cout << YELLOW << "Diamond Trap : " << this->_name << " appeared!" << RESET << std::endl;
    return ;
}

DiamondTrap::~DiamondTrap() {
    std::cout << YELLOW << "Diamond Trap : " << this->_name << " destroyed!" << RESET << std::endl;
}

void DiamondTrap::whoAmI(void) {
    std::cout << GREEN << "ClapTrap : " << ClapTrap::_name << " DiamondTrap : " << this->_name << RESET << std::endl;
    return ;
}