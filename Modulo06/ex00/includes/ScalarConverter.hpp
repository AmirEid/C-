/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 22:43:51 by aeid              #+#    #+#             */
/*   Updated: 2024/12/15 23:12:54 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>

# define MAX_INT std::numeric_limits<int>::max()
# define MIN_INT std::numeric_limits<int>::min()
# define MAX_FLOAT std::numeric_limits<float>::max()
# define MIN_FLOAT std::numeric_limits<float>::min()
# define MAX_DOUBLE std::numeric_limits<double>::max()
# define MIN_DOUBLE std::numeric_limits<double>::min()

class ScalarConverter {
      public:
        static void convert(const std::string &literal);
};

#endif