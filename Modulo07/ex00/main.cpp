/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:08:29 by aeid              #+#    #+#             */
/*   Updated: 2024/12/20 17:03:30 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "./inc/whatever.hpp"

int main () {
    const std::string color = "\033[1;34m";
    const std::string red = "\033[1;31m";
    const std::string reset = "\033[0m";

    std::cout << red << std::setfill('=') << std::setw(30) << "" << reset << std::endl;
    std::cout << std::setfill(' ');
    //test swap
    {
        std::cout << red << "Testing swap" << reset << std::endl;
        int a = 2;
        int b = 3;
        std::cout << "Default: a = " << a << " b = " << b << std::endl;
        swap(a, b);   
        std::cout << "Swapped: a = " << a << " b = " << b << std::endl;
    }
    std::cout << red << std::setfill('=') << std::setw(30) << "" << reset << std::endl;
    std::cout << std::setfill(' ');
    //test min
    {
        std::cout << red << "Testing min" << reset << std::endl;
        int a = 2;
        int b = 3;
        std::cout << "Default: a = " << a << " b = " << b << std::endl;
        std::cout << "min: " << min(a, b) << std::endl;
        std::cout << color << "Testing min with same values" << reset << std::endl;
        int c = 3;
        int d = 3;
        std::cout << "Default: c = " << c << " d = " << d << std::endl;
        std::cout << "min: " << min(c, d) << std::endl;
        std::cout << color << "Testing min with different types" << reset << std::endl;
        int e = 3;
        float f = 3.5;
        std::cout << "Default: e = " << e << " f = " << f << std::endl;
        std::cout << "min: " << min(e, f) << std::endl;
    }
    std::cout << red << std::setfill('=') << std::setw(30) << "" << reset << std::endl;
    std::cout << std::setfill(' ');
    //test max
    {
        std::cout << red << "Testing max" << reset << std::endl;
        int a = 2;
        int b = 3;
        std::cout << "Default: a = " << a << " b = " << b << std::endl;
        std::cout << "max: " << max(a, b) << std::endl;
        std::cout << color << "Testing max with same values" << reset << std::endl;
        int c = 3;
        int d = 3;
        std::cout << "Default: c = " << c << " d = " << d << std::endl;
        std::cout << "max: " << max(c, d) << std::endl;
        std::cout << color << "Testing max with different types" << reset << std::endl;
        int e = 3;
        float f = 3.5;
        std::cout << "Default: e = " << e << " f = " << f << std::endl;
        std::cout << "max: " << max(e, f) << std::endl;
    }
    std::cout << red << std::setfill('=') << std::setw(30) << "" << reset << std::endl;
    std::cout << std::setfill(' ');
    // test in PDF
    {
        std::cout << red << "Test PDF and more" << reset << std::endl;
        int a = 2;
        int b = 3;

        std::cout << "Before swap" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << min(a, b) << std::endl;
        std::cout << "max(a, b) = " << max(a, b) << std::endl;

        swap(a, b);

        std::cout << "After swap" << std::endl;
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min(a, b) = " << min(a, b) << std::endl;
        std::cout << "max(a, b) = " << max(a, b) << std::endl;

        std::cout << "example with strings" << std::endl;

        std::string c = "chaine1";
        std::string d = "chaine2";

        std::cout << "Before swap" << std::endl;
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min(c, d) = " << min(c, d) << std::endl;
        std::cout << "max(c, d) = " << max(c, d) << std::endl;

        swap(c, d);

        std::cout << "After swap" << std::endl;
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min(c, d) = " << min(c, d) << std::endl;
        std::cout << "max(c, d) = " << max(c, d) << std::endl;

    }
}