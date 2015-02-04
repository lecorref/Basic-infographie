
#include "Matrix.hpp"

Matrix::Matrix( void )
{
	return ;
}

Matrix::Matrix( double values[4][4] )
{
	this->_initialize(values);
	return ;
}

Matrix::Matrix(Matrix const & src)
{
	*this = src;
	return ;
}

Matrix::~Matrix( void )
{
	return ;
}

Matrix		Matrix::operator*(Matrix const & rhs) const
{
	double	tab[4][4];
	double	tmp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tmp = 0;
			for (int k = 0; k < 4; k++)
				tmp += this->_values[i][k] * rhs._values[k][j];
			tab[i][j] = tmp;
		}
	}
	return Matrix(tab);
}

Matrix &	Matrix::operator=(Matrix const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}

Matrix		Matrix::inverse() const
{
	double	tab[4][4] =
	{
		{ this->_values[0][0], this->_values[1][0], this->_values[2][0], this->_values[3][0] },
		{ this->_values[0][1], this->_values[1][1], this->_values[2][1], this->_values[3][1] },
		{ this->_values[0][2], this->_values[1][2], this->_values[2][2], this->_values[3][2] },
		{ this->_values[0][3], this->_values[1][3], this->_values[2][3], this->_values[3][3] },
	};
	return Matrix(tab);
}

void		Matrix::_initialize(double const values[4][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			this->_values[i][j] = values[i][j];
		}
	}
}

Vertex		Matrix::operator*(Vertex const & vertex) const
{
	double	x = vertex.getX() * this->_values[0][0] + vertex.getY() * this->_values[0][1] + vertex.getZ() * this->_values[0][2] + vertex.getW() * this->_values[0][3];
	double	y = vertex.getX() * this->_values[1][0] + vertex.getY() * this->_values[1][1] + vertex.getZ() * this->_values[1][2] + vertex.getW() * this->_values[1][3];
	double	z = vertex.getX() * this->_values[2][0] + vertex.getY() * this->_values[2][1] + vertex.getZ() * this->_values[2][2] + vertex.getW() * this->_values[2][3];
	double	w = vertex.getX() * this->_values[3][0] + vertex.getY() * this->_values[3][1] + vertex.getZ() * this->_values[3][2] + vertex.getW() * this->_values[3][3];
	return Vertex(x, y, z, w, vertex.getColor());
}

Triangle	Matrix::transformTriangle(Triangle const & triangle) const
{
	return Triangle(*this * triangle.getA(), *this * triangle.getB(), *this * triangle.getC());
}

std::string	Matrix::toString() const
{

}
