/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DataStructure.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:58:05 by aeid              #+#    #+#             */
/*   Updated: 2024/12/19 16:08:32 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATASTRUCTURE_HPP
#define DATASTRUCTURE_HPP

# include <string>

struct Data {
    int id;
    std::string name;
    std::string email;
    std::string phone;
    std::string birthday;
};

#endif