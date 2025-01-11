/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:01:50 by amireid           #+#    #+#             */
/*   Updated: 2025/01/11 19:22:07 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stack>
# include <limits>


# define RED "\033[31m"
# define RESET "\033[0m"


class RPN {
    private:
        std::stack<int> _stack;
        void _check_number_of_operands(std::string input);
        RPN();
        int strToInt(const std::string &str);
    
    public:
        RPN(std::string input);
        ~RPN();
        RPN(const RPN &src);
        RPN &operator=(const RPN &src);

    class SyntaxError : public std::exception {
        private:
            std::string _msg;
        public:
        SyntaxError(std::string msg);
        virtual ~SyntaxError() throw();
        virtual const char *what() const throw();
    };
};

# endif