/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:04:59 by amireid           #+#    #+#             */
/*   Updated: 2024/12/29 22:41:56 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/BitcoinExchange.hpp"

void BitcoinExchange::_parseDate(std::string date) {
    if (date.length() != 10)
        throw DataBaseError("Error: invalid date at line: " + date);
    int dashes = 0;
    for (int i = 0; i < 10; i++)
        if (date[i] == '-')
            dashes++;
    if (dashes != 2 || date[4] != '-' || date[7] != '-')
        throw DataBaseError("Error: invalid date at line: " + date);
    try {
        std::size_t idx;
        int year = std::stoi(date.substr(0, 4), &idx);
        if (idx != 4 || year < 2009 || year > 2024)
            throw DataBaseError("Error: invalid date at line: " + date);
        int month = std::stoi(date.substr(5, 2), &idx);
        if (idx != 2 || month < 1 || month > 12)
            throw DataBaseError("Error: invalid date at line: " + date);
        int day = std::stoi(date.substr(8, 2), &idx);
        if (idx != 2 || day < 1 || day > 31)
            throw DataBaseError("Error: invalid date at line: " + date);
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            throw DataBaseError("Error: invalid date at line: " + date);
        if (!(day <= 29) && month == 2)
            throw DataBaseError("Error: invalid date at line: " + date);  
    } catch (std::invalid_argument &e) {
        throw DataBaseError("Error: invalid date at line: " + date);
    } catch (std::out_of_range &e) {
        throw DataBaseError("Error: invalid date at line: " + date);
    }
}

void BitcoinExchange::_initDB()
{
    try {
        std::ifstream file(DB_PATH);
        if (!file.is_open() || file.peek() == EOF || !file.good() || file.fail()) {
            throw DataBaseError("Error: invalid file");
        }
        std::string line = "";
        std::getline(file, line, '\n');
        if (line != "date,exchange_rate")
            throw DataBaseError("Error: invalid file header");    
        while (std::getline(file, line, '\n')) {
            size_t pos = line.find(',');
            if (pos == std::string::npos)
                throw DataBaseError("Error: invalid file format at line: " + line);
            try {
                std::string date = line.substr(0, pos);
                _parseDate(date);
                std::string ratez = line.substr(pos + 1);
                std::size_t idx;
                float rate = std::stof(ratez, &idx);
                if (idx != ratez.length() || rate < 0)
                    throw DataBaseError("Error: invalid exchange rate at line: " + line);
                _dB[date] = rate;
            } catch (std::invalid_argument &e) {
                throw DataBaseError("Error: invalid exchange rate at line: " + line);
            } catch (std::out_of_range &e) {
                throw DataBaseError("Error: exceeded limit at line: " + line);
            }
    }
        file.close();    
    } catch (DataBaseError &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
    } 
}

BitcoinExchange::BitcoinExchange() : _dB() {_initDB();}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _dB(other._dB) {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        this->_dB = other._dB;
    return *this;
}

BitcoinExchange::DataBaseError::DataBaseError(std::string msg) : _msg(msg) {}
const char* BitcoinExchange::DataBaseError::what() const throw() { return _msg.c_str();}
BitcoinExchange::DataBaseError::~DataBaseError() throw() {}