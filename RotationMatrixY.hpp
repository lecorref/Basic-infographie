#ifndef ROTATIONMATRIXY_HPP
# define ROTATIONMATRIXY_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Matrix.hpp"

class RotationMatrixY : public Matrix
{
	public:
		RotationMatrixY(double const angle);
		RotationMatrixY(RotationMatrixY const & src);
		~RotationMatrixY( void );
		RotationMatrixY &	operator=(RotationMatrixY const & rhs);

	private:
		RotationMatrixY( void );
};

#endif /* ROTATIONMATRIXX_HPP */
