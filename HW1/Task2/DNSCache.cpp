#include "DNSCache.h"



DNSCache::DNSCache()
{
	size = INITIAL_SIZE;
	records = new DNSRecord[size];
	numberOfElements = 0;
}

void DNSCache::copy(const DNSCache & copyFrom)
{
	size = copyFrom.size;
	records = new DNSRecord[size];
	numberOfElements = copyFrom.numberOfElements;

	for (int i = 0; i < numberOfElements; ++i)
	{
		records[i] = copyFrom.records[i];
	}
}

bool DNSCache::compareNames(const char* domainName, const char* compareWith) const
{
	if (domainName == nullptr || compareWith == nullptr)
	{
		return false;
	}
	else if (strlen(domainName) != strlen(compareWith))//To prevent accessing memory that isn't allowed
	{
		return false;
	}
	for (int i = 0; i < strlen(domainName); i++)
	{
		if (domainName[i] != compareWith[i])
		{
			return false;
		}
	}
	return true;
}

DNSCache::DNSCache(const DNSCache & copyFrom)
{
	copy(copyFrom);
}

DNSCache & DNSCache::operator=(const DNSCache & object)
{
	if (this != &object)
	{
		delete[] records;
		copy(object);
	}

	return *this;
}

bool DNSCache::empty() const
{
	return (numberOfElements == 0);
}

bool DNSCache::full() const
{
	return (numberOfElements >= size);
}

void DNSCache::resize()
{
	int new_size = size * EXPAND_FACTOR;

	DNSRecord *tmp = new DNSRecord[new_size];

	for (int i = 0; i < size; ++i)
	{
		tmp[i] = records[i];
	}

	delete[] records;
	records = tmp;
	size = new_size;
}

void DNSCache::add(DNSRecord record)
{
	if (full())
	{
		resize();
	}

	records[numberOfElements++] = record;
}

const char * DNSCache::lookup(const char * lookFor) const
{
	if (empty())
	{
		std::cout << "The record is empty!" << std::endl;
		return NULL;
	}
	for (int i = 0; i < numberOfElements; i++)
	{
		if (compareNames(records[i].getName(),lookFor))
		{
			return records[i].getIpAdress();
		}
	}
	return NULL;
}

void DNSCache::flush()
{
	while (!empty())
	{
		pop();
	}
}

void DNSCache::print() const
{
	if (empty())
	{
		std::cout << "The record is empty!";
		return;
	}

	for (int i = 0; i < numberOfElements; ++i)
	{
		//std::cout << "-------------------------------- \n";
		std::cout << "Record " << i+1 << ": \n--------------------------------\n" << records[i] <<
		"\n" << "-------------------------------- \n"<<'\n';
	}
}

void DNSCache::pop()
{
	if (empty())
	{
		std::cout << "The record is empty!" << std::endl;
		return;
	}

	records[numberOfElements - 1]=NULL;
	--numberOfElements;
}

DNSCache::~DNSCache()
{
	delete[] records;
}