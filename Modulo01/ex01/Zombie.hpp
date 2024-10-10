/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 23:42:52 by aeid              #+#    #+#             */
/*   Updated: 2024/10/10 17:24:04 by aeid             ###   ########.fr       */
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
	Zombie();
	~Zombie();

	void announce(int i);
	void setName(std::string name);
	
	private:
		std::string _name;
		
};

Zombie* zombieHorde(int N, std::string name);

#endif