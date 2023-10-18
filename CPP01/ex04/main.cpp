#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::ofstream	output;
	std::ifstream	input;
	std::string		fileContent;

	if (ac == 4) {
		input.open(std::string(av[1]));
		if (!input.is_open()) {
			std::cout << "Error: file not found" << std::endl;
			return (0);
		}
		getline(input, fileContent);
		std::string tmp;
		while (!input.eof()) {
			getline(input, tmp);
			fileContent.append("\n");
			fileContent.append(tmp);
		}
		if (av[2][0] != '\0') {
			int pos = fileContent.find(av[2]);
			std::string target = av[2];
			while (pos != -1) {
				fileContent.erase(fileContent.begin() + pos, fileContent.begin() + pos + target.size());
				fileContent.insert(pos, av[3]);
				pos = fileContent.find(av[2], pos + std::string(av[3]).size());
			}
		}
		input.close();
		std::string out = av[1];
		out.append(".replace");
		output.open(out);
		output << fileContent;
		output.close();
	}
	return (0);
}
