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
	cout << "Welcome " << ad.username << "!" << endl;
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
		cout << "(6) Add A New User" << endl;
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
				//current issue - runs even if order doesnt exist
				cout <<"(1) Update this order" << endl << "(2) Continue" << endl;
				cout << endl << "> ";		
				cin >> choice;
				cin.ignore();
				if(choice == 1)
					ad.updateOrder(orderNum);
				else
					ClearScreen();
				break;
			case 2:
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
				ClearScreen();
				cout << "Customers with Active Orders: " << endl << endl;
				ad.viewActiveCustomers();
				cout <<"Press any key to continue";
				cin.get();
				ClearScreen();
				break;
			case 4:
				ClearScreen();
				cout << "Packages In Transit:" << endl << endl;
				ad.packagesInTransit();
				cout <<"Press any key to continue";
				cin.get();
				ClearScreen();
				break;
			case 5:
				ClearScreen();
				cout << "Couriers In Transit:" << endl;
				ad.couriersInTransit();
				cout <<"Press any key to continue";
				cin.get();
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
		cout << "Welcome " << cr.username << "!" << endl;
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
				cout <<"Press any key to continue";
				cin.ignore();
				if(choice == 1)
					cr.updateOrder(orderNum);
				else
					ClearScreen();
				break;
			case 2:
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
				ClearScreen();
				cout << "Order History:" << endl;
				cr.getHistory();
				cout <<"Press any key to continue";
				cin.ignore();
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
		cout << "Welcome " << cu.username << "!" << endl;
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
				cout <<"Press any key to continue";
				cin.ignore();
				ClearScreen();
				break;
			case 2:
				ClearScreen();
				cout << "Order History:" << endl;
				cu.getHistory();
				cout <<"Press any key to continue";
				cin.ignore();
				ClearScreen();
				break;
			default:
				break;
		}
	}
}
 
	
#endif