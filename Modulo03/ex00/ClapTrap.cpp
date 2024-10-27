/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:25:21 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 00:56:28 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap (std::string name) : _name(name), _hp(HEALTH), _mana(MANA), _dmg(DMG) {
    std::cout << YELLOW << "ClapTrap: " << name << " created!" << RESET << std::endl;
    return ;
}

ClapTrap::~ClapTrap () {
    std::cout << YELLOW << "ClapTrap: " << _name << " disappeared!" << RESET << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &src) {
    *this = src;
    return ;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &src) {
    if (this != &src) {
        this->_name = src._name;
        this->_dmg = src.get_dmg_value();
        this->_hp = src.get_hp_value();
        this->_mana = src.get_mana_value();
    }
    return *this;
}

void ClapTrap::attack(const std::string &target)
{
    if (this->_mana > 0 && this->_hp > 0) {
        --this->_mana;
        std::cout << RED << "ClapTrap : " << this->_name << " attacks : " << target << ", causing " << this->_dmg << " damage!" << RESET << std::endl;
    }
    else if (this->_mana <= 0)
        std::cout << "ClapTrap : " << this->_name << " is out of mana!" << std::endl;
    else
        std::cout << "ClapTrap : " << this->_name << " is dead!" << std::endl;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hp > 0)
    {
        if (amount >= this->_hp)
            this->set_hp_value(0);
        else
            this->set_hp_value((this->_hp - amount));
        std::cout << PURPLE << "ClapTrap : " << this->_name << " takes " << amount << " damage!" << RESET << std::endl;
    }
    else
        std::cout << PURPLE << "ClapTrap : " << this->_name << " is dead, try to repair!" << std::endl;
    return ;
}

///getters and setters///
int ClapTrap::get_hp_value() const {
    return this->_hp;
}

int ClapTrap::get_mana_value() const {
    return this->_mana;
}

int ClapTrap::get_dmg_value() const {
    return this->_dmg;
}

void ClapTrap::set_hp_value(unsigned int hp) {
    this->_hp = hp;
}

void ClapTrap::set_mana_value(unsigned int mana) {
    this->_mana = mana;
}

void ClapTrap::set_dmg_value(unsigned int dmg) {
    this->_dmg = dmg;
}