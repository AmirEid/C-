/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:36:44 by aeid              #+#    #+#             */
/*   Updated: 2024/10/27 19:06:52 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

  public:
    Fixed(void);
    Fixed (const int n);
    Fixed (const float n);
    Fixed (const Fixed &src);
    ~Fixed(void);

    Fixed & operator=(const Fixed &src);

    int getRawBits (void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
    
  private:
    int _value;
    static const int _nfraction = 8;
};

std::ostream & operator<<(std::ostream &o, const Fixed &src);

# endif