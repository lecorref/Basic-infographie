#ifndef MATRIX_HPP
# define MATRIX_HPP
# include <string>
# include <sstream>
# include <iostream>
# include <cmath>
# include "Triangle.hpp"

class Matrix
{
	public:
		Matrix(Matrix const & src);
		virtual		~Matrix( void );
		Matrix		operator*(Matrix const & rhs) const;
		Vertex		operator*(Vertex const & vertex) const;
		Matrix &	operator=(Matrix const & rhs);
		Matrix		inverse() const;
		Vertex		transformVertex(Vertex const & vertex) const;
		Triangle	transformTriangle(Triangle const & triangle) const;
		std::string	toString() const;

	protected:
		Matrix(void);
		Matrix( double values[4][4] );
		void		_initialize(double const values[4][4]);
		double		_values[4][4];
};

std::ostream &		operator<<(std::ostream & o, Matrix const & rhs);

#endif /* MATRIX_HPP */
