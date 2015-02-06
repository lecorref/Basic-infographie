
#include "ScaleMatrix.hpp"

ScaleMatrix::ScaleMatrix( void )
{
	std::cout << "[RotationMatrixZ] created" << std::endl;
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
	std::cout << "[RotationMatrixZ] created" << std::endl;
	this->_initialize(tab);
	return ;
}

ScaleMatrix::ScaleMatrix(ScaleMatrix const & src)
{
	std::cout << "[RotationMatrixZ] created" << std::endl;
	*this = src;
	return ;
}

ScaleMatrix::~ScaleMatrix( void )
{
	std::cout << "[RotationMatrixZ] destructed" << std::endl;
	return ;
}

ScaleMatrix &	ScaleMatrix::operator=(ScaleMatrix const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}
