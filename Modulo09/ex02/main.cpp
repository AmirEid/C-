/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amireid <amireid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 02:34:03 by amireid           #+#    #+#             */
/*   Updated: 2025/01/06 02:53:32 by amireid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << RED << "Invalid number of arguments" << RESET << std::endl;
        return 1;
    }
    std::string input(argv[1]);
    if (input.empty() || input.find_first_not_of("0123456789 ") != std::string::npos || input.find_first_not_of(' ') == std::string::npos) {
        std::cerr << RED << "Error: invalid input" << RESET << std::endl;
        return 1;
    }
    std::vector<int> nums;
    std::stringstream ss(argv[1]);
    int num;
    while (ss >> num) {
        nums.push_back(num);
        if (ss.peek() == ' ') {
            ss.ignore();
        }
    }
    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] <= 0) {
            std::cerr << "Error: Only positive integers are allowed." << std::endl;
            return 1;
        }
    }
    PmergeMe sorter;
    std::cout << "Before: ";
    for (size_t i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    std::vector<int> sorted = sorter.sortVectorWithThreads(nums);
    std::cout << "After: ";
    for (size_t i = 0; i < sorted.size(); i++) {
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
