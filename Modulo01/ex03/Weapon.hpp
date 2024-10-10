/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:14:50 by aeid              #+#    #+#             */
/*   Updated: 2024/10/10 18:24:41 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <iostream>
#include <string>
#include <new>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon();
		
		const std::string& getType();
		void setType(std::string type);
	private:
		std::string _type;
};

#endif