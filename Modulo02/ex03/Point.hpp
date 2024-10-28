/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:54:56 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 13:41:27 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point {

  public:
    
    Point(void);
    Point(const float x, const float y);
    Point(const Point &src);
    ~Point(void);

    Point & operator=(const Point &src);

    const Fixed get_x() const;
    const Fixed get_y() const;
    
  private:
    const Fixed _x;
    const Fixed _y;
};

std::ostream & operator<<(std::ostream &o, const Point &src);
#endif