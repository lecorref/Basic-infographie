#ifndef SCALEMATRIX_HPP
# define SCALEMATRIX_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Matrix.hpp"

class ScaleMatrix : public Matrix
{
	public:
		ScaleMatrix( double const scale );
		ScaleMatrix(ScaleMatrix const & src);
		~ScaleMatrix( void );
		ScaleMatrix &	operator=(ScaleMatrix const & rhs);

	private:
		ScaleMatrix( void );
};
#endif /* SCALEMATRIX_HPP */
