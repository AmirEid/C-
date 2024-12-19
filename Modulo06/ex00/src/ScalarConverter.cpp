/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:05:51 by aeid              #+#    #+#             */
/*   Updated: 2024/12/18 18:15:13 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    if (checkInput(literal))
        exit(1);
    double d = std::atof(literal.c_str());
    charPrinter(d);
    intPrinter(d);
    floatPrinter(d);
    doublePrinter(d);
}

bool ScalarConverter::checkInput(const std::string &literal) {
    std::string pseudo[11] = {"nan", "nanf", "inf", "inff", "+inf", "+inff", "-inf", "-inff", "INFINITY", "+INFINITY", "-INFINITY"};
    if (literal.length() > 1) {
        for (int i = 0; i < 11; i++) {
            if (literal == pseudo[i]) {
                std::cout << "Char: impossible" << std::endl;
                std::cout << "Int: impossible" << std::endl;
                std::cout << "Float: " << std::atof(literal.c_str()) << "f" << std::endl;
                std::cout << "Double: " << std::atof(literal.c_str()) << std::endl;
                return true;
            }
        }
        if (containsAlpha(literal)) {
            std::cout << "Char: impossible" << std::endl;
            std::cout << "Int: impossible" << std::endl;
            std::cout << "Float: impossible" << std::endl;
            std::cout << "Double: impossible" << std::endl;
            return true;
        }
    }
    return (false);
}

void ScalarConverter::charPrinter(double d) {
    if (d > MAX_CHAR || d < MIN_CHAR)
        std::cout << "Char: impossible" << std::endl;
    else if (std::isprint(static_cast<char>(d)))
        std::cout << "Char: '" << static_cast<char>(d) << "'" << std::endl;
    else
        std::cout << "Char: Non displayable" << std::endl;
}

void ScalarConverter::intPrinter(double d) {
    if (d > MAX_INT || d < MIN_INT)
        std::cout << "Int: impossible" << std::endl;
    else
        std::cout << "Int: " << static_cast<int>(d) << std::endl;
}

void ScalarConverter::floatPrinter(double d) {
    if (d > MAX_FLOAT || d < MIN_FLOAT)
        std::cout << std::fixed << std::setprecision(1) << "Float: impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "Float: " << static_cast<float>(d) << "f" << std::endl;
}

void ScalarConverter::doublePrinter(double d) {
    if (d > MAX_DOUBLE || d < MIN_DOUBLE)
        std::cout << std::fixed << std::setprecision(1) << "Double: impossible" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << "Double: " << d << std::endl;
}

bool ScalarConverter::containsAlpha(const std::string &literal) {
    int point = 1;
    int sign = 1;
    for (size_t i = 0; i < literal.length(); i++) {
        if (std::isalpha(literal[i]))
        {
            if (literal[i] == 'f' && i == literal.length() - 1)
                continue;
            return true;
        }
        else if (literal[i] == '.' && point)
            point = 0;
        else if (literal[i] == '-' && sign)
            sign = 0;
        else if (literal[i] == '+' && sign)
            sign = 0;
        else if (!std::isdigit(literal[i]) && (!point || !sign))
            return true;
    }
    return false;
}

//Not needed but I had to do it, so you won't start yappubg about it.
ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    *this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}
////////////////////////////////////////////////////////////////////////////////////
