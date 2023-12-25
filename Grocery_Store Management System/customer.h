#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
bool is_CNIC_valid(string);	//A function to check validity of CNIC

bool is_CNIC_unique(string);	//A function to check Uniqueness of CNIC



class customer :public user		//A class for customer
{
protected:
	char CNIC[15];
	char gender;
	char ph_no[12];
	char city[15];
	char full_address[50];
	char personal_info[30];
public:
	//Default and Parametrized constructor
	customer(int u_t = 3, string u_n = "custom", string psd = "Customer123", string cnic = "0000000000000", char gen = 'N', string phone = "00000000000", string cit = "", string addr = "", string per_info = "") :user(u_t, u_n, psd)
	{
		set_CNIC(cnic);
		set_gen(gen);
		set_ph(phone);
		set_city(cit);
		set_address(addr);
		set_per_info(per_info);
	}

	char get_gen()
	{
		return gender;
	}

	char* get_ph()
	{
		return ph_no;
	}

	char* get_city()
	{
		return city;
	}

	char* get_address()
	{
		return full_address;
	}

	char* get_per_info()
	{
		return personal_info;
	}

	char* get_CNIC()	//A Getter for CNIC
	{
		return CNIC;
	}

	customer getCustomer()
	{
		string fileName = "Customer.dat";
		customer temp;
		customer temp2 = *this;
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (strcmp(temp.get_username(), temp2.get_username()) == 0)
			{
				myFile.close();
				return temp;
			}
		}
		return temp;
	}

	void set_CNIC(string cnic)	// A setter for CNIC
	{
		bool done = false;
		if (cnic != "0000000000000")
		{
			while (done == false)
			{
				if (is_CNIC_valid(cnic) == true)
				{
					if (is_CNIC_unique(cnic) == true)
					{
						strcpy_s(CNIC, cnic.c_str());
						done = true;
					}
					else
					{
						cout << "\nAnother Customer already exist with this CNIC:\tKindly provide a unique CNIC:-\n";
							cin.clear();
							cin.ignore();
							getline(cin, cnic, '\n');
					}
				}
				else
				{
					cout << "\nPlease re-enter the correct CNIC again(without slashes): ";
					getline(cin, cnic);
				}
			}
		}
		else
		{
			strcpy_s(CNIC, cnic.c_str());
			done = true;
		}
	}

	void set_gen(char g)
	{
		while (g != 'M' && g != 'F' && g != 'T' && g != 'N')
		{
			cout << "\nIncorrect Gender:\t Please input gender in the form of 'M','F' or 'T': ";
			cin >> g;
		}
		gender = g;
	}

	void set_ph(string ph)
	{
		while (ph.length() != 11)
		{
			cout << "\nIncorrect Phone number:\t Please Input a valid phone number: ";
			cin>>ph;
		}
		strcpy_s(ph_no, ph.c_str());
	}

	void set_city(string cit)
	{
		strcpy_s(city, cit.c_str());
	}

	void set_address(string add)
	{
		strcpy_s(full_address, add.c_str());
	}

	void set_per_info(string per_info)
	{
		strcpy_s(personal_info, per_info.c_str());
	}

	void update_info()
	{
		string cnic = "000000000000";

		if (this->CNIC == "0000000000000")
		{
			while (is_CNIC_valid(cnic) != true)// && is_CNIC_unique(cnic) != true);
			{
				cout << setw(80) << "\nPlease Enter your CNIC no#: ";
				cin.clear();
				cin.ignore();
				getline(cin, cnic, '\n');
			}
			set_CNIC(cnic);
		}


		char gen = 'N';
		cout << setw(80) << "\nPlease Enter your gender('M','F' or 'T'): ";
		cin >> gen;
		set_gen(gen);

		string phone = "00000000000";
		cout << setw(80) << "\nPlease Enter your Phone no#: ";
		cin.clear();
		cin.ignore();
		getline(cin, phone, '\n');
		set_ph(phone);
		
		string cit = "";
		cin.clear();
		cin.ignore();
		cout << setw(80) << "\nPlease Enter your Current City: ";
		getline(cin, cit, '\n');
		set_city(cit);

		string addr = "";
		cout << setw(80) << "\nPlease Enter your full address: ";
		cin.clear();
		cin.ignore();
		getline(cin, addr, '\n');
		set_address(addr);

		string per_info = "";
		cout << setw(80) << "\nPlease Enter your Personal Info: ";
		cin.clear();
		cin.ignore();
		getline(cin, per_info, '\n');
		set_per_info(per_info);
	}
	bool verify_credentials(string usn, string pasd,string cnc)	////Polymorphically implemented function for validation of login credentials
	{
		char usnm[25];
		char paswd[30];
		char cnic[15];
		strcpy_s(usnm, usn.c_str());
		strcpy_s(paswd, pasd.c_str());
		strcpy_s(cnic, cnc.c_str());
		customer temp;
		bool flag = false;
		ifstream myFile("customer.dat", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)) && flag == false)	////compairing data from for login
		{
			bool u1 = false;
			bool p1 = false;
			bool c1 = false;

			if (strcmp(usnm, temp.get_username()) == 0)
			{
				u1 = true;
			}

			if (strcmp(paswd, temp.get_password()) == 0)
			{
				p1 = true;
			}

			if (strcmp(cnic, temp.get_CNIC()) == 0)
			{
				c1 = true;
			}

			if ((u1 == true) && (p1 == true) && (c1 == true))
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
		customer object = *this;
		if (object.verify_credentials(object.get_username(), object.get_password(), object.get_CNIC()) == false)
		{
			ofstream myFile(file, ios::binary | ios::app);
			myFile.write((char*)&object, sizeof(object));
			myFile.close();
			cout << setw(80) << "\nCustomer Registered Successfully:" << endl;
			return true;
		}
		else
		{
			cout << "\nRegistration Failed: " << endl;
			return false;
		}
	}

	void Display()
	{
		string type = "Customer";

		cout << setw(80) << type << endl;
		cout << "Username: " << username << endl;
		cout << "CNIC#: " << get_CNIC() << endl;
		cout << "Gender: " << gender << endl;
		cout << "Phone no# " << ph_no << endl;
		cout << "Current City: " << city << endl;
		cout << "Address: " << full_address << endl;
		cout << "Personal Info: " << personal_info << "\n\n" << endl;
	}
};



bool is_CNIC_valid(string cnic)	//A function to check validity of CNIC
{
	bool flag = true;
	int i = 0;
	while (i < cnic.size() && flag)
	{
		if (cnic[i] == '0' || cnic[i] == '1' || cnic[i] == '2' || cnic[i] == '3' || cnic[i] == '4' || cnic[i] == '5' || cnic[i] == '6' || cnic[i] == '7' || cnic[i] == '8' || cnic[i] == '9')
		{
			flag = true;
		}
		else
		{
			flag = false;
		}
		i++;
	}

	if (cnic.size() == 13 && flag)
	{
		//cout << "CNIC IS VALID:-" << endl;
		return true;
	}
	else
	{
		//cout << "CNIC IS NOT VALID:-" << endl;
		return false;
	}
}


bool is_CNIC_unique(string cnic)	//A function to check Uniqueness of CNIC
{
	char CNIC[15];
	strcpy_s(CNIC, cnic.c_str());
	customer temp;
	ifstream myFile("customer.dat", ios::binary);
	while (myFile.read((char*)&temp, sizeof(temp)))
	{
		if (strcmp(CNIC, temp.get_CNIC()) == 0)
		{
			myFile.close();
			return false;
		}
	}
	myFile.close();
	return true;
}