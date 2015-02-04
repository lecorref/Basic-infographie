
#include "ScaleMatrix.hpp"

ScaleMatrix::ScaleMatrix( void )
{
	return ;
}

ScaleMatrix::ScaleMatrix( double const scale )
{
	double tab[4][4] = {
		{ scale, 0, 0, 0 },
		{ 0, scale, 0, 0 },
		{ 0, 0, scale, 0 },
		{ 0, 0, 0, 1 },
	};
	this->_initialize(tab);
	return ;
}

ScaleMatrix::ScaleMatrix(ScaleMatrix const & src)
{
	*this = src;
	return ;
}

ScaleMatrix::~ScaleMatrix( void )
{
	return ;
}

ScaleMatrix &	ScaleMatrix::operator=(ScaleMatrix const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}
