/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:41:31 by amireid           #+#    #+#             */
/*   Updated: 2024/10/11 16:57:14 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

Harl::Harl(void) 
{
  return ;
}

Harl::~Harl(void)
{
    return ;
}

const void _debug(void)
{
    std::cout << "Harl DEBUG: Shit, I have to sleep early every day!" << std::endl;
    return ;
}

const void _info(void)
{
    std::cout << "Harl INFO: Shit I think I can make if I slept only 6 only!" << std::endl;
    return ;
}

const void _warning(void)
{
    std::cout << "Harl WARNING: This job is bad, I don't like it that much anyway!" << std::endl;
    return ;
}

const void _error(void)
{
    std::cout << "Harl ERROR: Harl left his job and ended up unemployed again" << std::endl;
    return ;
}

void complain(std::string level)
{
    
}

