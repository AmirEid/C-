/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 13:56:48 by amireid           #+#    #+#             */
/*   Updated: 2024/12/26 15:35:48 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <exception>
# include <algorithm>

// return error value
template <typename T>
typename T::iterator easyfind(T &container, const int &a)
{
    typename T::iterator it = std::find(container.begin(), container.end(), a);
    if (it == container.end())
        std::cerr << "Element not found" << std::endl;
    return it;
}

//throw an exception here means i should use try an catch in main. 
// class ExceptionNotFound : public std::exception {
//     public:
//         const char* what() const throw() {
//             return "Element not found";
//         }
// };
// template <typename T>
// void easyfind(const T &container, const int &a)
// {
//     typename T::const_iterator it = std::find(container.begin(), container.end(), a);
//     if (it == container.end())
//         throw ExceptionNotFound();
//     std::cout << "Element found in " << *it << std::endl;
// }


# endif