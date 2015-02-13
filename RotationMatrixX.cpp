
#include "RotationMatrixX.hpp"

RotationMatrixX::RotationMatrixX(double const angle)
{
	double tab[4][4] = {
		{ 1, 0, 0, 0 },
		{ 0, std::cos(angle), -std::sin(angle), 0 },
		{ 0, std::sin(angle), std::cos(angle), 0 },
		{ 0, 0, 0, 1 }
	};
	this->_initialize(tab);
	return ;
}

RotationMatrixX::RotationMatrixX(RotationMatrixX const & src) : Matrix(src)
{
	*this = src;
	return ;
}

RotationMatrixX::~RotationMatrixX( void )
{
	return ;
}

RotationMatrixX &	RotationMatrixX::operator=(RotationMatrixX const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}

RotationMatrixX::RotationMatrixX( void )
{
	return ;
}

