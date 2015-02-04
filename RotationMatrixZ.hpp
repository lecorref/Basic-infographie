#ifndef ROTATIONMATRIXX_HPP
# define ROTATIONMATRIXX_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Matrix.hpp"

class RotationMatrixZ : public Matrix
{
	public:
		RotationMatrixZ(double const angle);
		RotationMatrixZ(RotationMatrixZ const & src);
		~RotationMatrixZ( void );
		RotationMatrixZ &	operator=(RotationMatrixZ const & rhs);

	private:
		RotationMatrixZ( void );
};

#endif /* ROTATIONMATRIXX_HPP */
