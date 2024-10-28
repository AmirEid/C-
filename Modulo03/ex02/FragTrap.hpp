/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:11:28 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 23:16:11 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
  
  public :
    FragTrap(const std::string name);
    ~FragTrap();
    
    void highFiveGuys(void);
    
  private :
    FragTrap();
};

#endif