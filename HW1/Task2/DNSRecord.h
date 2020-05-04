#pragma once
#include<iostream>
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h> 
#ifdef _DEBUG 
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#endif 


class DNSRecord
{
	char* domainName;
	char* ipAdress;

public:

	DNSRecord(const char* name = "", const char* adress = "");
	
	DNSRecord(const DNSRecord & object);

	DNSRecord & operator=(const DNSRecord & object);

	~DNSRecord();

	const char* getName() const;
	const char* getIpAdress() const;

	void setName(const char* name);
	void setIpAdress(const char* adress);

	friend std::ostream & operator<<(std::ostream & stream, const DNSRecord & object);
};