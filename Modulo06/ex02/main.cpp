/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:59:43 by aeid              #+#    #+#             */
/*   Updated: 2024/12/19 17:32:36 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Randomizer.hpp"
# include "./includes/Base.hpp"
# include "./includes/A.hpp"
# include "./includes/B.hpp"
# include "./includes/C.hpp"

int main() {
    Base *base = generate();
    identify(base);
    identify(*base);
    return 0;
}

