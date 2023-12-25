#pragma once

class product		//class to store products
{
protected:
	int p_id;
	char item_type;
	char catagory[20];
	char sub_catagory[20];
	char p_name[20];
	int price;
	char unit;
public:
	product(int id = 0, char i_type = '\0', string cat = "", string subcat = "", string nam = "", int pric = 0, char uni = '\0')
	{
		setPid(id);
		setItemtype(i_type);
		setCatagory(cat);
		setSubcatagory(subcat);
		setPname(nam);
		setPrice(pric);
		setUnit(uni);
	}

	int getPid() const
	{
		return p_id;
	}

	char getItemtype() const
	{
		return item_type;
	}

	char* getCatagory()
	{
		return catagory;
	}

	char* getSubcatagory()
	{
		return sub_catagory;
	}


	char* getPname()
	{
		return p_name;
	}

	int getPrice() const
	{
		return price;
	}

	char getUnit() const
	{
		return unit;
	}

	void setPid(int id) 
	{
		if (id < 0)
		{
			id = 0;
		}

		p_id = id;
	}

	void setItemtype(char itype)
	{
		if (itype != '\0')
		{
			while (itype != 'F' && itype != 'P' && itype != 'H')
			{
				cout << "\nPlease Enter a valid Product Type: (Food = F, Personal Hygiene = P, Household Cleaning = H)" << endl;
				cin >> itype;
			}
		}
		item_type = itype;

	}

	void setCatagory(string cat)
	{
		if (cat != "" && strcmp(cat.c_str(), "1234") != 0)
		{
			while ((strcmp(cat.c_str(), "Perishable") != 0) && (strcmp(cat.c_str(), "Non-Perishable") != 0))
			{
				cin.clear();
				cin.ignore();
				cout << "\nPlease Enter a valid catagory: (Perishable or Non-Perishable)" << endl;
				getline(cin, cat, '\n');
			}
		}
		if (strcmp(cat.c_str(), "1234") == 0)
		{
			cat = "\0";
		}


		strcpy_s(catagory, cat.c_str());
	}

	void setSubcatagory(string s_cat)
	{
		if (s_cat != "")
		{
			if ((strcmp(catagory, "Perishable")) == 0)
			{
				bool meat = false;
				bool dairy = false;
				bool fruit = false;
				bool vegetable = false;



				while ((meat == false) && (dairy == false) && (fruit == false) && (vegetable == false))
				{
					cin.clear();
					cin.ignore();
					cout << "\nPlease Enter a valid sub-catagory:  (Meat, Dairy, Fruit, Vegetable)" << endl;
					getline(cin, s_cat, '\n');
					meat = false;
					dairy = false;
					fruit = false;
					vegetable = false;
					if (strcmp(s_cat.c_str(), "Meat") == 0)
					{
						meat = true;
					}
					if (strcmp(s_cat.c_str(), "Dairy") == 0)
					{
						dairy = true;
					}
					if (strcmp(s_cat.c_str(), "Fruit") == 0)
					{
						fruit = true;
					}
					if (strcmp(s_cat.c_str(), "Vegetable") == 0)
					{
						vegetable = true;
					}
				}
			}

			if (strcmp(catagory, "Non-Perishable") == 0)
			{
				bool Snacks = false;
				bool Spices = false;
				bool Grains = false;
				bool cereals = false;
				while ((Snacks == false) && (Spices == false) && (Grains == false) && (cereals == false)) {
					cin.clear();
					cin.ignore();
					cout << "\nPlease Enter a valid sub-catagory: (Snacks, Spices, Grains, Cereal)" << endl;
					getline(cin, s_cat, '\n');
					Snacks = false;
					Spices = false;
					Grains = false;
					cereals = false;
					if (strcmp(s_cat.c_str(), "Snacks") == 0)
					{
						Snacks = true;
					}
					if (strcmp(s_cat.c_str(), "Spices") == 0)
					{
						Spices = true;
					}
					if (strcmp(s_cat.c_str(), "Grains") == 0)
					{
						Grains = true;
					}
					if (strcmp(s_cat.c_str(), "Cereal") == 0)
					{
						cereals = true;
					}

				}
			}
		}

		if (strcmp(s_cat.c_str(), "1234") == 0)
		{
			s_cat = "\0";
		}
		strcpy_s(sub_catagory, s_cat.c_str());
	}

	void setPname(string name)
	{
		strcpy_s(p_name, name.c_str());
	}

	void setPrice(int pri)
	{
		while (pri < 0)
		{
			cout << "\nPlease Enter a valid price for the product:" << endl;
			cin >> pri;
		}
		price = pri;
	}

