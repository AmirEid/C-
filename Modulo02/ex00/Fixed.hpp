/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:36:44 by aeid              #+#    #+#             */
/*   Updated: 2024/10/27 17:30:48 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

  public:
    Fixed(void);
    Fixed (const Fixed &src);
    ~Fixed(void);

    Fixed & operator=(const Fixed &src);

    int getRawBits (void) const;
    void setRawBits(int const raw);
    
  private:
    int _value;
    static const int _nfraction = 8;
};

# endif