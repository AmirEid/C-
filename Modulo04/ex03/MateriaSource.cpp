/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:49:36 by aeid              #+#    #+#             */
/*   Updated: 2024/11/08 21:01:11 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->_template[i] = NULL;
    std::cout << "MateriaSource constructor recorded" << std::endl;
    return ;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        if (this->_template[i])
            delete this->_template[i];
    std::cout << "MateriaSource deconstructor called" << std::endl;
    return ;
}

MateriaSource::MateriaSource(const MateriaSource & src) {
    for (int i = 0; i < 4; i++)
    {
        if (src._template[i])
            this->_template[i] = src._template[i]->clone();
        else
            this->_template[i] = NULL;
    }
    std::cout << "MateriaSource copier called" << std::endl;
    return ;
}

MateriaSource & MateriaSource::operator=(const MateriaSource & src) {
    if (this != &src)
    {
        for (int i = 0; i < 4; i++)
        {    
            if (this->_template[i])
                delete this->_template[i];
            if (src._template[i])
                this->_template[i] = src._template[i]->clone();
            else
                this->_template[i] = NULL;
        }
    }
    return *this ;
}

void MateriaSource::learnMateria(AMateria*) {
    
}