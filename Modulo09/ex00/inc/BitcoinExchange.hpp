/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:57:25 by amireid           #+#    #+#             */
/*   Updated: 2024/12/29 23:27:00 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOINTEXCHANGE_HPP
# define BITCOINTEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <exception>

# define DB_PATH "data.csv"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

class BitcoinExchange
{
    private:
        std::map<std::string, float> _dB;
        void _initDB();
        void _parseDate(std::string date);
    
    public:
        BitcoinExchange();
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