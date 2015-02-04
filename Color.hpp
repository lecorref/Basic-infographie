#ifndef COLOR_HPP
# define COLOR_HPP
# include <string>
# include <sstream>
# include <iostream>

class Color
{
	public:
		Color( void );
		Color( unsigned int color );
		Color( unsigned char r, unsigned char g, unsigned char b);
		Color(Color const & src);
		~Color( void );
		unsigned char		getRed() const;
		unsigned char		getGreen() const;
		unsigned char		getBlue() const;
		unsigned int		getHex() const;
		Color				operator*(double d);
		Color				operator-(Color const & rhs);
		Color				operator+(Color const & rhs);
		Color &				operator=(Color const & rhs);
		std::string			toString() const;

	private:
		unsigned char		_r;
		unsigned char		_g;
		unsigned char		_b;
};

std::ostream &		operator<<(std::ostream & o, Color const & rhs);

#endif /* COLOR_HPP */
