/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:00:45 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:00:46 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void printError(std::string error)
{
	std::cout << error << std::endl;
}

void readInput(std::ifstream &input, std::string &fileContent)
{
	getline(input, fileContent);
	while (!input.eof()) {
		std::string tmp;
		getline(input, tmp);
		fileContent.append("\n");
		fileContent.append(tmp);
	}
}
void writeInput(std::string file, std::string &fileContent)
{
	std::ofstream	output;

	file.append(".replace");
	output.open(file);
	output << fileContent;
	output.close();
}
void replace(std::string file, std::string target, std::string rep)
{
	std::ifstream	input;
	std::string		fileContent;

	input.open(file);
	if (!input.is_open()) 
		return (printError("Error: Cannot open file"));
	readInput(input ,fileContent);
	if (!fileContent[0])
		return (input.close(), printError("Error: empty file"));
	if (!target[0])
		return (input.close(), printError("Error: target not found"));
	std::size_t pos = fileContent.find(target);
	if (pos == std::string::npos)
		return (input.close(), printError("Error: target not found"));
	while (pos != std::string::npos) {
		fileContent.erase(fileContent.begin() + pos, fileContent.begin() + pos + target.size());
		fileContent.insert(pos, rep);
		pos = fileContent.find(target, pos + rep.size());
	}
	input.close();
	writeInput(file, fileContent);
}

int main(int ac, char **av)
{
	if (ac == 4) replace(av[1], av[2], av[3]);
	return (0);
}
