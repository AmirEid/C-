/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:04:59 by amireid           #+#    #+#             */
/*   Updated: 2025/01/11 19:20:59 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/BitcoinExchange.hpp"

float BitcoinExchange::strToFloat(const std::string &str) {
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]) && str[i] != '.')
            throw DataBaseError("Error: invalid exchange rate at line: " + str);
    std::istringstream iss(str);
    float result;
    iss >> result;
    if (iss.fail())
        throw DataBaseError("Error: invalid exchange rate at line: " + str);
    if (result < -std::numeric_limits<float>::max() || result > std::numeric_limits<float>::max())
        throw DataBaseError("Error: exceeded limit at line: " + str);
    return result;
}

int BitcoinExchange::strToInt(const std::string &str) {
    for (size_t i = 0; i < str.length(); i++)
        if (!std::isdigit(str[i]) && str[i] != '.')
            throw DataBaseError("Error: invalid exchange rate at line: " + str);
    std::istringstream iss(str);
    int result;
    iss >> result;
    if (iss.fail())
        throw DataBaseError("Error: invalid exchange rate at line: " + str);
    if (result < -std::numeric_limits<int>::max() || result > std::numeric_limits<int>::max())
        throw DataBaseError("Error: exceeded limit at line: " + str);
    return result;
}

//parse the date to check if it is valid
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
        int year = strToInt(date.substr(0, 4));
        if (year < 2000 || year > 2024)
            throw DataBaseError("Error: invalid date at line: " + date);
        int month = strToInt(date.substr(5, 2));
        if (month < 1 || month > 12)
            throw DataBaseError("Error: invalid date at line: " + date);
        int day = strToInt(date.substr(8, 2));
        if (day < 1 || day > 31)
            throw DataBaseError("Error: invalid date at line: " + date);
        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            throw DataBaseError("Error: invalid date at line: " + date);
        if (!(day <= 29) && month == 2)
            throw DataBaseError("Error: invalid date at line: " + date);  
    } catch (std::invalid_argument &e) {
        throw DataBaseError("Error: invalid date at line: " + date);
    } catch (std::out_of_range &e) {
        throw DataBaseError("Error: invalid date at line: " + date);
}}

//initialize the database from the file
void BitcoinExchange::_initDB()
{
    std::ifstream file(DB_PATH);
    if (!file.is_open() || file.peek() == EOF || !file.good() || file.fail())
        throw DataBaseError("Error: invalid file");
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
            float rate = strToFloat(ratez);
            if (rate < 0)
                throw DataBaseError("Error: invalid exchange rate at line: " + line);
            _dB[date] = rate;
        } catch (std::invalid_argument &e) {
            throw DataBaseError("Error: invalid exchange rate at line: " + line);
        } catch (std::out_of_range &e) {
            throw DataBaseError("Error: exceeded limit at line: " + line);
        } 
        }
    file.close();
    std::cout << GREEN << "Database loaded successfully" << RESET << std::endl;
}

//search the database for the right date
void BitcoinExchange::_searchDataBase(std::string date, float value) {
    std::map<std::string, float>::iterator it = _dB.lower_bound(date);
    if (it == _dB.end() || (it == _dB.begin() && it->first > date))
        std::cout << YELLOW << "No data found for date => " << date << RESET << std::endl;
    else {
        if (it->first > date)
            it--;
        std::cout << std::fixed << std::setprecision(2);
        std::cout << date << " => " << value << " = " << it->second * value << std::endl;     
    }}

//handle the input file that is passed as an argument
void BitcoinExchange::_initInput(std::string argv) {
    std::ifstream file(argv.c_str());
    if (!file.is_open() || file.peek() == EOF || !file.good() || file.fail())
        throw DataBaseError("Error Input file: invalid file " + argv);
    std::string line = "";
    std::getline(file, line, '\n');
    if (line != "date | value")
        throw DataBaseError("Error Input file: invalid file header " + line);
    while (std::getline(file, line, '\n')) {
        size_t pos = line.find('|');
        if (pos == std::string::npos || line[pos + 1] != ' ' || line[pos - 1] != ' ') {
            std::cout << YELLOW << "Bad input at line => " << line << RESET << std::endl;   
            continue;
        }
        try {
            std::string date = line.substr(0, (pos - 1));
            _parseDate(date);
            std::string valuez = line.substr(pos + 2);
            float value = strToFloat(valuez);
            if (value < 0)
                std::cout << YELLOW << "Error: not a positive number at line => " << line << RESET << std::endl;
            else if (value > 1000)
                std::cout << YELLOW << "Error: too large a number at line => " << line << RESET << std::endl;
            else
                _searchDataBase(date, value);
        } catch (std::invalid_argument &e) {
            throw DataBaseError("Error Input file: invalid exchange rate at line: " + line);
        } catch (std::out_of_range &e) {
            throw DataBaseError("Error Input file: exceeded limit at line: " + line);
    }} 
    file.close();
    std::cout << GREEN << "Input file loaded successfully" << RESET << std::endl;
}
    

//Canonical form functions
BitcoinExchange::BitcoinExchange() : _dB() {_initDB();}
BitcoinExchange::BitcoinExchange(std::string argv) : _dB() {
    try {
        if (argv.empty())
            throw DataBaseError("Error: invalid argument");
        _initDB();
        _initInput(argv);
    } catch (DataBaseError &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return ;
    }}

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