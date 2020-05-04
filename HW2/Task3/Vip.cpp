#include "Vip.h"


VIP::VIP(const char* ip, const char* username, const char* password, const char* title) :User(ip, username, password, title)
{}

void VIP::changeTitle(const char * title)
{
	setTitle(title);
}