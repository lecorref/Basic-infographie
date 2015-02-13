/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:49:11 by afaucher          #+#    #+#             */
/*   Updated: 2015/02/13 18:37:33 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Renderer.hpp"

int	main()
{
	std::vector<std::vector<Vertex> >	vtx;
	std::vector<Vertex>					vec;
	Vertex								p1(100.0, 80.0, 0.0, 0.0, 255);
	Vertex								p2(300.0, 80.0, 0.54, 0.0, 0xFF0000);
	Vertex								p3(500.0, 80.0, 0.4, 0.0, 0xFF00FF);
	Vertex								p4(100.0, 300.0, 0, 0.0, 0xFF00FF);
	Vertex								p5(300.0, 300.0, 0, 0.0, 255);
	Vertex								p6(500.0, 300.0, 0.0, 0.0, 255);

	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	vtx.push_back(vec);
	vec.clear();
	vec.push_back(p4);
	vec.push_back(p5);
	vec.push_back(p6);
	vtx.push_back(vec);

	Renderer renderer;

	renderer.init();
	renderer.run(vtx, 1, 2);
	renderer.quit();
	return (0);
}
