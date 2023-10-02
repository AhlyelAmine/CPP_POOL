#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	std::ofstream	output;
	std::ifstream	input;
	std::string		fileContent;

	if (ac == 4) {
		input.open(av[1]);
		getline(input, fileContent);
		std::string tmp;
		while (!input.eof()) {
			getline(input, tmp);
			fileContent.append(tmp);
		}
		std::cout << fileContent << std::endl;
		int pos = fileContent.find(av[2]);
		std::string target = av[2];
		while (pos != -1) {
			fileContent.erase(fileContent.begin() + pos, fileContent.begin() + pos + target.size());
			fileContent.insert(pos, av[3]);
			pos = fileContent.find(av[2]);
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
