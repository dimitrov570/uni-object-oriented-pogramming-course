#pragma once
#include "Point2D.h"

class Point3D: public Point2D
{
private:

	double z;

public:

	Point3D(double X = 0, double Y = 0, double Z = 0);
	
	int getZ() const;

	void setCoordinates(Point2D * point);

	virtual double getDistanceTo(const Point3D & object);
};