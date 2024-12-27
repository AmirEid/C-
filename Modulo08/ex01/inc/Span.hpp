/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:52:49 by amireid           #+#    #+#             */
/*   Updated: 2024/12/27 14:43:26 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>
# include <exception>
# include <cstdlib>

#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m" 

class Span {
    private:
        unsigned int _n;
        std::vector<int> _vec;
        
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &src);
        Span &operator=(const Span &src);
        ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        void printVector();

        class SingleEmpVec : public std::exception {
            public:
            virtual const char* what() const throw();
        };
        
        class FullVector : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
};


# endif