#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


bool is_username_valid(string un)	//A function to check validity of username
{
	bool flag = true;
	int i = 0;
	while (i < un.length() && flag == true)
	{
		if (un[i] >= 65 && un[i] <= 90 || (un[i] == 32))
		{
			flag = true;
		}
		else if (un[i] >= 97 && un[i] <= 122)
		{
			flag = true;
		}
		else
		{
			//cout << "\nUsername is not valid:- " << endl;
			return false;
		}
		i++;
	}

	if (flag == true)
	{
		//cout << "\nUsername is valid:-" << endl;
	}
		return flag;
}

bool is_password_valid(string pswd)	//A function to check validity of Password
{
	bool flag = true;
	bool has_capital = false;
//	bool has_small = false;
	bool has_number = false;
//	bool has_character = false;
	int i = 0;
	while (i < pswd.length() && flag == true)
	{
		if (pswd.length() >= 9)
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
		if (pswd[i] >= 65 && pswd[i] <= 90)
		{
			//flag = true;
			has_capital = true;
		}

		if (pswd[i] >= 48 && pswd[i] <= 57)
		{
			//flag = true;
			has_number = true;
		}
		i++;
	}

	if ((has_capital == true) && (flag == true) && (has_number == true))
	{
		//cout << "\nPassword is valid:-" << endl;
		return true;
	}
	else
	{
		return false;
	}
	//cout << "Returning flag: " << flag << endl;
	//return flag;
}

class user
{
protected:
	int user_type;
	char username[20];
	char password[20];
public:
	//Default and Parametrized Constructor
	user(int u_t = 1, string u_n = "default", string psd = "Default123")
	{
		user_type = u_t;
		//cout << "Usertype assigned: " << endl;
		set_username(u_n);
		//cout << "Username Set successfully: " << endl;
		set_password(psd);
		//cout<<"Password Set successfully: "<<endl;

	}


	void set_username(string un)	////A setter for username
	{
		bool done = false;
		while (done == false)
		{
			if (is_username_valid(un) == true)
			{
				strcpy_s(username, un.c_str());
				done = true;
			}
			else
			{
				cout << "\nPlease re-enter the correct Username again: ";
				getline(cin, un);

				if (is_username_valid(un) == true)
				{
					strcpy_s(username, un.c_str());
					done = true;
				}
			}
		}
	}

	void set_password(string psd)//A setter for password
	{
		bool done = false;
		bool valid = false;
		string psd2;
		while (done != true)
		{
			//cout << "Before validation: " << endl;
			valid = is_password_valid(psd);
			if (valid == true)
			{
				//cout << "Before copying: " << endl;
				strcpy_s(password, psd.c_str());

				if (psd == "Admin12345" || psd == "Customer123" || psd == "Manager123" || psd == "Default123")
				{
					done = true;
				}
			}
			else
			{
				cin.clear();
				cin.ignore();
				cout << "\nPlease re-enter the correct Password again: ";
				getline(cin, psd, '\n');
			}

			if ((valid == true) && psd != "Admin12345" && psd != "Customer123" && psd != "Manager123" && psd != "Default123")
			{
				cin.clear();
				cin.ignore();
				cout << "\nPlease re-enter the Password again to confirm: ";
				getline(cin, psd2, '\n');

				if (!(strcmp(psd.c_str(), psd2.c_str())))
				{
					done = true;
				}
				else
				{
					done = false;
				}
			}
		}
	}


	char* get_username()//A Getter for Username
	{
		return username;
	}

	char* get_password()	//A Getter for Password
	{
		return password;
	}

	// Copy constructor
	user(const user& u1)
	{
		user_type = u1.user_type;
		strcpy_s(username, u1.username);
		strcpy_s(password, u1.password);
	}

	virtual bool verify_credentials(string, string)
	{
		return true;
	}

	virtual bool Registration(string file)		//For Registration
	{
		return true;
	}

	virtual bool verify_credentials(string, string, string)
	{
		return true;
	}

	virtual void Display()
	{

	}

	virtual void update_info()
	{}

	template<typename T>
	bool DisplayAll(string file, T& object)
	{
		T temp;
			ifstream myFile(file, ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp)))
			{
				temp.Display();
			}
			myFile.close();
		return true;
	}

	~user()
	{
	}
};