#pragma once
#include "User.h"

class PowerUser: virtual public User
{
protected:
	int Reputation;


public:
	PowerUser(const char* ip = nullptr, const char* username = nullptr, const char* password = nullptr, const char* title = nullptr);
	void increaseReputation(const User & user);
	int getReputation() const;

};
