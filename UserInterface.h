#include"Miscellaneous.h"

#ifndef __UserInterface_h_INCLUDED__
#define __UserInterface_h_INCLUDED__

using namespace std;

class UI{
	public:
	UI();
		void display(Admin);
		void display(Courier);
		void display(Customer);
};

UI::UI(){
	
}

void UI::display(Admin ad){
	int choice = -1;
	string orderNum;
	ClearScreen();
	//greets admin
	cout << "Welcome " << ad.username << "!" << endl;
	cout << "You Have Logged In As An Administrator" << endl;
	
	//displays admin options
	while(choice != 0){
		cout << "Here Are Your Options: " << endl;
		cout << "(0) Logout Of System" << endl;
		cout << "(1) Track Order" << endl;
		cout << "(2) Update Order" << endl;
		cout << "(3) View Active Customers" << endl;
		cout << "(4) View Packages In Transit" << endl;
		cout << "(5) View Couriers In Transit" << endl;
		cout << endl << "<------ Admin Functions ------>"<< endl;
		cout << "(6) Add A New User" << endl;
		cout << "(7) Add A New Order" << endl;
		
		//gets admin input
		cout << endl << "> ";		
		cin >> choice;
		cin.ignore();
		//checks if input is something that causes cin to fail
		while(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << endl << "That was not a valid input, please only input valid menu numbers." << endl;;
			cout << endl << "> ";	
			cin >> choice;
			cin.ignore();
		}

	
		//switch case for options
		switch(choice){
			case 0:
				//logout case
				ClearScreen();
				exit(0);
			case 1:
				//track an order
				ClearScreen();
				cout << "Order Tracking:" << endl;
				cout << "Please input an order number for tracking: ";
				getline(cin,orderNum);
				//checks if the order number exists 
				try{
					ad.trackOrder(orderNum);
				}catch(const char * error){
					cout << error;
					break;
				}
				//allows admin to directly update an order
				cout <<"(1) Update this order" << endl << "(2) Continue" << endl;
				cout << endl << "> ";		
				cin >> choice;
				cin.ignore();
				while(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout << endl << "That was not a valid input, please only input valid menu numbers." << endl;;
					cout << endl << "> ";	
					cin >> choice;
					cin.ignore();
				}
				if(choice == 1)
					ad.updateOrder(orderNum);
				else
					ClearScreen();
				break;
			case 2:
				//update an order
				ClearScreen();
				cout << "Update Order:" << endl;
				cout << "Please input an order number for updating: ";
				getline(cin,orderNum);
				ad.updateOrder(orderNum);
				cout <<"Press any key to continue";
				cin.ignore();
				ClearScreen();
				break;
			case 3:
				//view all customers that have an order currently in transit
				ClearScreen();
				cout << "Customers with Active Orders: " << endl << endl;
				ad.viewActiveCustomers();
				cout <<"Press any key to continue";
				cin.get();
				ClearScreen();
				break;
			case 4:
				//view all packages in transit
				ClearScreen();
				cout << "Packages In Transit:" << endl << endl;
				ad.packagesInTransit();
				cout <<"Press any key to continue";
				cin.get();
				ClearScreen();
				break;
			case 5:
				//view all couriers assigned to a package that is in transit
				ClearScreen();
				cout << "Couriers In Transit:" << endl;
				ad.couriersInTransit();
				cout <<"Press any key to continue";
				cin.get();
				ClearScreen();
				break;
			case 6:
				//allows the admin to add a new user
				ClearScreen();
				cout << "Add a New User:" << endl;
				ad.addUser();
				cout <<"Press any key to continue";
				cin.get();
				ClearScreen();
				break;
			case 7:
				//allows an admin to add a new order
				ClearScreen();
				cout << "Add a New Order:" << endl;
				ad.addOrder();
				cout <<"Press any key to continue";
				cin.get();
				ClearScreen();
				break;
			default:
				//default case if input was not recognized
				ClearScreen();
				cout << "That was not a valid input, please only input valid menu numbers." << endl;
				break;
		}
	}
}

