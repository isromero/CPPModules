/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:34:30 by isromero          #+#    #+#             */
/*   Updated: 2024/05/26 16:23:29 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

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

	std::ifstream ifs(filename.c_str());
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

	std::ofstream ofs((filename + ".replace").c_str());
	if (!ofs)
	{
		std::cerr << "Unable to open output file." << std::endl;
		return 1;
	}
	Sed sed;
	std::string const &finalContent = sed.replaceContent(content, s1, s2);
	ofs << finalContent;
	std::cout << "File copied successfully." << std::endl;
	ofs.close();
	return (0);
}
