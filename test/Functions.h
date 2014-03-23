#pragma once
#include "header.h"
#include <string>
#include "string.h"

using namespace std;

struct user{
	string login;
	string passw;
};





void signup();
void signin();
void logon(string ussername);
void OS(string username);
void logoff(string usn);
void chpsw(string un);
bool authorize(user ul);
bool fe(string path);