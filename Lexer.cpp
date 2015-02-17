#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Lexer.hpp"

std::vector<std::vector<Vertex> > &		Lexer::readFile(std::string const filename)
{
	std::string							line;
	std::ifstream						file(filename.c_str());
	std::vector<std::vector<Vertex> > *	ret = new std::vector<std::vector<Vertex> >;

	if(file.is_open())
	{
		while (std::getline(file, line))
		{
			if (Lexer::_checkFormat(line))
				ret->push_back(Lexer::_lexLine(line));
		}
		file.close();
	}
	else
		std::cerr << "Unable to open file" << std::endl;

	return *ret;
}

std::vector<Vertex>					Lexer::_lexLine(std::string const line)
{
	std::vector<Vertex>				ret;
	std::stringstream				tmp;
	unsigned int					i = 0;
	unsigned int					j;
	unsigned int					k = 0;

	while (k < line.size() - 1)
	{
		std::stringstream			*tmp = new std::stringstream;
		while (line[i] != '(' && i < line.size())
			i++;
		i++;
		for (j = i; line[j] != ')' && j < line.size(); j++)
		{
			*tmp << line[j];
		}
		ret.push_back(Lexer::_getVertex(tmp->str()));
		std::cout << "k = " << k <<std::endl;
		k = j;
		i = j;
		delete tmp;
	}

	return ret;
}

Vertex								Lexer::_getVertex(std::string const tmp)
{
	double							nb[3];
	unsigned int					i = 0;
	unsigned int					j = 0;
	unsigned int					k = 0;

	for (i = 0; i < tmp.size(); i++)
	{
		for (j = i; tmp[j] != ',' && j < tmp.size(); j++);
		nb[k] = atof((tmp.substr(i, j - i)).c_str());
		k++;
		i = j;
	}
	Vertex							ret(nb[0] / 100, nb[1] / 100, nb[2] / 100);

	std::cout << "Line: " << nb[0] << ", " << nb[1] << ", " << nb[2] << std::endl;
	return ret;
}

bool								Lexer::_checkFormat(std::string const line)
{
	int								crochet1 = 0;
	int								crochet2 = 0;
	int								virgule = 0;
	unsigned int					i = 0;

	std::cout << "pouet" << std::endl;
	while (i < line.size())
	{
		if (line[i] == '(' && crochet1 == crochet2)
			crochet1++;
		if (line[i] == ',' && crochet1 > 0 && crochet1 == crochet2 + 1)
			virgule++;
		if (line[i] == ')' && crochet1 == crochet2 + 1 && virgule / 2 == crochet1 && virgule % 2 == 0)
			crochet2++;
		i++;
	}
	if (crochet1 == crochet2 && crochet1 > 0)
		return 1;
	return 0;
}
