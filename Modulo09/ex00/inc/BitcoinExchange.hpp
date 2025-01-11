/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:57:25 by amireid           #+#    #+#             */
/*   Updated: 2025/01/11 18:41:03 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOINTEXCHANGE_HPP
# define BITCOINTEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <limits>
#include <exception>
#include <iomanip>
#include <cstdlib>


# define DB_PATH "data.csv"

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

class BitcoinExchange
{
    private:
        std::map<std::string, float> _dB;
        void _initDB();
        void _initInput(std::string argv);
        void _parseDate(std::string date);
        void _searchDataBase(std::string date, float value);
        float strToFloat(const std::string &str);
        int strToInt(const std::string &str);
    
    public:
        BitcoinExchange();
        BitcoinExchange(std::string argv);
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);

    class DataBaseError : public std::exception {
        private:
            std::string _msg;
        public:
            DataBaseError(std::string msg);
            ~DataBaseError() throw();
            virtual const char* what() const throw();
    };
    
};


# endif