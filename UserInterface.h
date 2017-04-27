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
	cout << "You Have Logged In As An Administrator" << endl;
	
	while(choice != 0){
		cout << "Here Are Your Options: " << endl;
		cout << "(1) Track Order" << endl;
		cin >> choice;
		cin.ignore();
	
		switch(choice){
			case 1:
				ClearScreen();
				cout << "Order Tracking:" << endl;
				cout << "Please input an order number for tracking: ";
				getline(cin,orderNum);
				ad.trackOrder(orderNum);
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
		cout << "(1) Track Order" << endl;
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
				
			default:
				break;
		}
	}
}
 
	
#endif