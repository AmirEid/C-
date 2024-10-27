/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:25:18 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 00:55:57 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

int main ()
{
    ClapTrap Ninja("Ninja");
    ClapTrap Samurai("Samurai");
    Ninja.set_dmg_value(5);
    std::cout << "Ninja damage: " << Ninja.get_dmg_value() << std::endl;
    Ninja.attack("Samurai");
    std::cout << "Ninja mana: " << Ninja.get_mana_value() << std::endl;
    Samurai.takeDamage(Ninja.get_dmg_value());
    std::cout << "Samurai hp: " << Samurai.get_hp_value() << std::endl;
    
    return 0;
}