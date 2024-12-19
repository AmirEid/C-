/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:01:55 by aeid              #+#    #+#             */
/*   Updated: 2024/12/19 16:38:18 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./includes/Serialization.hpp"
# include "./includes/DataStructure.hpp"

int main () {
    ///DATA TEST
    Data *data = new Data();
{    data->id = 42;
    data->name = "John Doe";
    data->email = "ciao@gmail.com";
    data->phone = "1234567890";
    data->birthday = "01/01/1970";
    
    std::cout << "Original PTR Data: " << data << std::endl;
    std::cout << "data id: " << data->id << std::endl;
    uintptr_t serial = Serialization::serialize(data);
    std::cout << "PTR as integers: " << serial << std::endl;
    Data *deserial = Serialization::deserialize(serial);
    std::cout << "Deserialized PTR Data: " << deserial << std::endl;}
    std::cout << std::endl;
    ///normal test
{    int object = 42;
    int *serial = &object;
    std::cout << "object Value: " << object << std::endl;
    std::cout << "object address: " << &object << std::endl;
    std::cout << "object address: " << serial << std::endl;
    uintptr_t serial2 = reinterpret_cast<uintptr_t>(serial);
    std::cout << "PTR as integers: " << serial2 << std::endl;
    unsigned long *deserial = reinterpret_cast<unsigned long *>(serial2);
    std::cout << "Deserialized PTR Value: " << *deserial << std::endl;
    std::cout << "Deserialized PTR address: " << deserial << std::endl;

}
    return 0;
}