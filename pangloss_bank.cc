//------------------------------------------------------------------------------------------------------------------------------------
//Pangloss_bank
//This program will create and keep track of bank accounts
//Bonus Bonus programmer defined feature, regular accounts info can be outputed to a webpage file (located on line 324)
//written by James Gouveia 4/29/16 Version 1.0
//------------------------------------------------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream> 
#include <fstream>
using namespace std;

//Template prototype
template <typename Anytype>
float convert(Anytype &a);

//Struct Declaration
struct regular_account
{
	string name;
	int account_number;
	float balance;
};

struct plus_account
{
	string name;
	float account_number;
	float balance;
	float overdraft_limit;
	float interest_rate;
};

//function prototype
void show_intro();
bool menu();
regular_account * data_input_regular();
plus_account * data_input_plus();


//global variables, used to keep track of the number of accounts
int number_regular_accounts;
int number_plus_accounts;

//global pointers to structures
regular_account * dynamic_regular_account;
plus_account * dynamic_plus_account;

int main()
{
	//a short intro to the program
	show_intro();

	//infinite loop used to detect if the user wishes to continue the program
	while (1)
		{
			if (menu() == false)
				break;
		}

	
}

//short intro to the program
void show_intro()
{
	cout << "Pangloss_bank, this program will keep track of the account balances of both Regular and Plus Checking accounts.\n";
}

