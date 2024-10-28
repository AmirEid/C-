/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:25:18 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 21:11:21 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

int main ()
{
    ClapTrap Ninja("Ninja");
    ClapTrap Samurai("Samurai");
    
    std::cout << std::endl;
    std::cout << COLOR << "NINJA'S TURN" << RESET << std::endl;
    std::cout << std::endl;
    {
        Ninja.set_dmg_value(5);
        std::cout << "Ninja damage: " << Ninja.get_dmg_value() << std::endl;
        Ninja.attack("Samurai");
        std::cout << "Ninja mana: " << Ninja.get_mana_value() << std::endl;
        Samurai.takeDamage(Ninja.get_dmg_value());
        std::cout << "Samurai hp: " << Samurai.get_hp_value() << std::endl;
        Samurai.beRepaired(4);
        std::cout << "Samurai hp: " << Samurai.get_hp_value() << std::endl;
    }
    std::cout << std::endl;
    std::cout << COLOR << "SAMURAI'S TURN" << RESET << std::endl;
    std::cout << std::endl;
    {
        Samurai.set_dmg_value(6);
        std::cout << "Samurai damage: " << Samurai.get_dmg_value() << std::endl;
        Samurai.attack("Ninja");
        std::cout << "Samurai mana: " << Samurai.get_mana_value() << std::endl;
        Ninja.takeDamage(Samurai.get_dmg_value());
        std::cout << "Ninja hp: " << Ninja.get_hp_value() << std::endl;
        Ninja.beRepaired(3);
        std::cout << "Ninja hp: " << Ninja.get_hp_value() << std::endl;
    }
    std::cout << std::endl;
    std::cout << COLOR << "MAZINGA'S TURN" << RESET << std::endl;
    std::cout << std::endl;
    {
        ScavTrap Robot("Mazinga");
        Samurai.set_dmg_value(20);
        std::cout << "Samurai damage: " << Samurai.get_dmg_value() << std::endl;
        Ninja.set_dmg_value(15);
        std::cout << "Ninja damage: " << Ninja.get_dmg_value() << std::endl;
        Samurai.attack("Mazinga");
        std::cout << "Samurai mana: " << Samurai.get_mana_value() << std::endl;
        Ninja.attack("Mazinga");
        std::cout << "Ninja mana: " << Ninja.get_mana_value() << std::endl;
        Robot.takeDamage((Samurai.get_dmg_value() + Ninja.get_dmg_value()));
        std::cout << "Mazinga hp: " << Robot.get_hp_value() << std::endl;
        Robot.beRepaired(5);
        std::cout << "Robot mana: " << Robot.get_mana_value() << std::endl;
        std::cout << "Mazinga hp: " << Robot.get_hp_value() << std::endl;
        Robot.attack("Samurai");
        std::cout << "Robot mana: " << Robot.get_mana_value() << std::endl;
        Robot.attack("Ninja");
        std::cout << "Robot mana: " << Robot.get_mana_value() << std::endl;
        Samurai.takeDamage(Robot.get_dmg_value());
        std::cout << "Samurai hp: " << Samurai.get_hp_value() << std::endl;
        Ninja.takeDamage(Robot.get_dmg_value());
        std::cout << "Ninja hp: " << Ninja.get_hp_value() << std::endl;
        std::cout << std::endl;
        std::cout << COLOR << "MAZINGA WON!" << RESET << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << COLOR << "GAME OVER" << RESET << std::endl;
    std::cout << std::endl;
    return 0;
}