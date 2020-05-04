#include "Guest.h"
#include <iostream>


Guest::Guest(const char * ip)
{
	setIP(ip);
}

Guest::Guest(const Guest & copyFrom)
{
	setIP(copyFrom.ipAdress);
}

Guest & Guest::operator=(const Guest & copyFrom)
{
	if (this != &copyFrom)
	{
		setIP(copyFrom.ipAdress);
	}
	return *this;
}

Guest::~Guest()
{
	delete[] ipAdress;
}

void Guest::setIP(const char * ip)
{
	if (ip == nullptr)
	{
		return;
	}
	delete[] ipAdress;
	ipAdress = new char[strlen(ip) + 1];
	strcpy(ipAdress, ip);
}

const char * Guest::getIpAdress() const
{
	return ipAdress;
}
