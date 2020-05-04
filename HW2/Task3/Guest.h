#pragma once


class Guest
{
protected:
	char* ipAdress = nullptr;
	void setIP(const char* ip);

public:

	Guest(const char* ip);
	Guest(const Guest & copyFrom);
	Guest & operator=(const Guest & copyFrom);
	~Guest();


	const char* getIpAdress() const;
};