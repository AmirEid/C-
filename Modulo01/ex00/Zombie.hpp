/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.Class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:42:52 by aeid              #+#    #+#             */
/*   Updated: 2024/10/09 23:51:14 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

#include <iostream>
#include <string>
#include <new>

class Zombie
{
	public:
	Zombie(std::string name);
	~Zombie();

	void announce(void);
	
	private:
		std::string _name;
		
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif