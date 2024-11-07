/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:58:24 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 17:05:25 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
    return ;
}

Brain::~Brain() {
    std::cout << "Brain deconstructor called" << std::endl;
    return ;
}

Brain::Brain (const Brain &src) {
    *this = src;
    return ;
}

Brain & Brain::operator=(const Brain &src) {
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
    return *this;
}