
#include "TranslationMatrix.hpp"

TranslationMatrix::TranslationMatrix( void )
{
	return ;
}

TranslationMatrix::TranslationMatrix( Vector const & vtc )
{
	double tab[4][4] = {
		{ 0, 0, 0, vtc.getX() },
		{ 0, 0, 0, vtc.getY() },
		{ 0, 0, 0, vtc.getZ() },
		{ 0, 0, 0, 1 },
	};
	this->_initialize(tab);
	return ;
}

TranslationMatrix::TranslationMatrix(TranslationMatrix const & src)
{
	*this = src;
	return ;
}

TranslationMatrix::~TranslationMatrix( void )
{
	return ;
}

TranslationMatrix &	TranslationMatrix::operator=(TranslationMatrix const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}
