/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:34:30 by isromero          #+#    #+#             */
/*   Updated: 2024/04/13 13:37:47 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string replaceContent(std::string &content, std::string const &s1, std::string const &s2)
{
	if (s1.empty())
		return (content);
	size_t index = content.find(s1);
	while (index != std::string::npos)
	{
		content.erase(index, s1.size());
		content.insert(index, s2);
		index = content.find(s1);
	}
	return (content);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}

	std::string const &filename = argv[1];
	std::string const &s1 = argv[2];
	std::string const &s2 = argv[3];

	std::ifstream ifs(filename);
	if (!ifs)
	{
		std::cerr << "Error: Unable to open input file: " << filename << std::endl;
		return (1);
	}
	std::string content;
	std::string line;
	while (std::getline(ifs, line))
	{
		content += line;
		if (!ifs.eof())
			content += "\n";
	}
	ifs.close();

	std::ofstream ofs(filename + ".replace");
	if (!ofs)
	{
		std::cerr << "Unable to open output file." << std::endl;
		return 1;
	}
	std::string const &finalContent = replaceContent(content, s1, s2);
	ofs << finalContent;
	std::cout << "File copied successfully." << std::endl;
	ofs.close();
	return (0);
}
