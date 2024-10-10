/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:17:00 by aeid              #+#    #+#             */
/*   Updated: 2024/10/10 18:47:44 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

#include <iostream>
#include <string>
#include <new>
#include "Weapon.hpp"

class HumanA {
	
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		
		void attack() const;
	private:
		std::string _name;
		Weapon &_weapon;
};

#endif