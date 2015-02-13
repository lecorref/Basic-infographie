int		ft_put_blue(int z)
{
	if (z <= 0 && z > -200)
		return (255 + z);
	else if (z < -200)
		return (50);
	else if (z >= 255)
		return (255);
	else
		return (0);
}

int		ft_put_green(int z)
{
	if (z < -68)
		return (0);
	else if (z <= 0)
		return (136 + z * 2);
	else if (z >= 255)
		return (255);
	else if (z < 100)
		return (60 + z);
	else
		return (150);
}

int		ft_put_red(int z)
{
	if (z > 0 && z < 255)
		return (z);
	else if (z >= 255)
		return (255);
	else
		return (0);
}
