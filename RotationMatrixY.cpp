
#include "RotationMatrixY.hpp"

RotationMatrixY::RotationMatrixY(double const angle)
{
	double tab[4][4] = {
		{ std::cos(angle), 0, std::sin(angle), 0 },
		{ 0, 1, 0, 0 },
		{ -std::sin(angle), 0, std::cos(angle), 0 },
		{ 0, 0, 0, 1 }
	};
	std::cout << "[RotationMatrixY] created" << std::endl;
	this->_initialize(tab);
	return ;
}

RotationMatrixY::RotationMatrixY(RotationMatrixY const & src)
{
	std::cout << "[RotationMatrixY] created" << std::endl;
	*this = src;
	return ;
}

RotationMatrixY::~RotationMatrixY( void )
{
	std::cout << "[RotationMatrixY] destructed" << std::endl;
	return ;
}

RotationMatrixY &	RotationMatrixY::operator=(RotationMatrixY const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}

RotationMatrixY::RotationMatrixY( void )
{
	return ;
}
