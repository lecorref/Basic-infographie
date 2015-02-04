#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Vertex.hpp"

class Triangle
{
	public:
		Triangle( void );
		Triangle( Vertex const & a, Vertex const & b, Vertex const & c );
		Triangle(Triangle const & src);
		~Triangle( void );
		Triangle &	operator=(Triangle const & rhs);
		Vertex		getA() const;
		Vertex		getB() const;
		Vertex		getC() const;
		std::string	toString() const;

	private:
		Vertex		_a;
		Vertex		_b;
		Vertex		_c;
};

std::ostream &		operator<<(std::ostream & o, Triangle const & rhs);

#endif /* TRIANGLE_HPP */
