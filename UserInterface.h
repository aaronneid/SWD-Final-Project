#include"Miscellaneous.h"
#include "Admin.h"

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
	cout << "You Have Logged In As An Administrator" << endl;
	
	while(choice != 0){
		cout << "Here Are Your Options: " << endl;
		cout << "(0) Logout Of System" << endl;
		cout << "(1) Track Order" << endl;
		cout << "(2) Update Order" << endl;
		cout << "(3) View Active Customers" << endl;
		cout << "(4) View Packages In Transit" << endl;
		cout << "(5) View Couriers In Transit" << endl;
		cout << endl << "<------ Admin Functions ------>"<< endl;
		cout << "(6) Add A New Customer" << endl;
		cout << "(7) Add A New Order" << endl;
		
		cout << endl << "> ";		
		cin >> choice;
		cin.ignore();
	
		switch(choice){
			case 1:
				ClearScreen();
				cout << "Order Tracking:" << endl;
				cout << "Please input an order number for tracking: ";
				getline(cin,orderNum);
				ad.trackOrder(orderNum);
				ClearScreen();
				break;
			case 2:
				ClearScreen();
				cout << "Order Updating:" << endl;
				cout << "Please input an order number for updating: ";
				getline(cin,orderNum);
                                ad.updateOrder(orderNum);
                                ClearScreen();
				break;
			case 3:
				ClearScreen();

				break;
			case 4:
				ClearScreen();

				break;
			case 5:
				ClearScreen();

				break;
			case 6:
				ClearScreen();

				break;
			case 7:
				ClearScreen();

				break;
			default:
				break;
		}
	}
}

void UI::display(Courier cr){
	int choice = -1;
	string orderNum;
	ClearScreen();
	cout << "You Have Logged In As An Courier" << endl;
		
	while(choice != 0){
		cout << "Here Are Your Options: " << endl;
		cout << "(0) Logout Of System" << endl;
		cout << "(1) Track Order" << endl;
		cout << "(2) Update Order" << endl;
		cout << "(3) View Delivery History" << endl;
		cin >> choice;
		cin.ignore();
	
		switch(choice){
			case 1:
				ClearScreen();
				cout << "Order Tracking:" << endl;
				cout << "Please input an order number for tracking: ";
				getline(cin,orderNum);
				cr.trackOrder(orderNum);
				break;
			case 2:
				ClearScreen();

				break;
			case 3:
				ClearScreen();

				break;	
			default:
				break;
		}
	}
}

void UI::display(Customer cu){
	int choice = -1;
	string orderNum;
	ClearScreen();
	cout << "Thank You For Logging Into The Mojave Express Courier System." << endl;
		
	while(choice != 0){
		cout << "What would you like to do?" << endl;
		cout << "(1) Track Order" << endl;
		cout << "(2) View Order History" << endl;
		cout << "(3) Logout Of System" << endl;
		cin >> choice;
		cin.ignore();
	
		switch(choice){
			case 1:
				ClearScreen();
				cout << "Order Tracking:" << endl;
				cout << "Please input an order number for tracking: ";
				getline(cin,orderNum);
				cu.trackOrder(orderNum);
				break;
			case 2:
				ClearScreen();
				break;	
			default:
				break;
		}
	}
}
 
	
#endif