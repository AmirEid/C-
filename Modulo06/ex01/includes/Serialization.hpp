/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:58:55 by aeid              #+#    #+#             */
/*   Updated: 2024/12/19 16:15:46 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include "DataStructure.hpp"
# include <iostream>

class Data;
typedef unsigned long uintptr_t;

class Serialization {
    private:
        Serialization();
        ~Serialization();
        Serialization(Serialization const &src);
        Serialization &operator=(Serialization const &src);
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif