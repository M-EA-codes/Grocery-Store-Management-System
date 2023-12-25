#pragma once
#include"product _catalog.h"


class item		//class to store items
{
protected:
	int p_id;
	char item_type;
	char catagory[20];
	char sub_catagory[20];
	char p_name[20];
	int price;
	char unit;
	int quan;
public:
	item(int id = 0, char i_type = '\0', string cat = "", string subcat = "", string nam = "", int pric = 0, char uni = '\0',int qunt = 0)
	{
		setPid(id);
		setItemtype(i_type);
		setCatagory(cat);
		setSubcatagory(subcat);
		setPname(nam);
		setPrice(pric);
		setUnit(uni);
		setquantity(qunt);
	}
	//////////////////////////////Getters and Setters are Implemented\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	
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

	int getquantity()
	{
		return quan;
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
				cout << "\nPlease Enter a valid item Type: (Food = F, Personal Hygiene = P, Household Cleaning = H)" << endl;
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
			cout << "\nPlease Enter a valid price for the item:" << endl;
			cin >> pri;
		}
		price = pri;
	}

	void setUnit(char uni)
	{
		if (uni != '\0')
		{
			while (uni != 'K' && uni != 'L' && uni != 'D' && uni != 'l' && uni != 'I')
			{
				cout << "\nPlease Enter a valid unit: (Kg = K, L = liter, D = Dozens, l = Pound , I = Item):" << endl;
				cin >> uni;
			}
		}
		unit = uni;
	}

	void setquantity(int qunt)
	{
		do
		{
			if (qunt < 0)
			{
				cout << "Enter a valid quantity: ";
				cin >> qunt;
			}
			quan = qunt;
		} while (qunt < 0);
	}


	void Display(item temp) const
	{
		string type = "-:Item no# ";
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
		cout << "item Name: " << temp.getPname() << endl;
		cout << "Item Type: " << it << endl;
		if (dis == true)
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
		cout << "Quantity " << "= " << temp.getquantity() << endl;
		cout << "\n";
	}


};

item update_item()
{
	int id = 0;
	char i_type = '\0';
	string cat = "1234";
	string subcat = "1234";
	string name = "";
	int price = 0;
	char unit = '\0';
	int qun = -1;
	cout << setw(85) << "*\t\tAdd updated Details of Item.\t\t\t*\n";


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

	item iem(id, i_type, cat, subcat, name, price, unit, qun);
	return iem;
}


class inventory
{
protected:
	item itm;
public:
	inventory()
	{}

	bool add_item(string City)
	{
		City = City + ".dat";
		product_catalog P(1);
		int id;
		do
		{
			cout << "Please Enter the Product ID of the product from catalog to add into Inventory: " << endl;
			P.Display_items();
			cout << "Please Enter the Product ID of the product from catalog to add into Inventory: " << endl;
			cin >> id;

			if (P.retrieveProduct(id).getPid() != 0)
			{
				cout << "\nProduct with given below details is added to Inventory: " << endl;
			}

		} while (P.retrieveProduct(id).getPid() == 0);

		P.setProd(P.retrieveProduct(id));

		P.getProd().Display(P.getProd());

		itm.setPid(P.getProd().getPid());
		itm.setItemtype(P.getProd().getItemtype());
		itm.setCatagory(P.getProd().getCatagory());
		itm.setSubcatagory(P.getProd().getSubcatagory());
		itm.setPname(P.getProd().getPname());
		itm.setPrice(P.getProd().getPrice());
		itm.setUnit(P.getProd().getUnit());
		itm.setquantity(-2);
		ofstream myFile(City, ios::binary | ios::app);
		myFile.write((char*)&itm, sizeof(itm));
		myFile.close();
		cout << setw(80) << "\nNew Product Added to the Inventory Successfully:" << endl;
		return true;
	}

	bool update_items(int id, string item_name,string file)
	{
		item temp;
		file = file + ".dat";
		fstream myFile(file, ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.getPid() == id) && (strcmp(temp.getPname(), item_name.c_str()) == 0))
			{
				item temp2;
				temp2 = update_item();
				temp2.setPid(id);
				temp = temp2;
				int current = myFile.tellg(); //will tell where is our pointer at current time
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock); // seekg will move the pointer location
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
				cout << setw(85) << "*\t\tItem Updated Successfully.\t\t\t*\n";
				return true;
			}
		}
		cout << setw(85) << "*\t\tItem Updating Failed: (No Such Item Exist in Inventory)\t\t\t*\n";
		return false;
	}

	bool remove_item(int num, string name,string c_name)
	{
		item temp;
		bool flag = false;
		c_name = c_name + ".dat";
		
		fstream myFile(c_name, ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.dat", ios::app | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if ((temp.getPid() != num) && (strcmp(temp.getPname(), name.c_str()) != 0))
			{
				myFile_temp.write((char*)&temp, sizeof(temp));
			}
			else
			{
				cout << "Item Removed Successfully:" << endl;
				flag = true;
			}
		}

		if (flag == false)
		{
			cout << "Removing Item Failed: (No Item exist with such Item ID and Name)" << endl;
		}

		myFile.close();
		myFile_temp.close();
		remove(c_name.c_str());
		int n = rename("temp.dat", c_name.c_str());
		return flag;
	}

	void display_all_items(string City)
	{
		City = City + ".dat";
		cout << "\n" << setw(122) << "**********************************************************************************\n";
		cout << setw(83) << "*\t\t\tDisplaying all Items in Inventory.\t\t\t*\n";
		cout << setw(122) << "**********************************************************************************\n";
		ifstream myFile(City, ios::binary);
		while (myFile.read((char*)&itm, sizeof(itm)))
		{
			itm.Display(itm);
		}
		myFile.close();
	}
};


class store
{
protected:
	char location[15];
	inventory inv;
public:
	store(string loc = "")
	{
		setLocation(loc);
		inv;
	}

	void setLocation(string cit)
	{
		strcpy_s(location, cit.c_str());
	}

	inventory getInv()
	{
		return inv;
	}
};