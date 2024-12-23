/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:03:03 by aeid              #+#    #+#             */
/*   Updated: 2024/12/23 16:10:18 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./inc/Array.hpp"

int main () {
    // {    try {char array[5] = {'a', 'b', 'c', 'd', 'e'};
    //     Array<char> arr(5);
    //     for (int i = 0; i < 5; i++)
    //         arr[i] = array[i];
    //     //int i = arr.size();
    //     int i = arr[8];
    //     std::cout << "Array size: " << i << std::endl;
    //     } catch (std::exception &e) {
    //         std::cerr << e.what() << std::endl;
    //     }}
    {
    try {
        int *a = new int();
        std::cout << *a << std::endl;
        delete a;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    }
        {    try {
        char array[5] = {'a', 'b', 'c', 'd', 'e'};
        Array<char> arr(5);
        for (int i = 0; i < 5; i++)
            arr[i] = array[i];
        int i = arr.size();
        std::cout << "Array size: " << i << std::endl;
        Array<char> arr2(arr);
        int size = arr2.size();
        std::cout << "Array size: " << size << std::endl;
        Array<char> arr3 = arr;
        int size2 = arr3.size();
        std::cout << "Array size: " << size2 << std::endl;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }}
}