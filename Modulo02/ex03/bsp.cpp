/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:45:35 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 14:15:22 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include "Point.hpp"

Fixed get_denominator(Point const a, Point const b, Point const c) {
    
    Fixed denominator = ((b.get_y() - c.get_y()) * (a.get_x() - c.get_x())) + ((c.get_x() - b.get_x()) * (a.get_y() - c.get_y()));
    return denominator ;
}

Fixed get_alpha(Point const b, Point const c, Point const point) {
    
    Fixed alpha = ((b.get_y() - c.get_y()) * (point.get_x() - c.get_x())) + ((c.get_x() - b.get_x()) * (point.get_y() - c.get_y()));
    return alpha ;
}

Fixed get_beta(Point const a, Point const c, Point const point) {
    
    Fixed beta = ((c.get_y() - a.get_y()) * (point.get_x() - c.get_x())) + ((a.get_x() - c.get_x()) * (point.get_y() - c.get_y()));
    return beta ;
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed denominator = get_denominator(a, b, c);
    Fixed alpha = get_alpha(b, c, point) / denominator;
    Fixed beta = get_beta(a, c, point) / denominator;
    Fixed gamma = Fixed(1.0f) - alpha - beta;

    if (alpha >= 0 && beta >= 0 && gamma >= 0)
        return true;
    return false ;
}
