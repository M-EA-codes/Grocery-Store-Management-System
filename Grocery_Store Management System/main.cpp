#include<iostream>
#include<fstream>
#include<iomanip>
#include"grocery_store.h"
#include"user.h"
#include"admin.h"
#include"customer.h"
#include"manager.h"
#include"product _catalog.h"
#include"stores and inventory.h"
#include"online_shoping.h"
#include"Feedback.h"
#include"Payment.h"
#include<string>
#include<string.h>
using namespace std;

int main()
{
	bool main_menu = true;
	bool login_menu = false;
	bool reg_menu = false;
	bool admin_menu = false;
	bool manager_menu = false;
	bool customer_menu = false;
	bool managing_inventory = false;
	bool managing_catalog = false;
	bool payment_menu = false;
	int choice = 0;
	int total = 0;
	int i = 0;
	string unm;
	string pssd;
	user* User = new Admin;

	while (true)
	{
		while (main_menu)		//Main Menu
		{
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(80) << "*\t\t\t-: Welcome to My Grocery Store :-\t\t\t*";
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(81) << "*\t\t\t1)- Login.\t\t\t*\n";
			cout << setw(84) << "*\t\t\t2)- Register.\t\t\t*\n";
			cout << setw(92) << "*\t\t\t3)- Display All Users.\t\t*\n";
			cout << setw(80) << "*\t\t\t0)- Exit.\t\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cin >> choice;


			switch (choice)
			{

			case 1:
			{
				login_menu = true;
				main_menu = false;
				break;
			}
			case 2:
			{
				reg_menu = true;
				main_menu = false;
				break;
			}

			case 3:			//Displays All users of every type
			{
				cout << setw(81) << "*\t\t\t0)- Display Customers.\t\t\t*\n";
				cout << setw(81) << "*\t\t\t1)- Display Admins.\t\t\t*\n";
				cout << setw(81) << "*\t\t\t2)- Display Managers.\t\t\t*\n";
				cin >> choice;

				if (choice == 0)
				{
					customer A;
					A.DisplayAll<typename customer>("Customer.dat", A);
				}

				if (choice == 1)
				{
					Admin A;
					A.DisplayAll<typename Admin>("admin.dat", A);
				}
				if (choice == 2)
				{
					manager A;
					A.DisplayAll<typename manager>("manager.dat", A);
				}
				break;
			}

			case 0:
			{
				cout << setw(95) << "******\t\tThank You for Shopping\t\t******";
				exit(0);
				break;
			}

			default:
			{
				cout << setw(80) << "*\t\t\tPlease Enter a valid Number from 0-3:-\t\t\t*\n";
			}
			}
		}

		while (login_menu)		//Login Menu
		{
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(65) << "*\t\t\t\t-: Login Menu :-\t\t\t\t*";
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(80) << "*\t\t\t1)- Login as Admin.\t\t\t*\n";
			cout << setw(82) << "*\t\t\t2)- Login as Manager.\t\t\t*\n";
			cout << setw(83) << "*\t\t\t3)- Login as Customer.\t\t\t*\n";
			cout << setw(71) << "*\t\t\t0)- Back.\t\t\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(73) << "*\t\t\t\t-: Logging in as Admin :-\t\t\t*";
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				string temp_username;
				string temp_password;
				cout << setw(80) << "*\t\t\tPlease Enter your Username: \t\t\t*\n";
				cin.clear();
				cin.ignore();
				getline(cin, temp_username, '\n');

				cout << setw(80) << "*\t\t\tPlease Enter your Password: \t\t\t*\n";
				cin.clear();
				getline(cin, temp_password, '\n');

				User = new Admin;
				if (User->verify_credentials(temp_username, temp_password) == true)
				{
					cout << "\nLogged in Successfully:-" << endl;
					unm = temp_username;
					pssd = temp_password;
					login_menu = false;
					admin_menu = true;
				}
				break;
			}
			case 2:
			{
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(73) << "*\t\t\t\t-: Logging in as Manager :-\t\t\t*";
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				string temp_username;
				string temp_password;
				cout << setw(80) << "*\t\t\tPlease Enter your Username: \t\t\t*\n";
				cin.clear();
				cin.ignore();
				getline(cin, temp_username, '\n');

				cout << setw(80) << "*\t\t\tPlease Enter your Password: \t\t\t*\n";
				cin.clear();
				getline(cin, temp_password, '\n');

				User = new manager;
				if (User->verify_credentials(temp_username, temp_password) == true)
				{
					cout << "\nLogged in Successfully:-" << endl;
					unm = temp_username;
					pssd = temp_password;
					login_menu = false;
					manager_menu = true;
				}
				break;
			}
			case 3:
			{
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(76) << "*\t\t\t\t-: Logging in as Customer :-\t\t\t*";
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				string temp_username;
				string temp_password;
				string cn;
				cout << setw(80) << "*\t\t\tPlease Enter your Username: \t\t\t*\n";
				cin.clear();
				cin.ignore();
				getline(cin, temp_username, '\n');


				cout << setw(80) << "*\t\t\tPlease Enter your Password: \t\t\t*\n";
				cin.clear();
				getline(cin, temp_password, '\n');

				cout << setw(80) << "*\t\t\tPlease Enter your CNIC no#: \t\t\t*\n";
				cin.clear();
				getline(cin, cn, '\n');

				User = new customer;
				if (User->verify_credentials(temp_username, temp_password, cn) == true)
				{
					unm = temp_username;
					pssd = temp_password;
					login_menu = false;
					customer_menu = true;
				}
				break;
			}
			case 0:
			{
				login_menu = false;
				main_menu = true;
				break;
			}
			default:
			{
				cout << setw(80) << "*\t\t\tPlease Enter a valid Number from 0-3:-\t\t\t*\n";
				break;
			}
			}
		}

		while (reg_menu)		//Registration
		{
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(72) << "*\t\t\t\t-: Registration Menu :-\t\t\t\t*";
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(85) << "*\t\t\t1)- Register a new Admin.\t\t*\n";
			cout << setw(88) << "*\t\t\t2)- Register a new Customer.\t\t*\n";
			cout << setw(71) << "*\t\t\t0)- Back.\t\t\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				string temp_username;
				string temp_password;
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(80) << "*\t\t\tRegistering a new Admin: \t\t\t*\n\n";
				cout << setw(80) << "*\t\t\tPlease Enter your Username: \t\t\t*\n";

				cin.clear();
				cin.ignore();
				getline(cin, temp_username, '\n');

				cout << setw(80) << "*\t\t\tPlease Enter your Password: \t\t\t*\n";
				cin.clear();
				getline(cin, temp_password);

				User = new Admin(1, temp_username, temp_password);
				User->Registration("admin.dat");
				break;
			}
			case 2:
			{
				string temp_username;
				string temp_password;
				string cn;
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(80) << "*\t\t\tRegistering a new Customer: \t\t\t*\n\n";
				cout << setw(80) << "*\t\t\tPlease Enter your Username: \t\t\t*\n";
				cin.clear();
				cin.ignore();
				getline(cin, temp_username, '\n');

				cout << setw(80) << "*\t\t\tPlease Enter your CNIC no#: \t\t\t*\n";
				cin.clear();
				getline(cin, cn, '\n');

				cout << setw(80) << "*\t\t\tPlease Enter your Password: \t\t\t*\n";
				cin.clear();
				getline(cin, temp_password, '\n');

				User = new customer(3, temp_username, temp_password, cn);
				User->update_info();
				User->Registration("customer.dat");
				//		first_menu = true;
				break;
			}
			case 0:
			{
				reg_menu = false;
				main_menu = true;
				break;
			}
			default:
			{
				cout << setw(80) << "*\t\t\tPlease Enter a valid Number from 0-2:-\t\t\t*\n";
				break;
			}
			}
		}

		while (admin_menu)		//Admin Menu
		{
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(65) << "*\t\t\t\t-: Admin Menu :-\t\t\t\t*";
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(85) << "*\t\t\t1)- Register a new Manager.\t\t*\n";
			cout << setw(85) << "*\t\t\t2)- Manage Product Catalog.\t\t*\n";
			cout << setw(85) << "*\t\t\t3)- Manage Stores.\t\t*\n";
			cout << setw(71) << "*\t\t\t0)- Logout.\t\t\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cin >> choice;

			switch (choice)
			{
			case 1:
			{
				string temp_username;
				string temp_password;
				string cit;
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(80) << "*\t\t\tRegistering a new Manager: \t\t\t*\n\n";
				cout << setw(83) << "*\t\t\tPlease Enter your Username: \t\t\t*\n";
				cin.clear();
				cin.ignore();
				getline(cin, temp_username, '\n');

				cout << setw(80) << "*\t\t\tPlease Enter your Current City: \t\t\t*\n";
				cin.clear();
				getline(cin, cit, '\n');

				cout << setw(80) << "*\t\t\tPlease Enter your Password: \t\t\t*\n";
				cin.clear();
				getline(cin, temp_password, '\n');

				User = new manager(2, temp_username, temp_password, cit);
				User->Registration("manager.dat");
				break;
			}
			case 2:
			{
				admin_menu = false;
				managing_catalog = true;
				break;
			}
			case 3:
			{
				int n = -12;
				cout << "\n\nManaging Feedbacks: " << endl;
				feedback obj;

				obj.display_all_items();
				cout << "\nIf you want to remove a Feedback then Enter its number otherwise Enter a Negative Number: " << endl;
				cin >> n;

				if (n < 0)
				{
					obj.remove_feedback(n);
					cout << "\nFeedback Removed Succesfully:" << endl;
				}

				break;
			}
			case 0:
			{
				cout << "\nLogged out Successfully:-" << endl;
				login_menu = true;
				admin_menu = false;
				break;
			}
			default:
			{
				cout << setw(80) << "*\t\t\tPlease Enter a valid Number from 0-3:-\t\t\t*\n";
			}
			}
		}

		while (manager_menu)		//Manager Menu
		{
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(68) << "*\t\t\tManager Menu:\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cout << setw(83) << "*\t\t\t1)- Manage Inventory of your store.\t\t\t*\n";
			cout << setw(71) << "*\t\t\t0)- Back.\t\t\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cin >> choice;

			switch (choice)
			{
			case 0:
			{
				login_menu = true;
				manager_menu = false;
				break;
			}
			case 1:
			{
				managing_inventory = true;
				manager_menu = false;
				break;
			}
			default:
			{
				cout << setw(80) << "*\t\t\tPlease Enter a valid Number from 0-2:-\t\t\t*\n";
				break;
			}
			}
		}

		while (managing_inventory)		//Manaing inventory
		{
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(80) << "*\t\t\tManaging Inventory:\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cout << setw(83) << "*\t\t1)- Add a new Item.\t\t\t*\n";
			cout << setw(82) << "*\t\t2)- Update an Item\t\t\t*\n";
			cout << setw(82) << "*\t\t3)- Delete an Item\t\t\t*\n";
			cout << setw(79) << "*\t\t\t4)- Display all Items.\t\t\t*\n";
			cout << setw(71) << "*\t\t\t0)- Back.\t\t\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cin >> choice;

			switch (choice)
			{
			case 0:
			{
				manager_menu = true;
				managing_inventory = false;
				break;
			}
			case 1:
			{
				manager temp;
				manager* temp1 = new manager;
				*temp1 = temp.return_manager("manager.dat", unm, pssd);
				temp.getStore().getInv().add_item(temp1->get_city());
				break;
			}
			case 2:
			{
				int id;
				string name;
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(85) << "*\t\tUpdating an Item.\t\t\t*\n";
				cout << "Please Enter the Item ID of the Item you want to update: " << endl;
				cin >> id;
				cin.clear();
				cin.ignore();

				cout << "\nPlease Enter Item name you want to update: " << endl;
				getline(cin, name, '\n');

				manager temp;
				manager* upd = new manager;
				*upd = temp.return_manager("manager.dat", unm, pssd);
				upd->getStore().getInv().update_items(id, name, upd->get_city());
				break;
			}
			case 3:
			{
				int id;
				string name;
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(85) << "*\t\tRemoving a Item.\t\t\t*\n";
				cout << "Please Enter the Item ID of the Item you want to from Inventory: " << endl;
				cin >> id;

				cin.clear();
				cin.ignore();
				cout << "\nPlease Enter Item Name you want to remove: " << endl;
				getline(cin, name, '\n');

				manager temp;
				manager* rem = new manager;
				*rem = temp.return_manager("manager.dat", unm, pssd);
				rem->getStore().getInv().remove_item(id, name, rem->get_city());
				break;
			}
			case 4:
			{
				manager temp;
				manager* dis = new manager;
				*dis = temp.return_manager("manager.dat", unm, pssd);
				dis->getStore().getInv().display_all_items(dis->get_city());
				break;
			}
			default:
			{
				cout << setw(80) << "*\t\t\tPlease Enter a valid Number from 0-4:-\t\t\t*\n";
				break;
			}
			}
		}

		while (managing_catalog)	//Managing catalog
		{
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(85) << "*\t\t\tManaging Product Catalog:\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cout << setw(83) << "*\t\t\t1)- Add a new Product.\t\t\t*\n";
			cout << setw(82) << "*\t\t\t2)- Update a Product.\t\t\t*\n";
			cout << setw(82) << "*\t\t\t3)- Delete a Product.\t\t\t*\n";
			cout << setw(79) << "*\t\t\t4)- Display Items.\t\t\t*\n";
			cout << setw(71) << "*\t\t\t0)- Back.\t\t\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cin >> choice;

			switch (choice)
			{
			case 0:
			{
				admin_menu = true;
				managing_catalog = false;
				break;
			}
			case 1:
			{
				int id = 0;
				char i_type = '\0';
				string cat = "1234";
				string subcat = "1234";
				string name = "";
				int price = 0;
				char unit = '\0';
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(85) << "*\t\tAdding a new Product.\t\t\t*\n";

				cout << "\nPlease Enter Product Id: " << endl;
				cin >> id;

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

				product_catalog P(id, i_type, cat, subcat, name, price, unit);
				P.add_product(P.getProd());
				break;
			}
			case 2:
			{
				int id;
				string name;
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(85) << "*\t\tUpdating a Product.\t\t\t*\n";
				cout << "Please Enter the Product ID of the product you want to update: " << endl;
				cin >> id;

				cin.clear();
				cin.ignore();
				cout << "\nPlease Enter Product Name you want to update: " << endl;
				getline(cin, name, '\n');
				product_catalog P;
				P.update_product(id, name);
				break;
			}
			case 3:
			{
				int id;
				string name;
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(85) << "*\t\tRemoving a Product.\t\t\t*\n";
				cout << "Please Enter the Product ID of the product you want to remove: " << endl;
				cin >> id;

				cin.clear();
				cin.ignore();
				cout << "\nPlease Enter Product Name you want to remove: " << endl;
				getline(cin, name, '\n');
				product_catalog P;
				P.remove_product(id, name);
				break;
			}
			case 4:
			{
				product_catalog A;
				A.Display_items();
				break;
			}
			default:
			{
				cout << setw(80) << "*\t\t\tPlease Enter a valid Number from 0-4:-\t\t\t*\n";
				break;
			}
			}
		}

		while (customer_menu)		//Customer Menu
		{
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(65) << "*\t\t\t\t-: Customer Menu :-\t\t\t\t*";
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(84) << "*\t\t\t1)- Shop Now.\t\t\t*\n";
			cout << setw(76) << "*\t\t\t2)- Proceed to Payment.\t\t\t*\n";
			cout << setw(76) << "*\t\t\t3)- Give Feedback.\t\t\t*\n";
			cout << setw(71) << "*\t\t\t0)- Back.\t\t\t\t*\n";
			cout << setw(122) << "**********************************************************************************\n";
			cin >> choice;


			switch (choice)
			{
			case 1:
			{
				customer m(2, unm);
				string City;
				m = m.getCustomer();
				City = m.get_city();
				City = City + ".dat";
				cout << "\n" << setw(122) << "**********************************************************************************\n";
				cout << setw(65) << "*\t\t\t\t-: Shop :-\t\t\t\t*";
				cout << "\n" << setw(122) << "**********************************************************************************\n";

				int i=0;
				online_shopping ons;

				do
				{
					item itm;
					cout << "\n" << setw(122) << "**********************************************************************************\n";
					cout << setw(65) << "*\t\t\t\t-: Add to Cart :-\t\t\t\t*";
					cout << "\n" << setw(122) << "**********************************************************************************\n";
					cout << setw(83) << "*\t\t\tDisplaying all Items in Inventory.\t\t\t*\n";
					cout << setw(122) << "**********************************************************************************\n";
					ifstream myFile(City, ios::binary);
					while (myFile.read((char*)&itm, sizeof(itm)))
					{
						itm.Display(itm);
					}
					myFile.close();
					ons.add_to_cart(m);
					cout << "Please Enter 1 to check out: " << endl;
					cin >> i;
				} while (i == 1);
				total = ons.calculate_total_bill();
			}
			case 2:
			{
				payment_menu = true;
				customer_menu = false;
				break;
			}
			case 3:
			{
				i++;
				feedback obj;
				obj.give_feedback(i);
				obj.add_feedback();
				customer_menu = false;
				login_menu = true;
				break;
			}
			case 0:
			{
				customer_menu = false;
				login_menu = true;
				break;
			}
			default:
			{
				cout << setw(80) << "*\t\t\tPlease Enter a valid Number from 0-3:-\t\t\t*\n";
				break;
			}
			}
		}

		while (payment_menu)		//Payment Options
		{
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(65) << "*\t\t\t\t-: Payment :-\t\t\t\t*";
			cout << "\n" << setw(122) << "**********************************************************************************\n";
			cout << setw(84) << "*\t\t\t1)- Pay through Cash on COD.\t\t\t*\n";
			cout << setw(76) << "*\t\t\t2)- Pay through Credit Card.\t\t\t*\n";
			cout << setw(76) << "*\t\t\t3)- Pay through Online Wallets (Easypaisa or Jazzcash).\t\t\t*\n";
			cout << setw(71) << "*\t\t\t0)- Back.\t\t\t\t*\n";
			cin >> choice;
			Payment* obj = new Payment;
			switch (choice)
			{
			case 1:
			{
				obj->transcation();			//Applied Polymorphism
				break;
			}
			case 2:
			{
				obj = new debit;
				obj->transcation();			//Applied Polymorphism
				break;
			}
			case 3:
			{
				obj = new wallets;			//Applied Polymorphism
				obj->transcation();
				break;
			}
			case 0:
			{
				customer_menu = true;
				payment_menu = false;
			}
			default:
			{
				cout << setw(80) << "*\t\t\tPlease Enter a valid Number from 0-3:-\t\t\t*\n";
				break;
			}
			}
		}

	}
	return 0;
}