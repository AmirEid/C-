/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:25:23 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 00:51:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CLAPTRAPP_HPP
# define CLAPTRAPP_HPP

# include <iostream>
# include <string>

# define HEALTH 10
# define MANA 10
# define DMG 0
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define PURPLE "\033[35m"
# define RESET "\033[0m"

class ClapTrap {
  
  public:
    
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &src);
    ~ClapTrap();
    ClapTrap & operator=(const ClapTrap &src);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    // void beRepaired(unsigned int amount);

    int get_hp_value() const;
    int get_mana_value() const;
    int get_dmg_value() const;
    void set_hp_value(unsigned int hp);
    void set_mana_value(unsigned int mana);
    void set_dmg_value(unsigned int dmg);
    
  private:
  
    std::string _name;
    unsigned int _hp;
    unsigned int _mana;
    unsigned int _dmg;
};

#endif