
#include <iostream>
#include <fstream>
#include <string>

int	replace(std::string *line, std::string to_find, std::string to_put)
{
	std::size_t found;
	std::size_t len_find;
	std::size_t len_put;

	found = line->find(to_find);
	len_find = to_find.length();
	len_put = to_put.length();
	while (found != std::string::npos)
	{
		line->erase (found, len_find);
		line->insert (found, to_put);
		found = line->find(to_find, found + len_put);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::fstream	file;
	std::fstream	new_file;
	std::string		new_file_name;
	std::string		text;
	char			c;

	if (argc != 4 || argv[0] == "" || argv[1] == "")//check empty string !
	{
		std::cout << "parameters error\n";
		return (1);
	}
	new_file_name.append(argv[1]);
	new_file_name.append(".replace");
	file.open(argv[1], std::ios::in);
	if(!file)
	{
		std::cout << "No such file\n";
		return (1);
	}
	new_file.open(new_file_name, std::ios::out);
	if(!new_file)
	{
		std::cout << "file opening failed\n";
		file.close();
		return (1);
	}
	while (file.get(c))
		text = text + c;
	replace (&text, argv[2], argv[3]);
	new_file << text;
	file.close();
	new_file.close();
	return (0);
}