#include "Admin.h"


Admin::Admin(const char* ip, const char* username, const char* password, const char* title) :User(ip, username, password, title)
{
}

void Admin::changeUsername(const char * username)
{
	setUsername(username);
}

void Admin::changeOtherUsername(User & user, const char * username)
{
	user.setUsername(username);
}
