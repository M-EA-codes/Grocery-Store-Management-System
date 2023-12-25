#pragma once

class feedback
{
protected:
	int n;
	char feed[100];
public:

	void give_feedback(int num)		//to give feedback
	{
		string fe;
		cin.clear();
		cout << "\nPlease Enter your Feedback: " << endl;
		cin >> fe;
		n = num;
		strcpy_s(feed, fe.c_str());
	}

	void add_feedback()		//to store feedback
	{
		feedback temp = *this;
		ofstream myFile("Feedbacks.dat", ios::binary | ios::app);
		myFile.write((char*)&temp, sizeof(temp));
		myFile.close();
		cout << setw(80) << "\nYour Feedback is Submitted: Thank you for Shopping" << endl;
	}

	void remove_feedback(int num)	//to remove a feedback
	{
		feedback temp;
		fstream myFile("Feedbacks.dat", ios::in | ios::out | ios::binary);
		ofstream myFile_temp("temp.dat", ios::app | ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			if (temp.n != num)
			{
				myFile_temp.write((char*)&temp, sizeof(temp));
				cout << "Feedback Removed Successfully" << endl;
			}
		}
		myFile.close();
		myFile_temp.close();
		remove("Feedbacks.dat");
		rename("temp.dat", "Feedbacks.dat");
	}

	void display_all_items()	//displays all feedbacks
	{
		cout << "\n" << setw(122) << "**********************************************************************************\n";
		cout << setw(83) << "*\t\t\tDisplaying all Feedbacks.\t\t\t*\n";
		cout << setw(122) << "**********************************************************************************\n";
		feedback temp;
		ifstream myFile("Feedbacks.dat", ios::binary);
		while (myFile.read((char*)&temp, sizeof(temp)))
		{
			cout << "Feedback no# " << temp.n << endl;
			cout << temp.feed << "\n\n" << endl;
		}
		myFile.close();
	}
};