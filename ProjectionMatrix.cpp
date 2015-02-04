
#include "ProjectionMatrix.hpp"

ProjectionMatrix::ProjectionMatrix( void )
{
	return ;
}

ProjectionMatrix::ProjectionMatrix( double const angle, double const ratio, double const near, double const far )
{
	double scale = 1 / std::tan((angle / 2) / 180.0 * M_PI);
	double tab[4][4] = {
		{ scale / ratio, 0, 0, 0 },
		{ 0, scale, 0, 0 },
		{ 0, 0, (far + near) / (near - far), (2 * far * near) / (near - far) },
		{ 0, 0, -1, 0 },
	};
	this->_initialize(tab);
	return ;
}

ProjectionMatrix::ProjectionMatrix(ProjectionMatrix const & src)
{
	*this = src;
	return ;
}

ProjectionMatrix::~ProjectionMatrix( void )
{
	return ;
}

ProjectionMatrix &	ProjectionMatrix::operator=(ProjectionMatrix const & rhs)
{
	this->_initialize(rhs._values);
	return *this;
}
