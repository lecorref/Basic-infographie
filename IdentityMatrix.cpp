
#include "IdentityMatrix.hpp"

IdentityMatrix::IdentityMatrix( void )
{
	double tab[4][4] = {
	 { 1, 0, 0, 0 },
	 { 0, 1, 0, 0 },
	 { 0, 0, 1, 0 },
	 { 0, 0, 0, 1 },
	};
	std::cout << "[IdentityMatrix] created" << std::endl;
	this->_initialize(tab);
	return ;
}

IdentityMatrix::IdentityMatrix(IdentityMatrix const & src)
{
	std::cout << "[IdentityMatrix] created" << std::endl;
	*this = src;
	return ;
}

IdentityMatrix::~IdentityMatrix( void )
{
	std::cout << "[IdentityMatrix] destructed" << std::endl;
	return ;
}

IdentityMatrix &	IdentityMatrix::operator=(IdentityMatrix const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}
