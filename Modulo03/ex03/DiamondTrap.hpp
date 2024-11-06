/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:24:27 by aeid              #+#    #+#             */
/*   Updated: 2024/10/29 17:35:30 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DIAMOND__HPP
# define DIAMOND_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
   
   public:
        DiamondTrap(std::string name);
        ~DiamondTrap(void);
        using ScavTrap::attack;
        void whoAmI(void);
        
   private:
        std::string _name;
        DiamondTrap(void);
} ;

# endif