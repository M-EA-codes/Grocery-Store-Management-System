#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;


//An Admin Class
class Admin :public user
{
protected:

public:
	Admin(int u_t = 1,string u_n = "admin", string psd = "Admin12345") :user(u_t,u_n, psd)
	{

	}

	// Copy constructor
	Admin(const Admin& A1)
	{
		user_type = A1.user_type;
		strcpy_s(username, A1.username);
		strcpy_s(password, A1.password);
	}

	bool verify_credentials(string usn, string pasd)	//Polymorphically implemented function for validation of login credentials
	{
		char usnm[25];
		char paswd[30];
		strcpy_s(usnm, usn.c_str());
		strcpy_s(paswd, pasd.c_str());
		Admin temp;
		bool flag = false;
		ifstream myFile("admin.dat", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)) && flag == false)		//compairing data from for login
		{
			bool u1 = false;
			bool p1 = false;

			if (strcmp(usnm, temp.get_username()) == 0)
			{
				u1 = true;
			}

			if (strcmp(paswd, temp.get_password()) == 0)
			{
				p1 = true;
			}

			if ((u1 == true) && (p1 == true))
			{
				cout << "\nUsername and Password exist:" << endl;
				return true;
				myFile.close();
			}

		}
		cout << "\nNo User exist with this Username and Password:" << endl;  //Incase of invalid credentials
		return false;
	}


	bool Registration(string file)		//For Registration
	{
		Admin object = *this;
		if (object.verify_credentials(object.get_username(), object.get_password()) == false)
		{
			ofstream myFile(file, ios::binary | ios::app);
			myFile.write((char*)&object, sizeof(object));
			myFile.close();
			cout << setw(80) << "\nAdmin Registered Successfully:" << endl;
			return true;
		}
		else
		{
			cout << setw(80) << "\nRegisteration Failed:" << endl;
			return false;
		}
	}

	void Display()
	{
		string type = "Admin";

		cout << setw(80) << type << endl;
		cout << "Username: " << username <<"\n"<< endl;
	}
};