//menu function used to direct the program to the appropriate function
bool menu()
{
	string menu_choice;
	float regular_deposit;
	float plus_deposit;
	int account_number_converted;
	int menu_choice_converted;

	cout << "Please choose from the following options:\n"
	     << "1. Create a regular account.\n"
	     << "2. Create a plus account.\n"
	     << "3. Deposit money into an account.\n"
	     << "4. Withdraw money from an account.\n"
	     << "5. Display account info.\n"
	     << "99. Exit" << endl;

	cin >> menu_choice;
	menu_choice_converted = convert(menu_choice);
	cout << menu_choice_converted << endl;


	if (menu_choice_converted == 1)
		{
			dynamic_regular_account = data_input_regular();	
		}

	else if (menu_choice_converted == 2)
		{
			dynamic_plus_account = data_input_plus();	
			
		}

	else if (menu_choice_converted == 3)
		{
			string account_number_str;
			string account_type_str;
			int account_type;

			cout << "Please choose from the following options:\n"
			     << "1. Deposit to a regular account.\n"
			     << "2. Deposit to a plus account.\n";

			cin >> account_type_str;
			account_type = convert(account_type_str);

			if (account_type == 1)
				
				{
					cout << "Please enter the account number for the account you would like to deposit into.\n";
					
					cin >> account_number_str;
					account_number_converted = convert(account_number_str);

					int n = 0;
					
					for (n = 0; n != number_regular_accounts; n++)
					{
						
						cout << dynamic_regular_account[0].account_number << endl;

						if (dynamic_regular_account[n].account_number == account_number_converted)
							
							{
							cout << "Your account has been found, please enter the amount you would like to deposit.\n";
							cin >> regular_deposit;
							dynamic_regular_account[n].balance = dynamic_regular_account[n].balance + regular_deposit;
							cout << "The new balance is: " << dynamic_regular_account[n].balance << endl;
							return true;
							}
						
					}
					if (n == number_regular_accounts)
					{
							cout << "That account was not found, please try agian.\n\n";
							
					}

				}
			else if (account_type == 2)
				{
					cout << "Please enter the account number for the account you would like to deposit into.\n";
					
					cin >> account_number_str;
					account_number_converted = convert(account_number_str);

					int n = 0;
					for (n = 0; n != number_plus_accounts; n++)
					{
						cout << dynamic_plus_account[n].account_number << endl;

						if (dynamic_plus_account[n].account_number == account_number_converted)
							
							{
							cout << "Your account has been found, please enter the amount you would like to deposit.\n";
							cin >> plus_deposit;
							dynamic_plus_account[n].balance = dynamic_plus_account[n].balance + plus_deposit;
							cout << "The new balance is: " << dynamic_plus_account[n].balance << endl;
							return true;
							}
					}
					if (n == number_plus_accounts)
						{
							cout << "That account was not found, please try agian.\n\n";
						}	//menu();
				}
					
		}

	else if (menu_choice_converted == 4)
		{
			string account_number_str;
			string account_type_str;
			int account_type;

			cout << "Please choose from the following options:\n"
			     << "1. Withdraw from a regular account.\n"
			     << "2. Withdraw from a plus account.\n";

			cin >> account_type_str;
			account_type = convert(account_type_str);

			if (account_type == 1)
				
				{
					cout << "Please enter the account number for the account you would like to withdraw from.\n";
					
					cin >> account_number_str;
					account_number_converted = convert(account_number_str);

					int n = 0;
					
					for (n = 0; n != number_regular_accounts; n++)
					{
						
						cout << dynamic_regular_account[0].account_number << endl;

						if (dynamic_regular_account[n].account_number == account_number_converted)
							
							{
							cout << "Your account has been found, please enter the amount you would like to withdraw.\n";
							cin >> regular_deposit;
							dynamic_regular_account[n].balance = dynamic_regular_account[n].balance - regular_deposit;
								// Bonus Bonus!! Programmer defined feature, a warning when a regular account is overdrawn
								if (dynamic_regular_account[n].balance < 0)
									{
										cout << "This account is overdrawn, advise the client they may want to a plus account.\n\n\n";
										dynamic_regular_account[n].balance = 0;
									}
							cout << "The new balance is: " << dynamic_regular_account[n].balance << endl << endl;
							return true;
							}
						
					}
					if (n == number_regular_accounts)
					{
							cout << "That account was not found, please try agian.\n\n";
							
					}

				}
			if (account_type == 2)
				
				{
					cout << "Please enter the account number for the account you would like to withdraw from.\n";
					
					cin >> account_number_str;
					account_number_converted = convert(account_number_str);

					int n = 0;
					
					for (n = 0; n != number_plus_accounts; n++)
					{

						if (dynamic_plus_account[n].account_number == account_number_converted)
							
							{
							cout << "Your account has been found, please enter the amount you would like to withdraw.\n";
							
							string regular_deposit_str;

							cin >> regular_deposit_str;
							regular_deposit = convert(regular_deposit_str);


							dynamic_plus_account[n].balance = dynamic_plus_account[n].balance - regular_deposit;
								
								if (dynamic_plus_account[n].balance < 0)
									{

										float overdrawn_amount = dynamic_plus_account[n].overdraft_limit - dynamic_plus_account[n].balance;
										cout << "This account is overdrawn, and you are using your overdraft protection.\n"
											 << "You have " << dynamic_plus_account[n].overdraft_limit + dynamic_plus_account[n].balance
											 << " left to spend from your overdraft amount.\n\n\n";
										dynamic_plus_account[n].overdraft_limit = dynamic_plus_account[n].overdraft_limit - overdrawn_amount;	
									}
							cout << "The new balance is: " << dynamic_plus_account[n].overdraft_limit << endl << endl;
							return true;
							}
						
					}
					if (n == number_regular_accounts)
					{
							cout << "That account was not found, please try agian.\n\n";
							return true;
							
					}

				}

		}

	else if (menu_choice_converted == 5)
		{
			string account_number_str;
			string account_type_str;
			int account_type;
			string save;

			cout << "Please choose from the following options:\n"
			     << "1. Display account info from a regular account.\n"
			     << "2. Display account info from a plus account.\n";

			cin >> account_type_str;
			account_type = convert(account_type_str);

			if (account_type == 1)
				{
					cout << "Please enter the account number for the account you would like display info for.\n";
					
					cin >> account_number_str;
					account_number_converted = convert(account_number_str);

					int n = 0;

					for (n = 0; n != number_regular_accounts; n++)
					{
						
						

						if (dynamic_regular_account[n].account_number == account_number_converted)
							
							{
							cout << "Your account has been found, Here is the account information.\n";
							
							cout << " account holder name: " << dynamic_regular_account[n].name << endl;
							cout << " Account number: " << dynamic_regular_account[n].account_number << endl;
							cout << " Account balance " << dynamic_regular_account[n].balance << endl << endl;
							
							//Bonus Bonus outputs the account info to a webpage file
							cout << "Would you like to save the account info into a file you can print out? Y for yes, any other key for no.\n";
							
							cin >> save;

							if (save == "y" or save == "Y")
								{
									//Bonus Bonus outputs the account info to a webpage file
									ofstream myfile;
									myfile.open("account.htm", ios:: out);

									//format the html doc and output the account info
									myfile << "<DOCTYPE html>\n" 
										   << "<html>\n"
										   << "<title>Account info!</title>\n"
										   << "<style>\n body{background-color:green;}\n p {color:red;}\n</style>"
										   << "<body>\n"
										   << "<h1> Account info:\n<br>  "
										   << " account holder name: " << dynamic_regular_account[n].name << "<br>" << endl;
									myfile << " \nAccount number: " << dynamic_regular_account[n].account_number << "<br>" << endl;
							        myfile << " \nAccount balance " << dynamic_regular_account[n].balance << endl << endl;
									
	                                myfile << "\n</h1><br>";
	                                        
	                                myfile << "</body>\n"
		                                   << "</html>";

		                            myfile.close();
								}

							return true;
							}
						
					}
					if (n == number_regular_accounts)
					{
							cout << "That account was not found, please try agian.\n\n";
							return true;
							
					}
				}

			if (account_type == 2)
				{
					
					cout << "Please enter the account number for the account you would like display info for.\n";
					
					cin >> account_number_str;
					account_number_converted = convert(account_number_str);

					int n = 0;

					for (n = 0; n != number_plus_accounts; n++)
					{
						

						if (dynamic_plus_account[n].account_number == account_number_converted)
							
							{
							cout << "Your account has been found, Here is the account information.\n";
							
							cout << " account holder name: " << dynamic_plus_account[n].name << endl;
							cout << " Account number: " << dynamic_plus_account[n].account_number << endl;
							cout << " Account balance " << dynamic_plus_account[n].balance << endl;
							cout << " Overdraft protection balance: " << dynamic_plus_account[n].overdraft_limit << endl;
							cout << " Overdraft interest rate: " << dynamic_plus_account[n].interest_rate << endl << endl;

							return true;
							}
						
					}
					if (n == number_regular_accounts)
					{
							cout << "That account was not found, please try agian.\n\n";
							return true;
							
					}
				}

		}

	else if (menu_choice_converted == 99)
		{
			return false;
		}
	else
		{
			cout << "Invalid entry, please begin again from the beginning.\n"
				 << "================================================================================\n";
			return true;
		}


		
	
	return true;
}

