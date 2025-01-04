/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:05:01 by amireid           #+#    #+#             */
/*   Updated: 2025/01/04 13:05:32 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/RPN.hpp"

void RPN::_check_number_of_operands(std::string input) {
    int operands = 0;
    int operators = 0;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == ' ')
            continue;
        if (input[i] >= '0' && input[i] <= '9') {
            operands++;
            while (input[i] >= '0' && input[i] <= '9')
                i++;
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
            operators++;
    }
    if (operands < operators + 1)
        throw SyntaxError("Error: invalid number of operands or operations");
}

RPN::RPN(std::string input) : _stack() {
    try {
        if (input.empty() || input.find_first_not_of(' ') == std::string::npos)
            throw SyntaxError("Error: invalid arguments");
        _check_number_of_operands(input);
    } catch (SyntaxError &e) {
        std::cerr << RED << e.what() << RESET << std::endl;
        return ;
    }
    std::istringstream iss(input);
    while (iss >> input) {
        try {
            if (input == "+" || input == "-" || input == "*" || input == "/")
            {
                int a = _stack.top();
                _stack.pop();
                int b = _stack.top();
                _stack.pop();
                if (input == "+")
                    _stack.push(a + b);
                else if (input == "-")
                    _stack.push(b - a);
                else if (input == "*")
                    _stack.push(a * b);
                else if (input == "/") {
                    if (a == 0)
                        throw SyntaxError("Syntax error");
                    _stack.push(b / a);
                }
                continue;
            }
            size_t e = 0;
            int i = std::stoi(input, &e);
            if (e != input.length() || i > 9)
                throw SyntaxError("Error: invalid operand " + input);
            _stack.push(i);
            if (iss.eof() && _stack.size() != 1)
                throw SyntaxError("Error: invalid number of operands");
        } catch (std::invalid_argument &e) {
            std::cerr << RED << "Error: invalid argument" << RESET << std::endl;
            return ;
        } catch (std::out_of_range &e) {
            std::cerr << RED << "Error: out of range" << RESET << std::endl;
            return ;
        } catch (SyntaxError &e) {
            std::cerr << RED << e.what() << RESET << std::endl;
            return ;
        }}
        std::cout << _stack.top() << std::endl;
}

RPN::RPN() : _stack() {}
RPN::~RPN() {}
RPN::RPN(const RPN &src) : _stack(src._stack) {}
RPN &RPN::operator=(const RPN &src) {
    if (this != &src)
        this->_stack = src._stack;
    return *this;
}

RPN::SyntaxError::SyntaxError(std::string msg) : _msg(msg) {}
RPN::SyntaxError::~SyntaxError() throw() {}
const char *RPN::SyntaxError::what() const throw() {return _msg.c_str();}