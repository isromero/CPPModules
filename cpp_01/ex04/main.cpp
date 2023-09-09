/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isromero <isromero@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:53:23 by isromero          #+#    #+#             */
/*   Updated: 2023/09/09 16:53:23 by isromero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void strReplaceFile(std::ifstream &inFile, std::ofstream &outputFile, const std::string &searchString, const std::string &replaceString)
{
  std::string line;
  std::string output;
  size_t pos = 0;

  while (std::getline(inFile, line))
  {
    pos = line.find(searchString);
    if (pos != std::string::npos)
    {
      for (size_t i = 0; i < pos; ++i)
        output += line[i];
      for (size_t j = 0; j < replaceString.length(); ++j)
        output += replaceString[j];
      size_t traveledLength = searchString.length() + pos;
      for (; traveledLength < line.length(); ++traveledLength)
        output += line[traveledLength];
    }
    else
      output += line;
    output += '\n';
  }
  outputFile << output;
}

int main(int argc, char **argv)
{
  if (argc == 4)
  {
    std::ifstream inFile(argv[1]);
    std::string filenameOutput = argv[1];
    filenameOutput.append(".replace");
    std::ofstream outputFile(filenameOutput.c_str());

    if (!inFile.is_open())
    {
      std::cerr << "Can't open the file" << std::endl;
      return 1;
    }
    strReplaceFile(inFile, outputFile, argv[2], argv[3]);
    inFile.close();
    outputFile.close();
  }
  else
    std::cout << "Usage: <filename> <search> <replace>" << std::endl;
  return 0;
}
