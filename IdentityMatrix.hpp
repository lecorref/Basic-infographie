#ifndef IDENTITYMATRIX_HPP
# define IDENTITYMATRIX_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Matrix.hpp"

class IdentityMatrix : public Matrix
{
	public:
		IdentityMatrix( void );
		IdentityMatrix(IdentityMatrix const & src);
		~IdentityMatrix( void );
		IdentityMatrix &	operator=(IdentityMatrix const & rhs);
		std::string	toString() const;

	private:
};

std::ostream &		operator<<(std::ostream & o, IdentityMatrix const & rhs);

#endif /* IDENTITYMATRIX_HPP */
