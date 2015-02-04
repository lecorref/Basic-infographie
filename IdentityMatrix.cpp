
#include "IdentityMatrix.hpp"

IdentityMatrix::IdentityMatrix( void )
{
	double tab[4][4] = {
	 { 1, 0, 0, 0 },
	 { 0, 1, 0, 0 },
	 { 0, 0, 1, 0 },
	 { 0, 0, 0, 1 },
	};
	this->_initialize(tab);
	return ;
}

IdentityMatrix::IdentityMatrix(IdentityMatrix const & src)
{
	*this = src;
	return ;
}

IdentityMatrix::~IdentityMatrix( void )
{
	return ;
}

IdentityMatrix &	IdentityMatrix::operator=(IdentityMatrix const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}
