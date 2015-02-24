#ifndef RENDERER_HPP
# define RENDERER_HPP
# include <string>
# include <sstream>
# include <iostream>
# include <SDL.h>
# include <SDL_opengl.h>
# include <unistd.h>
# include "Fps.hpp"
# include "Interval.hpp"
# include "Isometry.hpp"
# include "Iswi.hpp"

class Renderer
{
	public:
		Renderer( void );
		~Renderer( void );
		void			init();
		void			run(std::vector<Vertex> vtx, int sizex, int sizey);
		void			drawTriangle(Triangle triangle);
		void			quit();

	private:
		double				_put_blue(double z);
		double				_put_green(double z);
		double				_put_red(double z);
		Renderer(Renderer const & src);
		Renderer &	operator=(Renderer const & rhs);
		SDL_Window			*_window;
		SDL_GLContext		_glcontext;

};

#endif /* RENDERER_HPP */
