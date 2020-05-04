#include "Point3D.h"
#include <iostream>

Point3D::Point3D(double X, double Y, double Z):Point2D(X,Y), z(Z)
{}

int Point3D::getZ() const
{
	return z;
}

void Point3D::setCoordinates(Point2D * point)
{
	Point3D* CastTo3D = dynamic_cast<Point3D*>(point);

	if (CastTo3D != nullptr)
	{
		x = CastTo3D->getX();
		y = CastTo3D->getY();
		z = CastTo3D->getZ();
	}
	else
	{
		x = point->getX();
		y = point->getY();
		z = 0;
	}
}

double Point3D::getDistanceTo(const Point3D & object)
{
	double distanceInOxy = Point2D::getDistanceTo(Point2D(object.x, object.y));	//This is the distance of points projections on Oxy plane

	return sqrt(distanceInOxy*distanceInOxy + (z - object.z)*(z - object.z)); //Pythagoras theorem
}
