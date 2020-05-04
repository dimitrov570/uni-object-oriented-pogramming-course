#include "User.h"
#include <iostream>


void User::setUsername(const char * username)
{
	if (username == nullptr)
	{
		return;
	}
	delete[] Username;
	Username = new char[strlen(username) + 1];
	strcpy(Username, username);
}

void User::setPassword(const char * password)
{
	if (password == nullptr)
	{
		return;
	}
	delete[] Password;
	Password = new char[strlen(password) + 1];
	strcpy(Password, password);

	crypt(Password);
}

void User::setTitle(const char * title)
{
	if (title == nullptr)
	{
		return;
	}
	delete[] Title;
	Title = new char[strlen(title) + 1];
	strcpy(Title, title);
}

User::User(const char* ip, const char* username, const char* password, const char* title) :Guest(ip)
{
	setUsername(username);
	setPassword(password);
	setTitle(title);
}

User::User(const User & copyFrom):Guest(copyFrom.ipAdress)
{
	setUsername(copyFrom.Username);
	setPassword(copyFrom.Username);
	setTitle(copyFrom.Title);
}

User & User::operator=(const User & copyFrom)
{
	if (this != &copyFrom)
	{
		setIP(copyFrom.ipAdress);
		setUsername(copyFrom.Username);
		setPassword(copyFrom.Username);
		setTitle(copyFrom.Title);
	}
	return *this;
}

const char * User::getUsername() const
{
	return Username;
}

const char * User::getTitle() const
{
	return Title;
}

void User::changePassword(const char * oldPassword, const char* newPassword)
{
	deCrypt(Password);
	if (!strcmp(Password, oldPassword)) 
	{
		setPassword(newPassword);
		std::cout << "Password changed successfuly! \n";
		return;
	}
	std::cout << "Wrong password! \n";
	crypt(Password); //Password needs to be crypted again
}

User::~User()
{
	delete[] Username;
	delete[] Password;
	delete[] Title;
}

char* crypt(char * password)
{
	for (int i = 0; i < strlen(password); ++i)
	{
		password[i] += CRYPT_VALUE + i;
	}
	return password;
}

char* deCrypt(char * password)
{
	for (int i = 0; i < strlen(password); ++i)
	{
		password[i] -= CRYPT_VALUE + i;
	}

	return password;
}
