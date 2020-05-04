#pragma once
#include "Guest.h"

const int CRYPT_VALUE = 3;

class User: public Guest
{
protected: 
	friend class Admin;

	char* Username = nullptr;
	char* Password = nullptr;
	char* Title = nullptr;

	void setUsername(const char* username);
	void setPassword(const char* password);
	void setTitle(const char* title);

public:
	User(const char* ip = nullptr, const char* username = nullptr, const char* password = nullptr , const char* title=nullptr);
	User(const User & copyFrom);
	User & operator=(const User & copyFrom);

	void changePassword(const char* oldPassword, const char* newPassword);

	const char* getUsername() const;
	const char* getTitle() const;
	
	~User();

private:

};

char* crypt(char* password);
char* deCrypt(char* password);