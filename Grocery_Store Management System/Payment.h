#pragma once

class Payment
{
protected:
	int total;
public:
	virtual void transcation()
	{
		cout << "\nCash on Delivery:\n" << endl;
	}
};

class debit :public Payment
{
protected:
	char credit_card_no[30];
	char exp_date[15];
	int ccv;
public:
	void transaction()
	{
		cout << "\nPayment through Debit Cards: " << endl;
		cout << "Please Enter Credit Card Number: " << endl;
		cin >> credit_card_no;

		cout << "Please Enter Expiry Date of your Debit Card: " << endl;
		cin >> exp_date;


		cout << "Please Enter CCV of your Debit Card: " << endl;
		cin >> ccv;
	}
};

class wallets : public Payment
{
	char num[12];
	int mpin;
public:
	void transaction()
	{
		cout << "\nPayment through Wallet: " << endl;
		cout << "Please Enter your Acc Number: " << endl;
		cin >> num;

		cout << "Please Enter your MPIN to Pay: " << endl;
		cin >> mpin;

	}
};