	void setUnit(char uni)
	{
		if (uni != '\0')
		{
			while (uni != 'K' && uni != 'L' && uni != 'D' && uni != 'l' && uni!='I')
			{
				cout << "\nPlease Enter a valid unit: (Kg = K, L = liter, D = Dozens, l = Pound , I = Item):" << endl;
				cin >> uni;
			}
		}
		unit = uni;
	}

	void Display(product temp) const
	{
		string type = "-:Product no# ";
		string it = "";
		bool dis = false;
		if (temp.getItemtype() == 'F')
		{
			it = "Food";
			dis = true;
		}

		if (temp.getItemtype() == 'P')
		{
			it = "Personal Hygiene";

		}
		if (temp.getItemtype() == 'H')
		{
			it = "Household Cleaning";
		}

		cout << setw(80) << type << temp.getPid() << " :-" << endl;
		cout << "Product Name: " << temp.getPname() << endl;
		cout << "Item Type: " << it << endl;
		if (dis==true)
		{
			cout << "Catagory: " << temp.getCatagory() << endl;
			cout << "Sub-Catagory: " << temp.getSubcatagory() << endl;

		}

		if (temp.getUnit() == 'K')
		{
			it = "Kg";
		}

		if (temp.getUnit() == 'L')
		{
			it = "liter";
		}

		if (temp.getUnit() == 'D')
		{
			it = "Dozen";
		}

		if (temp.getUnit() == 'l')
		{
			it = "lb(Pound)";
		}

		if (temp.getUnit() == 'I')
		{
			it = "Item";
		}
		cout << "Price Per " << it << "= " << temp.getPrice() << endl;
		cout << "\n";
	}
	

	product retrieveProduct(int id, char dummy)
	{
		string fileName = "catalog.dat";
		product temp(0);
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getPid() == id)
			{
				myFile.close();
				return temp;
			}
		}
		temp.setPid(0);
		return temp;
		cout << "Invalid Input: No Such Product ID exist in Catalog" << endl;
	}


};
//
//class Food :public product
//{
//protected:
//	char catagory[10];
//	char sub_catagory[10];
//
//public:
//	Food(int id = 0, char i_type = '\0', string cat = "", string subcat = "", string nam = "", int pric = 0, char uni = '\0') :product(id, i_type, nam, pric, uni)
//	{
//		setCatagory(cat);
//		setSubcatagory(subcat);
//	}
//
//	char* getCatagory()
//	{
//		return catagory;
//	}
//
//	char* getSubcatagory()
//	{
//		return sub_catagory;
//	}
//
//
//
//	void setCatagory(string cat)
//	{
//		if (cat != "")
//		{
//		}
//
//		strcpy_s(catagory, cat.c_str());
//	}
//
//	void setSubcatagory(string s_cat)
//	{
//		strcpy_s(sub_catagory, s_cat.c_str());
//	}
//};


product updating()
{
	int id = 0;
	char i_type = '\0';
	string cat = "1234";
	string subcat = "1234";
	string name = "";
	int price = 0;
	char unit = '\0';
	cout << setw(85) << "*\t\tAdd updated Details of Product.\t\t\t*\n";


	while (i_type != 'F' && i_type != 'P' && i_type != 'H')
	{
		cout << "\nPlease Enter a valid Product Type: (Food = F, Personal Hygiene = P, Household Cleaning = H)" << endl;
		cin >> i_type;
	}


	if (i_type == 'F')
	{
		bool p = false;
		bool n = false;

		while (n != true && p != true)
		{
			//						cin.clear();

			cout << "\nPlease Enter a valid catagory: (Perishable or Non-Perishable)" << endl;
			cin.ignore();
			getline(cin, cat, '\n');

			if (strcmp(cat.c_str(), "Perishable") == 0 || strcmp(cat.c_str(), "erishable") == 0)
			{
				p = true;
			}

			if (strcmp(cat.c_str(), "Non-Perishable") == 0 || strcmp(cat.c_str(), "on-Perishable") == 0)
			{
				n = true;
			}
		}
	}

	cin.clear();
	cin.ignore();
	cout << "\nPlease Enter Product Name you want to Add: " << endl;
	getline(cin, name, '\n');
	cout << "\nPlease Enter a valid price for the product:" << endl;
	cin >> price;
	cout << "\nPlease Enter a valid unit: (Kg = K, L = liter, D = Dozens, l = Pound, I = Item):" << endl;
	cin >> unit;

	product P(id, i_type, cat, subcat, name, price, unit);
	return P;
}


class product_catalog
{
protected:
	product prod;
public:
	product_catalog(int id = 0, char i_type = '\0', string cat = "", string subcat = "", string name = "", int price = 0, char unit = '\0') :prod(id, i_type, cat, subcat, name, price, unit)
	{}

	bool add_product(product& obj)
	{
		ofstream myFile("catalog.dat", ios::binary | ios::app);
		myFile.write((char*)&obj, sizeof(obj));
		myFile.close();
		cout << setw(80) << "\nNew Product Added Successfully:" << endl;
		return true;
	}

