
#include "Renderer.hpp"

void		Renderer::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	this->_window = SDL_CreateWindow("SDL2 Pixel Drawing",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 960, SDL_WINDOW_OPENGL);

	this->_glcontext = SDL_GL_CreateContext(this->_window);
	glViewport(0, 0, 1280, 960);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1280, 960, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0, 0, 0, 0);
	return ;
}

void		Renderer::run(std::vector<Vertex> vtx, int sizex, int sizey)
{
	std::vector<std::vector <Vertex> >	iso = Isometry::toIso(Iswi::surface(vtx, sizex, sizey, 800, 800));
	bool								quit = false;
	SDL_Event							event;
	Vertex								tmp;

	while (!quit)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
			case SDL_QUIT:
				quit = true;
				break;
		}

		glClear(GL_COLOR_BUFFER_BIT);
		for (unsigned int i = 0; i < iso.size() - 1; i++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			for (int j = iso[i].size() - 1; j >= 0; j--)
			{
				tmp = iso[i][j];
				glColor3f(this->_put_red(tmp.getZ()), this->_put_green(tmp.getZ()), this->_put_blue(tmp.getZ()));
				glVertex3f(tmp.getX(), tmp.getY(), 0);
				tmp = iso[i + 1][j];
				glColor3f(this->_put_red(tmp.getZ()), this->_put_green(tmp.getZ()), this->_put_blue(tmp.getZ()));
				glVertex3f(tmp.getX(), tmp.getY(), 0);
			}
			glEnd();
		}
		SDL_GL_SwapWindow(this->_window);
	}
	return ;
}

void		Renderer::quit()
{
	SDL_DestroyWindow(this->_window);
	SDL_GL_DeleteContext(this->_glcontext);
	SDL_Quit();
	return ;
}

double		Renderer::_put_blue(double z)
{
	if (z <= 0 && z > -200)
		return ((255.0 + z) / 255.0);
	else if (z < -200)
		return (50 / 255.0);
	else if (z >= 255.0)
		return (1);
	else
		return (0);
}

double		Renderer::_put_green(double z)
{
	if (z < -68)
		return (0);
	else if (z <= 0)
		return ((136 + z * 2) / 255.0);
	else if (z >= 255.0)
		return (1);
	else if (z < 100)
		return ((60 + z) / 255.0);
	else
		return (150 / 255.0);
}

double	Renderer::_put_red(double z)
{
	if (z > 0 && z < 255.0)
		return (z / 255.0);
	else if (z >= 255.0)
		return (1);
	else
		return (0);
}

Renderer::Renderer( void )
{
	return ;
}

Renderer::~Renderer( void )
{
	this->quit();
	return ;
}
