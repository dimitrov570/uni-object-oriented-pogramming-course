#pragma once
#include "PowerUser.h"
#include "VIP.h"

class Admin: public PowerUser, virtual public VIP 
{
public:
	Admin(const char* ip, const char* username, const char* password, const char* title);

	void changeUsername(const char* username);
	void changeOtherUsername(User &user, const char* username);

private:

};