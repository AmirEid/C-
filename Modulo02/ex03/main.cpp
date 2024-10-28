/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:37:02 by aeid              #+#    #+#             */
/*   Updated: 2024/10/28 14:17:14 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
# include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    {
	Point	a(2.02f, 0.83f);
	Point	b(2.66f, 1.68f);
	Point	c(1.24f, 1.91f);
	Point	point(10.07f, 1.46f);
/* PRINT POINTs
    std::cout << "Point a: " << a << std::endl;
    std::cout << "Point b: " << b << std::endl;
    std::cout << "Point c: " << c << std::endl;
    std::cout << "Point p: " << point << std::endl;
*/
	if (bsp(a, b, c, point) == true)
		std::cout << YELLOW << "The point is inside the triangle." << RESET << std::endl;
	else
		std::cout << PURPLE << "The point is outside the triangle." << RESET << std::endl; 
    }
    {
	Point	a(2.02f, 0.83f);
	Point	b(2.66f, 1.68f);
	Point	c(1.24f, 1.91f);
	Point	point(2.07f, 1.46f);
/* PRINT POINTs
    std::cout << "Point a: " << a << std::endl;
    std::cout << "Point b: " << b << std::endl;
    std::cout << "Point c: " << c << std::endl;
    std::cout << "Point p: " << point << std::endl;
*/
	if (bsp(a, b, c, point) == true)
		std::cout << YELLOW << "The point is inside the triangle." << RESET << std::endl;
	else
		std::cout << PURPLE << "The point is outside the triangle." << RESET << std::endl; 
    }
	return 0;
}
