#include "Point2D.h"
#include <iostream>

Point2D::Point2D(double X, double Y):x(X), y(Y)
{}

int Point2D::getX() const
{
	return x;
}

int Point2D::getY() const
{
	return y;
}

void Point2D::setCoordinates(Point2D * point)
{
	x = (*point).getX();
	y = (*point).getY();
}

double Point2D::getDistanceTo(const Point2D & object)
{
	return sqrt((x - object.x)*(x - object.x) + (y - object.y)*(y - object.y));
}
