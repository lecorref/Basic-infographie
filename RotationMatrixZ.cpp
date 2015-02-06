
#include "RotationMatrixZ.hpp"

RotationMatrixZ::RotationMatrixZ(double const angle)
{
	double tab[4][4] = {
		{ std::cos(angle), -std::sin(angle), 0, 0 },
		{ std::sin(angle), std::cos(angle), 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 1 }
	};
	std::cout << "[RotationMatrixZ] created" << std::endl;
	this->_initialize(tab);
	return ;
}

RotationMatrixZ::RotationMatrixZ(RotationMatrixZ const & src)
{
	std::cout << "[RotationMatrixZ] created" << std::endl;
	*this = src;
	return ;
}

RotationMatrixZ::~RotationMatrixZ( void )
{
	std::cout << "[RotationMatrixZ] destructed" << std::endl;
	return ;
}

RotationMatrixZ &	RotationMatrixZ::operator=(RotationMatrixZ const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}

RotationMatrixZ::RotationMatrixZ( void )
{
	return ;
}
