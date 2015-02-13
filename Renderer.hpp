#ifndef RENDERER_HPP
# define RENDERER_HPP
# include <string>
# include <sstream>
# include <iostream>
#include </nfs/zfs-student-2/users/2013/frale-co/.brew/Cellar/sdl2/2.0.3/include/SDL2/SDL.h>
#include </nfs/zfs-student-2/users/2013/frale-co/.brew/Cellar/sdl2/2.0.3/include/SDL2/SDL_opengl.h>
# include "Isometry.hpp"
# include "Bezier.hpp"

class Renderer
{
	public:
		Renderer( void );
		~Renderer( void );
		void			init();
		void			run(std::vector<std::vector<Vertex> > vtx, int sizex, int sizey);
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
