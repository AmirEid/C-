/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:53:15 by aeid              #+#    #+#             */
/*   Updated: 2024/11/07 17:21:02 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {

    public:
        Brain();
        ~Brain();
        Brain(const Brain &src);
        Brain & operator=(const Brain &src);
    private:
        std::string _ideas[100];
};

# endif