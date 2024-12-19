/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:02:42 by aeid              #+#    #+#             */
/*   Updated: 2024/12/19 16:08:07 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/Serialization.hpp"
# include "../includes/DataStructure.hpp"

Serialization::Serialization() {}
Serialization::~Serialization() {}
Serialization::Serialization(Serialization const &src) { *this = src; }
Serialization &Serialization::operator=(Serialization const &src) { (void)src; return *this; }

uintptr_t Serialization::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serialization::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}