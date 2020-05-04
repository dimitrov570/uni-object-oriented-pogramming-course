#include "DNSRecord.h"


DNSRecord::DNSRecord(const char * name, const char * adress)
{
	if (name != nullptr) 
	{
		int nameLength = strlen(name);
		domainName = new char[nameLength + 1];
		strcpy(domainName, name);
	}
	else
	{
		domainName = new char[1];
		domainName[0] = 0;
	}

	if (adress != nullptr)
	{
		int adressLength = strlen(adress);
		ipAdress = new char[adressLength + 1];
		strcpy(ipAdress, adress);
	}
	else
	{
		ipAdress = new char[1];
		ipAdress[0] = 0;
	}
	
}

DNSRecord::DNSRecord(const DNSRecord & copyFrom)
{
	int nameLength = strlen(copyFrom.domainName);
	domainName = new char[nameLength + 1];
	strcpy(domainName, copyFrom.domainName);

	int adressLength = strlen(copyFrom.ipAdress);
	ipAdress = new char[adressLength + 1];
	strcpy(ipAdress, copyFrom.ipAdress);

}

DNSRecord & DNSRecord::operator=(const DNSRecord & object)
{
	if (this != &object)
	{
		delete[] domainName;
		delete[] ipAdress;

		int nameLength = strlen(object.domainName);
		domainName = new char[nameLength + 1];
		strcpy(domainName, object.domainName);


		int adressLength = strlen(object.ipAdress);
		ipAdress = new char[adressLength + 1];
		strcpy(ipAdress, object.ipAdress);
	}

	return *this;
}

DNSRecord::~DNSRecord()
{
	delete[] domainName;
	delete[] ipAdress;
}

const char * DNSRecord::getName() const
{
	return domainName;
}

const char * DNSRecord::getIpAdress() const
{
	return ipAdress;
}

void DNSRecord::setName(const char * name)
{
	if (name == nullptr)
	{
		return;
	}

	delete[] domainName;

	int nameLength = strlen(name);
	domainName = new char[nameLength + 1];
	strcpy(domainName, name);

}

void DNSRecord::setIpAdress(const char * adress)
{
	if (adress == nullptr)
	{
		return;
	}

	delete[] ipAdress;

	int adressLength = strlen(adress);
	ipAdress = new char[adressLength + 1];
	strcpy(ipAdress, adress);
}

std::ostream & operator<<(std::ostream & stream, const DNSRecord & object)
{
	if ((object.domainName != nullptr) && (object.ipAdress != nullptr))
	{
		stream << "Name: " << object.domainName << "\n" << "IP Adress: " << object.ipAdress;
	}
	
	return stream;
}
