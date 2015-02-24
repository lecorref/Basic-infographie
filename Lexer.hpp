#ifndef LEXER_HPP
# define LEXER_HPP

# include <vector>
# include "Vertex.hpp"

class Lexer
{
	public:
		static std::vector<Vertex> &				readFile(std::string const filename);

	private:
		Lexer( void );
		Lexer(Lexer const & src);
		~Lexer( void );
		Lexer &										operator=(Lexer const & rhs);
		static void									_lexLine(std::string const line, std::vector<Vertex> * ret);
		static Vertex								_getVertex(std::string const tmp);
		static bool									_checkFormat(std::string const line);
};

#endif /* LEXER_HPP */
