/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:43:51 by aeid              #+#    #+#             */
/*   Updated: 2024/12/16 18:08:40 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <exception>
#include <cstdlib>
#include <algorithm>
#include <cctype>

# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()

class ScalarConverter {
      public:
        enum Type {
            CHAR,
            INT,
            FLOAT,
            DOUBLE,
            PSEUDO
        };
        
        static void convert(const std::string &literal);
        
      private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        static Type getType(const std::string &literal);
        // static void printChar(Type type, const std::string &literal);
        // static void printInt(Type type, const std::string &literal);
        // static void printFloat(Type type, const std::string &literal);
        // static void printDouble(Type type, const std::string &literal);
        static void printerFunction(Type type);
        static bool containsAlpha(const std::string &literal);
  
};

#endif