void UI::display(Courier cr){
	int choice = -1;
	string orderNum;
	ClearScreen();
	//greets courier
	cout << "Welcome " << cr.username << "!" << endl;
	cout << "You Have Logged In As An Courier" << endl;
		
	//displays couriers options
	while(choice != 0){
		cout << "Here Are Your Options: " << endl;
		cout << "(0) Logout Of System" << endl;
		cout << "(1) Track Order" << endl;
		cout << "(2) Update Order" << endl;
		cout << "(3) View Delivery History" << endl;
		
		//gets courier input
		cout << endl << "> ";		
		cin >> choice;
		cin.ignore();
		//checks if input is something that causes cin to fail
		while(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << endl << "That was not a valid input, please only input valid menu numbers." << endl;;
			cout << endl << "> ";	
			cin >> choice;
			cin.ignore();
		}
	
		//switch case for options
		switch(choice){
			case 0:
			//logout case
				ClearScreen();
				exit(0);
			case 1:
			//track an order
				ClearScreen();
				cout << "Order Tracking:" << endl;
				cout << "Please input an order number for tracking: ";
				getline(cin,orderNum);
				//handling for case that order number doesnt exist
				try{
					cr.trackOrder(orderNum);
				}catch(const char * error){
					cout << error;
					break;
				}
				//allows courier to automatically update an order
				cout <<"(1) Update this order" << endl << "(2) Continue" << endl;
				cout << endl << "> ";	
				cin >> choice;
				cin.ignore();
				while(cin.fail()){
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(),'\n');
					cout << endl << "That was not a valid input, please only input valid menu numbers." << endl;;
					cout << endl << "> ";	
					cin >> choice;
					cin.ignore();
				}
				if(choice == 1)
					cr.updateOrder(orderNum);
				else
					ClearScreen();
				break;
			case 2:
			//update an order
				ClearScreen();
				cout << "Update Order:" << endl;
				cout << "Please input an order number for updating: ";
				getline(cin,orderNum);
				cr.updateOrder(orderNum);
				cout <<"Press any key to continue";
				cin.ignore();
				ClearScreen();
				break;
			case 3:
			//view all orders that the courier has handled
				ClearScreen();
				cout << "Order History:" << endl;
				cr.getHistory();
				cout <<"Press any key to continue";
				cin.ignore();
				ClearScreen();
				break;
			default:
			//default case if input was not recognized
				ClearScreen();
				cout << "That was not a valid input, please only input valid menu numbers." << endl;
				break;
		}
	}
}

void UI::display(Customer cu){
	int choice = -1;
	string orderNum;
	ClearScreen();
	//greets user
	cout << "Welcome " << cu.username << "!" << endl;
	cout << "Thank You For Logging Into The Mojave Express Courier System." << endl;
		
	//displays customers options
	while(choice != 0){
		cout << "What would you like to do?" << endl;
		cout << "(1) Track Order" << endl;
		cout << "(2) View Order History" << endl;
		cout << "(3) Logout Of System" << endl;
		
		//gets user input
		cout << endl << "> ";		
		cin >> choice;
		cin.ignore();
		//checks if input will cause cin to fail
		while(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << endl << "That was not a valid input, please only input valid menu numbers." << endl;;
			cout << endl << "> ";	
			cin >> choice;
			cin.ignore();
		}

		//switch case for options
		switch(choice){
			case 1:		
			//allows user to track order
				ClearScreen();
				cout << "Order Tracking:" << endl;
				cout << "Please input an order number for tracking: ";
				getline(cin,orderNum);
				try{
					cu.trackOrder(orderNum);
				}catch(const char * error){
					cout << error;
					cout <<"Press any key to continue";
					cin.ignore();
					break;
				}
				cout <<"Press any key to continue";
				cin.ignore();
				ClearScreen();
				break;
			case 2:
				//view all orders that are in the customers name
				ClearScreen();
				cout << "Order History:" << endl;
				cu.getHistory();
				cout <<"Press any key to continue";
				cin.ignore();
				ClearScreen();
				break;
			case 3:
				//logout case
				ClearScreen();
				exit(0);
			default:
			//default case for handling unrecognized input
				ClearScreen();
				cout << "That was not a valid input, please only input valid menu numbers." << endl;
				break;
		}
	}
}
 
	
#endif