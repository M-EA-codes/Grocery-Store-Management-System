#pragma once
class cart		//managing cart
{
public:
	char cust_city[25];
	int prod_ids[50];
	int i;
	int prod_quans[50];

	cart(string cust = "", int prods[] = { 0 }, int cou = 0, int quans[] = { 0 })
	{
		strcpy_s(cust_city, cust.c_str());
		if(cou!=0)
		{
			while (prods[i] != 0)
			{
				prod_ids[i] = prods[i];
				cou++;
			}

			while (quans[i] != 0)
			{
				prod_quans[i] = quans[i];
			}
		}
		i = cou;
	}

	void add(int id, int quan)		//adding items in cart
	{
		prod_ids[i] = id;
		prod_quans[i] = quan;
		i++;
	}
};


class online_shopping		//managing online shoping
{
protected:
	int total_bill;
	cart crt;
public:
	bool add_to_cart(customer c)
	{
		int id;
		int quan;
		strcpy_s(crt.cust_city, c.get_city());
		cout << "\nPlease enter the Product ID of the product you want to buy: " << endl;
		cin >> id;

		cout << "\nPlease enter the Quantity of product of you want to buy: " << endl;
		cin >> quan;

		crt.add(id, quan);
		display_cart();
		deduct_quan(id, crt.cust_city, quan);
		return true;
	}

	int calculate_total_bill()	//calcuates total bill
	{
		total_bill = 0;
		int prod_price;
		string fileName = "catalog.dat";
		product temp;
		for (int i = 0; crt.prod_ids[i] != 0; i++)
		{
			ifstream myFile(fileName, ios::binary);
			while (myFile.read((char*)&temp, sizeof(temp))) {
				if (temp.getPid() == crt.prod_ids[i])
				{
					total_bill += (temp.getPrice() * crt.prod_quans[i]);
				}
				i++;
			}
		}
		return total_bill;
	}

	void display_cart()	//displays cart
	{
		cout << "\n" << setw(122) << "**********************************************************************************\n";
		cout << setw(65) << "*\t\t\t\t-: Displaying Cart :-\t\t\t\t*";
		cout << "\n" << setw(122) << "**********************************************************************************\n";
		product p;
		for (int i = 0; i < crt.i; i++)
		{
			p = p.retrieveProduct(crt.prod_ids[i], 'a');
			p.Display(p);
			cout << "Amount: " << p.getPrice() * crt.prod_quans[i] << endl;

		}
	}

	bool deduct_quan(int id, string file,int q)		//deducts quanitites of products from inventory
	{
		item temp;
		file = file + ".dat";
		fstream myFile(file, ios::in | ios::out | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.getPid() == id)
			{
				if (temp.getquantity() - q > 0)
				{
					temp.setquantity(temp.getquantity() - q);
				}
				else
				{
					temp.setquantity(0);
				}
				int current = myFile.tellg(); //will tell where is our pointer at current time
				int oneblock = sizeof(temp);
				myFile.seekg(current - oneblock); // seekg will move the pointer location
				myFile.write((char*)&temp, sizeof(temp));
				myFile.close();
				cout << setw(85) << "*\t\tItem Updated Successfully.\t\t\t*\n";
				return true;
			}
		}
		return false;
	}
};