#pragma once
#include"stores and inventory.h"
class manager :public user
{
protected:
	char city[15];
	store str;
public:
	manager(int u_t = 2, string u_n = "manager", string psd = "Manager123", string cit = "") :user(u_t, u_n, psd)
	{
		set_city(cit);
	}

	char* get_city()
	{
		return city;
	}

	store getStore()
	{
		return str;
	}

	void set_city(string cit)
	{
		strcpy_s(city, cit.c_str());
	}

	bool verify_credentials(string usn, string pasd)	//Polymorphically implemented function for validation of login credentials
	{
		char usnm[25];
		char paswd[30];
		strcpy_s(usnm, usn.c_str());
		strcpy_s(paswd, pasd.c_str());
		manager temp;
		bool flag = false;
		ifstream myFile("manager.dat", ios::binary);
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
		manager object = *this;
		object.getStore().setLocation(object.city);
		if (object.verify_credentials(object.get_username(), object.get_password()) == false)
		{
			ofstream myFile(file, ios::binary | ios::app);
			myFile.write((char*)&object, sizeof(object));
			myFile.close();
			cout << setw(80) << "\nManager Registered Successfully:" << endl;
			return true;
		}
		else
		{
			cout << setw(80) << "\nRegisteration Failed:" << endl;
			return false;
		}
	}

	manager return_manager(string fileName, string un, string up)
	{
		manager temp;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.get_username(), un.c_str() == 0) && (temp.get_password(),up.c_str() == 0))
			{
				myFile.close();
				return temp;
			}
		}
		return temp;
	}

	void Display()
	{
		string type = "Manager";

		cout << setw(80) << type << endl;
		cout << "Username: " << username<<"\n" << endl;
		cout << "City: " << city << "\n" << endl;
	}
};