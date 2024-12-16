/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:05:51 by aeid              #+#    #+#             */
/*   Updated: 2024/12/16 18:14:17 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    Type type = getType(literal);
    printerFunction(type);
}

ScalarConverter::Type ScalarConverter::getType(const std::string &literal) {
    std::string pseudo[11] = {"nan", "nanf", "inf", "inff", "+inf", "+inff", "-inf", "-inff", "INFINITY", "+INFINITY", "-INFINITY"};
    if (literal.find('.') != std::string::npos)
    {
        if (literal.find('f') != std::string::npos)
            return FLOAT;
        if (!containsAlpha(literal))
            return DOUBLE;
    }
    //!std::any_of(literal.begin(), literal.end(), ::isalpha) could use this but cpp 11 is not allowed
    if ((std::atoi(literal.c_str()) != 0 || literal == "0") && !containsAlpha(literal))
        return INT;
    for (int i = 0; i < 11; i++) {
        if (literal == pseudo[i])
            return PSEUDO;
    }
    return CHAR;
}

bool ScalarConverter::containsAlpha(const std::string &literal) {
    for (size_t i = 0; i < literal.length(); i++) {
        if (std::isalpha(literal[i]))
            return true;
    }
    return false;
}
////debug function
void ScalarConverter::printerFunction(Type type) {
    switch (type) {
        case CHAR:
            std::cout << "It is a char" << std::endl;
            break;
        case INT:
            std::cout << "It is an int" << std::endl;
            break;
        case FLOAT:
            std::cout << "It is a float" << std::endl;
            break;
        case DOUBLE:
            std::cout << "It is a double" << std::endl;
            break;
        default:
            std::cout << "It is a pseudo" << std::endl;
            return;
    }
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
