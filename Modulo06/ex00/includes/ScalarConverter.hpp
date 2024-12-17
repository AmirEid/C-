/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:43:51 by aeid              #+#    #+#             */
/*   Updated: 2024/12/17 19:39:51 by aeid             ###   ########.fr       */
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
#include <iomanip>

# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT -std::numeric_limits<int>::max()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_FLOAT -std::numeric_limits<float>::max()
# define MAX_DOUBLE std::numeric_limits<double>::max()
# define MIN_DOUBLE -std::numeric_limits<double>::max()
# define MAX_CHAR std::numeric_limits<char>::max()
# define MIN_CHAR std::numeric_limits<char>::min()

class ScalarConverter {
      public:
        static void convert(const std::string &literal);
        
      private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter &operator=(const ScalarConverter &other);
        static bool checkInput(const std::string &literal);
        static void charPrinter(double d);
        static void intPrinter(double d);
        static void floatPrinter(double d);
        static void doublePrinter(double d);
        // static void printerFunction(Type type); //Debug function
        static bool containsAlpha(const std::string &literal);
  
};

#endif