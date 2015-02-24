#include "Renderer.hpp"
#include "Lexer.hpp"

int	main(int ac, char **av)
{
	std::vector<Vertex>					vtx2;
	std::vector<Vertex>					vec;
	Vertex								p1(400.0, 400.0, 400.0);
	Vertex								p4(390.0, 390.0, 400.0);
	Vertex								p2(200.0, 200.0, 200.0);
	Vertex								p3(600.0, 300.0, 350.0);
	Vertex								p5(300.0, 300.0, -10.0);

	if (ac > 1)
		vtx2 = Lexer::readFile(av[1]);
	if (ac > 1 && vtx2.empty())
	{
		std::cerr << "File is not well formated or empty." << std::endl;
		return 1;
	}
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	vec.push_back(p4);
	vec.push_back(p5);

	Renderer renderer;

	renderer.init();
	if (ac == 1)
		renderer.run(vec, 400, 400);
	else
		renderer.run(vtx2, 400, 400);
	renderer.quit();
	return (0);
}
