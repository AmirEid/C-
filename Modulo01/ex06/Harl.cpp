/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:41:31 by amireid           #+#    #+#             */
/*   Updated: 2024/10/16 18:07:08 by aeid             ###   ########.fr       */
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

Level get_level(const std::string level)
{
	if (level == "DEBUG")
		return (DEBUG);
	else if (level == "INFO")
		return (INFO);
	else if (level == "WARNING")
		return (WARNING);
	else if (level == "ERROR")
		return (ERROR);
	else
		return (UNKNOWN);
}

void Harl::_debug(void) const
{
    std::cout << "Harl: Shit, I have to sleep early every day!" << std::endl;
    return ;
}

void Harl::_info(void) const
{
    std::cout << "Harl: Shit I think I can make if I slept only 6 only!" << std::endl;
    return ;
}

void Harl::_warning(void) const
{
    std::cout << "Harl: This job is bad, I don't like it that much anyway!" << std::endl;
    return ;
}

void Harl::_error(void) const
{
    std::cout << "Harl: Harl left his job and ended up unemployed again" << std::endl;
    return ;
}

void Harl::complain(const std::string level)
{
	Level string;
	string = get_level(level);
	if (string != UNKNOWN)
		std::cout << "[ " << level << " ]" << std::endl;
	switch(string)
	{
		case DEBUG:
			_debug();
		case INFO:
			_info();
		case ERROR:
			_error();
		case WARNING:
			_warning();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return;
}