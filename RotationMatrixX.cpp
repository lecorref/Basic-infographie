
#include "RotationMatrixX.hpp"

RotationMatrixX::RotationMatrixX(double const angle)
{
	double tab[4][4] = {
		{ 1, 0, 0, 0 },
		{ 0, std::cos(angle), -std::sin(angle), 0 },
		{ 0, std::sin(angle), std::cos(angle), 0 },
		{ 0, 0, 0, 1 }
	};
	std::cout << "[RotationMatrixX] created" << std::endl;
	this->_initialize(tab);
	return ;
}

RotationMatrixX::RotationMatrixX(RotationMatrixX const & src)
{
	std::cout << "[RotationMatrixX] created" << std::endl;
	*this = src;
	return ;
}

RotationMatrixX::~RotationMatrixX( void )
{
	std::cout << "[RotationMatrixX] destructed" << std::endl;
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