	bool update_product(int id, string prod_name)
	{
		product temp;
		fstream myFile("catalog.dat", ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.getPid() == id) && (strcmp(temp.getPname(), prod_name.c_str()) == 0))
			{
				product temp2;
				temp2=updating();
				temp2.setPid(id);
				temp = temp2;
				int current = myFile.tellg(); //will tell where is our pointer at current time
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock); // seekg will move the pointer location
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
				cout << setw(85) << "*\t\tProduct Updated Successfully.\t\t\t*\n";
				return true;
			}
		}
		cout << setw(85) << "*\t\tProduct Updating Failed: (No Such Product Exist in Catalog)\t\t\t*\n";
		return false;
	}

	bool remove_product(int num, string name)
	{
		product temp;
		bool flag = false;
		fstream myFile("catalog.dat", ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.dat", ios::app | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) 
		{
			if ((temp.getPid() != num) && (strcmp(temp.getPname(), name.c_str()) != 0))
			{
				myFile_temp.write((char*)&temp, sizeof(temp));
			}
			else
			{
				cout << "Product Removed Successfully:" << endl;
				flag = true;
			}
		}
		
		if (flag == false)
		{
			cout << "Removing Object Failed: (No Product exist with such Product ID and Name)" << endl;
		}

		myFile.close();
		myFile_temp.close();
		remove("catalog.dat");
		int n = rename("temp.dat", "catalog.dat");
		return flag;
	}

	product retrieveProduct(int id) 
	{
		string fileName = "catalog.dat";
		product temp(0);
		ifstream myFile(fileName, ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp))) {
			if (temp.getPid() == id) 
			{
				myFile.close();
				return temp;
			}
		}
		temp.setPid(0);
		return temp;
		cout << "Invalid Input: No Such Product ID exist in Catalog" << endl;
	}

	void setProd(product P)
	{
		prod = P;
	}

	product& getProd()
	{
		return prod;
	}


	void Display_items() const
	{
		cout << "\n" << setw(122) << "**********************************************************************************\n";
		cout << setw(83) << "*\t\t\tDisplaying all Products in Catalog.\t\t\t*\n";
		cout << setw(122) << "**********************************************************************************\n";


		product temp;
		ifstream myFile("catalog.dat", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			temp.Display(temp);
		}
		myFile.close();
	}
};

//
//class product
//{
//protected:
//	int p_id;
//	char item_type;
//	char p_name[10];
//	int price;
//	char unit;
//public:
//	product(int id = 0, char i_type = '\0', string nam = "", int pric = 0, char uni = '\0')
//	{
//		setPid(id);
//		setItemtype(i_type);
//		setPname(nam);
//		setPrice(pric);
//		setUnit(uni);
//	}
//
//	int getPid()
//	{
//		return p_id;
//	}
//
//	char getItemtype()
//	{
//		return item_type;
//	}
//
//	char* getPname()
//	{
//		return p_name;
//	}
//
//	int getPrice()
//	{
//		return price;
//	}
//
//	char getUnit()
//	{
//		return unit;
//	}
//
//	void setPid(int id)
//	{
//		if (id < 0)
//		{
//			id = 0;
//		}
//
//		p_id = id;
//	}
//
//	void setItemtype(char itype)
//	{
//		if (itype != '\0')
//		{
//		}
//		item_type = itype;
//
//	}
//
//	void setPname(string name)
//	{
//		strcpy_s(p_name, name.c_str());
//	}
//
//	void setPrice(int pri)
//	{
//		price = pri;
//	}
//
//	void setUnit(char uni)
//	{
//		unit = uni;
//	}
//
//};
//
//class Food :public product
//{
//protected:
//	char catagory[10];
//	char sub_catagory[10];
//
//public:
//	Food(int id = 0, char i_type = '\0', string cat = "", string subcat = "", string nam = "", int pric = 0, char uni = '\0') :product(id, i_type, nam, pric, uni)
//	{
//		setCatagory(cat);
//		setSubcatagory(subcat);
//	}
//
//	char* getCatagory()
//	{
//		return catagory;
//	}
//
//	char* getSubcatagory()
//	{
//		return sub_catagory;
//	}
//
//
//
//	void setCatagory(string cat)
//	{
//		if (cat != "")
//		{
//		}
//
//		strcpy_s(catagory, cat.c_str());
//	}
//
//	void setSubcatagory(string s_cat)
//	{
//		strcpy_s(sub_catagory, s_cat.c_str());
//	}
//};
//
//class product_catalog
//{
//protected:
//	product prod;
//public:
//	product_catalog(int id = 0, char type = '\0', string name = "", int price = 0, char unit = '\0') :prod(id, type, name, price, unit)
//	{}
//
//	bool add_product(product& obj)
//	{
//
//	}
//};