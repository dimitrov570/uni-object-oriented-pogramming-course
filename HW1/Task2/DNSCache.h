#pragma once
#include <iostream>
#include "DNSRecord.h"
#define _CRTDBG_MAP_ALLOC
#include <cstdlib> 
#include <crtdbg.h> 
#ifdef _DEBUG 
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#endif 


const int INITIAL_SIZE = 10;
const int EXPAND_FACTOR = 2;

class DNSCache
{
	DNSRecord* records;
	int size;
	int numberOfElements;

	//Function for copy constructor and operator=
	void copy(const DNSCache & copyFrom);

	//Function for lookup() method
	bool compareNames(const char* domainName, const char* compareWith) const;

public:

	DNSCache();

	DNSCache(const DNSCache & copyFrom);
	
	DNSCache & operator=(const DNSCache & object);

	bool empty() const;

	bool full() const;

	void resize();
	
	void add(DNSRecord record);

	void pop();

	const char* lookup(const char* domainName) const;

	void flush();

	void print() const;

	~DNSCache();

};