#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Vertex.hpp"
# include "Vector.hpp"

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
		Vector		getNormal() const;
		std::string	toString() const;

	private:
		void		_initNormalVector();
		Vertex		_a;
		Vertex		_b;
		Vertex		_c;
		Vector		_normal;
};

std::ostream &		operator<<(std::ostream & o, Triangle const & rhs);

#endif /* TRIANGLE_HPP */
