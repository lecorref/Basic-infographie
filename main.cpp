/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:49:11 by afaucher          #+#    #+#             */
//   Updated: 2015/02/18 12:37:40 by frale-co         ###   ########.fr       //
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Renderer.hpp"
#include "Lexer.hpp"

int	main(int ac, char **av)
{
	std::vector<std::vector<Vertex> >	vtx2;
	std::vector<Vertex>					vec;

	Vertex								p1(400.0, 400.0, 40.4);
	Vertex								p2(3.0, 4.0, 1.0);
	Vertex								p4(1.0, 5.0, 1.0);
	Vertex								p5(3.0, 5.0, 2.0);

	if (ac > 1)
		vtx2 = Lexer::readFile(av[1]);
	if (ac > 1 && vtx2.empty())
	{
		std::cerr << "File is not well formated or empty." << std::endl;
		return 1;
	}
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p4);
	vec.push_back(p5);

	Renderer renderer;

	renderer.init();
	if (ac == 1)
		renderer.run(vec, 400, 400);
	else
		renderer.run(vec, 400, 400);
	renderer.quit();
	return (0);
}
