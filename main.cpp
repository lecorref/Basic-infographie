/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaucher <afaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 16:49:11 by afaucher          #+#    #+#             */
/*   Updated: 2015/02/13 18:01:04 by afaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Renderer.hpp"

int	main()
{
	std::vector<std::vector<Vertex> >	vtx;
	std::vector<Vertex>					vec;
	Vertex								p1(350.0, 0.0, 200.0, 0.0, 255);
	Vertex								p2(300.0, 300.0, 34.54, 0.0, 0xFF0000);
	Vertex								p3(600.0, 20.0, 100.4, 0.0, 0xFF00FF);
	Vertex								p4(600.0, 420.0, 20, 0.0, 0xFF00FF);

	vec.push_back(p1);
	vec.push_back(p2);
	vtx.push_back(vec);
	vec.clear();
	vec.push_back(p3);
	vec.push_back(p4);
	vtx.push_back(vec);

	Renderer renderer;

	renderer.init();
	renderer.run(vtx);
	renderer.quit();
	return (0);
}
