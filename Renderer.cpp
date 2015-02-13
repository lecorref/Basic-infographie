
#include "Renderer.hpp"

void		Renderer::init()
{
	SDL_Init(SDL_INIT_VIDEO);
	this->_window = SDL_CreateWindow("SDL2 Pixel Drawing",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);

	this->_glcontext = SDL_GL_CreateContext(this->_window);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 640, 480, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0, 0, 0, 0);
	return ;
}

void		Renderer::run(std::vector<std::vector<Vertex> > vtx)
{
	std::vector<std::vector<Vertex> >	iso;
	bool								quit = false;
	SDL_Event							event;
	iso = Isometry::toIso(*Bezier::surface(vtx, 1, 1, 40, 40));

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
				glColor3f(1.0f, 0.34f, (iso[i][j].getZ() * 2.0) / 255.0);
				glVertex3f(iso[i][j].getX(), iso[i][j].getY(), 0);
				glColor3f(1.0f, 0.34f, (iso[i + 1][j].getZ() * 2.0) / 255.0);
				glVertex3f(iso[i + 1][j].getX(), iso[i + 1][j].getY(), 0);
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

Renderer::Renderer( void )
{
	return ;
}

Renderer::~Renderer( void )
{
	this->quit();
	return ;
}