//input data for regular accounts
regular_account * data_input_regular()
{
	string regular_entries;
	int regular;
	string dynamic_regular_account_name;
	string dynamic_regular_account_account_number;
	string dynamic_regular_account_balance;
	

	cout << "How many regular bank accounts would you like to enter data for?\n";

	cin >> regular_entries;

	regular = convert(regular_entries);

	number_regular_accounts = regular;

	regular_account * dynamic_regular_account = new regular_account[regular];

	for (int n = 0; n != regular; n++)
	{
		cout << "Enter the client's name: " << endl;
		cin.ignore();
		getline(cin, dynamic_regular_account[n].name);

		cout << "Enter the account number:" << endl;
		cin >> dynamic_regular_account_account_number;
		dynamic_regular_account[n].account_number = convert(dynamic_regular_account_account_number);
		
		cout << "Enter the amount in the account." << endl;
		cin >> dynamic_regular_account_balance;
		dynamic_regular_account[n].balance = convert(dynamic_regular_account_balance);

		cout << endl;
	};

	return dynamic_regular_account;

}


//input data for plus accounts
plus_account * data_input_plus()
{
	string plus_entries;
	int number;
	string dynamic_plus_account_account_number;
	string dynamic_plus_account_balance;
	string dynamic_plus_account_overdraft_limit;
	string dynamic_plus_account_interest_rate;

	cout << "How many plus bank accounts would you like to enter data for?\n";
	cin >> plus_entries;

	number = convert(plus_entries);

	number_plus_accounts = number;

	plus_account * dynamic_plus_account = new plus_account[number];

	for (int n = 0; n != number; n++)
	{
		cout << "Enter the client's name: " << endl;
		cin.ignore();
		getline(cin, dynamic_plus_account[n].name);

		cout << "Enter the account number:" << endl;
		cin >> dynamic_plus_account_account_number;
		dynamic_plus_account[n].account_number = convert(dynamic_plus_account_account_number);

		cout << "Enter the amount in the account." << endl;
		cin >> dynamic_plus_account_balance;
		dynamic_plus_account[n].balance = convert(dynamic_plus_account_balance);

		cout << "Enter the overdraft limit." << endl;
		cin >> dynamic_plus_account_overdraft_limit;
		dynamic_plus_account[n].overdraft_limit = convert(dynamic_plus_account_overdraft_limit);

		cout << "Enter the overdraft intrest rate." << endl;
		cin >> dynamic_plus_account_interest_rate;
		 dynamic_plus_account[n].interest_rate = convert(dynamic_plus_account_interest_rate);

		cout << endl;
	};

	return dynamic_plus_account;
}


//template to convert strings to floats
template <typename Anytype>
float convert(Anytype &a)
{
	float b;

	b = atof (a.c_str());

	return b;
}