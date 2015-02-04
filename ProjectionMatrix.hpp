#ifndef PROJECTIONMATRIX_HPP
# define PROJECTIONMATRIX_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Matrix.hpp"

class ProjectionMatrix : public Matrix
{
	public:
		ProjectionMatrix( double const angle, double const ratio, double const near, double const far );
		ProjectionMatrix(ProjectionMatrix const & src);
		~ProjectionMatrix( void );
		ProjectionMatrix &	operator=(ProjectionMatrix const & rhs);

	private:
		ProjectionMatrix( void );
};
#endif /* PROJECTIONMATRIX_HPP */
