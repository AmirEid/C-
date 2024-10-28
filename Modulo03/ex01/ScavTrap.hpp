/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:19:13 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 20:30:47 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
    
    public :
        ScavTrap(const std::string name);
        ~ScavTrap();
        void attack(const std::string& target);
        void guardGate();

    private :
        ScavTrap();
};

# endif