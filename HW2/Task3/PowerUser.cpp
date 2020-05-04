#include "PowerUser.h"
#include <iostream>


PowerUser::PowerUser(const char* ip, const char* username, const char* password, const char* title):User(ip,username,password,title), Reputation(0)
{}

void PowerUser::increaseReputation(const User & user)
{
	if (strcmp(user.getUsername(), Username))
	{
		++Reputation;
		std::cout << "You gave +1 reputation to " << Username << "!\n";
		return;
	}
	std::cout << "You can't increase your own reputation! \n";
}

int PowerUser::getReputation() const
{
	return Reputation;
}
