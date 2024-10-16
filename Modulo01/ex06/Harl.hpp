/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:42:00 by amireid           #+#    #+#             */
/*   Updated: 2024/10/16 17:53:55 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl {
  
  public:
    Harl(void);
    ~Harl(void);

    void complain(std::string level);
  private:
    void _debug(void) const;
    void _info(void) const;
    void _warning(void) const;
    void _error(void) const;
        
};

enum Level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    UNKNOWN
};

#endif