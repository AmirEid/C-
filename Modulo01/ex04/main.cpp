/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeid <aeid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 20:24:10 by aeid              #+#    #+#             */
/*   Updated: 2024/10/20 16:19:27 by aeid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include <new>
# include <fstream>

std::string read_from_file(std::ifstream& file)
{
	std::string line;
	std::string content;
	while (std::getline(file, line))
	{
		content += line;
		if (file.eof())
			break;
		content += "\n";
	}
	return (content);
}

std::string replace_words(std::string& content, std::string s1, std::string s2)
{
	size_t pos = 0;
	size_t prev_pos = 0;
	std::string to_copy = "";
	while((pos = content.find(s1, pos)) != std::string::npos)
	{
		to_copy += content.substr(prev_pos, pos - prev_pos);
		to_copy += s2;
		pos += s1.length();
		prev_pos = pos;
	}
	to_copy += content.substr(prev_pos, content.length() - prev_pos);
	return (to_copy);
}

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	std::ifstream file(argv[1]);
	if(!file.is_open())
	{
		std::cout << "Invalid file" << std::endl;
		return (1);
	}
	if (file.peek() == EOF)
	{
		std::cout << "File is empty" << std::endl;
		file.close();
		return (1);
	}
	std::string content = read_from_file(file);
	std::ofstream new_file((argv[1] + std::string(".replace")).c_str());
	if(!new_file.is_open())
	{
		std::cout << "Error creating new file" << std::endl;
		file.close();
		return (1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string to_copy = replace_words(content, s1, s2);
	new_file << to_copy;
	file.close();
	new_file.close();
}