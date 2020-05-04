#pragma once
#include "User.h"

class VIP: virtual public User
{

public:
	VIP(const char* ip = nullptr, const char* username = nullptr, const char* password = nullptr, const char* title = nullptr);
	void changeTitle(const char* title);

};