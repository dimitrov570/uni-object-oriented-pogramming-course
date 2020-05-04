#pragma once

class Point2D
{
protected:
	double x;
	double y;

public:

	Point2D(double X=0, double Y=0);

	int getX() const;
	int getY() const;

	virtual void setCoordinates(Point2D * point);

	virtual double getDistanceTo(const Point2D & object);
};