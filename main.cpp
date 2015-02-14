#include "Renderer.hpp"

int	main()
{
	std::vector<std::vector<Vertex> >	vtx;
	std::vector<Vertex>					vec;
	Vertex								p1(100.0, 200.0, -100.0, 0.0, 255);
	Vertex								p2(300.0, 200.0, -100.0, 0.0, 0xFF0000);
	Vertex								p3(600.0, 200.0, -100.0, 0.0, 0xFF00FF);
	Vertex								p4(100.0, 200.0, 100.0, 0.0, 255);
	Vertex								p5(300.0, -400.0, 100.0, 0.0, 0xFF0000);
	Vertex								p6(600.0, 200.0, 100.0, 0.0, 0xFF00FF);
	Vertex								p7(100.0, 200.0, 300, 0.0, 0xFF00FF);
	Vertex								p8(300.0, 200.0, 300, 0.0, 255);
	Vertex								p9(600.0, 200.0, 300.0, 0.0, 255);

	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	vtx.push_back(vec);
	vec.clear();
	vec.push_back(p4);
	vec.push_back(p5);
	vec.push_back(p6);
	vtx.push_back(vec);
	vec.clear();
	vec.push_back(p7);
	vec.push_back(p8);
	vec.push_back(p9);
	vtx.push_back(vec);

	Renderer renderer;

	renderer.init();
	renderer.run(vtx, 2, 2);
	renderer.quit();
	return (0);
}
