#include "cub3d.h"

double	normalize_angle(double angle)
{
	if (angle < 0)
		angle += (2 * PI);
	else if (angle > 2 * PI)
		angle -= (2 * PI);
	return (angle);
}