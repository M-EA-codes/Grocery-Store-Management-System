#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
#include"user.h"
using namespace std;

class grocery_store
{
private:
	user person;
public:
	grocery_store(int u_t = 1, string u_n = "default", string psd = "Default@123") :person(u_t,u_n, psd)
	{

	}
};