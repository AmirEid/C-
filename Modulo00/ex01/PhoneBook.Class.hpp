/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 23:48:26 by aeid              #+#    #+#             */
/*   Updated: 2024/10/09 19:28:54 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Fields.hpp"
#include "Contact.Class.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <unistd.h>

#define MAX_CONTACTS 8
#define MAX_WIDTH 10

class PhoneBook {
	
	public:
	PhoneBook(void);
	~PhoneBook(void);
	bool checkindex();
	void addcontact(std::string& input, Fields field);
	void search_contact(PhoneBook &phonebook);
	int get_id();

	private:
	void _print_contact(Contact contacts[], int id);
	Contact _contacts[MAX_CONTACTS];
	int _index;
};

void add_function(PhoneBook &phonebook);

#endif