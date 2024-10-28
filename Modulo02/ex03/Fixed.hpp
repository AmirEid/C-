/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:36:44 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 12:53:24 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define YELLOW "\033[33m"
# define PURPLE "\033[35m"
# define RESET "\033[0m"

class Fixed {

  public:
    Fixed(void);
    Fixed (const int n);
    Fixed (const float n);
    Fixed (const Fixed &src);
    ~Fixed(void);

    Fixed & operator=(const Fixed &src);
    
    bool operator>(const Fixed &src) const;
    bool operator<(const Fixed &src) const;
    bool operator<=(const Fixed &src) const;
    bool operator>=(const Fixed &src) const;
    bool operator==(const Fixed &src) const;
    bool operator!=(const Fixed &src) const;

    Fixed operator+(const Fixed &src) const;
    Fixed operator-(const Fixed &src) const;
    Fixed operator*(const Fixed &src) const;
    Fixed operator/(const Fixed &src) const;

    //pre: increase the value and return the incremented value
    //post: increase the value and return the original value before increment.
    Fixed & operator++(void);
    Fixed operator++(int);
    Fixed & operator--(void);
    Fixed operator--(int);

    static Fixed & min(Fixed & n1, Fixed & n2);
    static const Fixed & min (const Fixed & n1, const Fixed & n2);

    static Fixed & max(Fixed & n1, Fixed & n2);
    static const Fixed & max (const Fixed & n1, const Fixed & n2);

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