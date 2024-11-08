/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:02:43 by aeid              #+#    #+#             */
/*   Updated: 2024/11/08 20:54:58 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(const std::string & name) : _name(name) {
    
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
    printer(std::string(CYAN) + CHARCONST, this->getName());
    return ;
}

Character::Character(const Character & src) : _name(src.getName()) {
    
    for (int i = 0; i < 4; i++)
    {
        if (src._inventory[i])
            this->_inventory[i] = src._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
    printer(std::string(CYAN) + CHARCPY, this->getName());
    return ;
}

Character & Character::operator=(const Character & src) {
    
    if (this != &src)
    {
        this->_name = src.getName() ;
        for (int i = 0; i < 4; i++)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (src._inventory[i])
                this->_inventory[i] = src._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this ;
}

Character::~Character() {

    for (int i = 0; i < 4; i++)
        if (this->_inventory[i])
            delete this->_inventory[i];
    printer(std::string(CYAN) + CHARDECON, this->getName());
    return ;
}

std::string const & Character::getName() const {
    return this->_name ;
}

void Character::equip(AMateria* m) {
    
    for (int i = 0; i < 4; i++)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = m;
            std::cout << this->getName() << "equipped " << m->getType() << std::endl;
            return ;
        }
    }
    std::cout << "Sorry, the inventroy is full for " << this->getName() << std::endl;
    return ;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && !this->_inventory[idx])
    {
        this->_inventory[idx] = NULL;
        std::cout << "Material unequipped" << std::endl;
        return ;
    }
    std::cout << "Invalid idx" << std::endl;
    return ;
}

void Character::use(int idx, ICharacter & target) {
    if (idx >= 0 && idx < 4 && !this->_inventory[idx])
        this->_inventory[idx]->use(target);
    else
        std::cout << "Invalid idx" << std::endl;
    return ;
}

void Character::printer(std::string text, std::string type) const
{
    std::cout << text << type << RESET << std::endl;
    return ;
}
