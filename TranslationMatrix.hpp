#ifndef TRANSLATIONMATRIX_HPP
# define TRANSLATIONMATRIX_HPP
# include <string>
# include <sstream>
# include <iostream>
# include "Vector.hpp"
# include "Matrix.hpp"

class TranslationMatrix : public Matrix
{
	public:
		TranslationMatrix( Vector const & vtc);
		TranslationMatrix(TranslationMatrix const & src);
		~TranslationMatrix( void );
		TranslationMatrix &	operator=(TranslationMatrix const & rhs);

	private:
		TranslationMatrix( void );
};
#endif /* TRANSLATIONMATRIX_HPP */
