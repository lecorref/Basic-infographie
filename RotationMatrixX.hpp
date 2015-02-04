#ifndef ROTATIONMATRIXX_HPP
# define ROTATIONMATRIXX_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Matrix.hpp"

class RotationMatrixX : public Matrix
{
	public:
		RotationMatrixX(double const angle);
		RotationMatrixX(RotationMatrixX const & src);
		~RotationMatrixX( void );
		RotationMatrixX &	operator=(RotationMatrixX const & rhs);

	private:
		RotationMatrixX( void );
};
#endif /* ROTATIONMATRIXX_HPP */
