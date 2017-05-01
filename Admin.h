#include"Miscellaneous.h"
#include <string>
#include <algorithm>
#include <vector>

#ifndef __Admin_h_INCLUDED__
#define __Admin_h_INCLUDED__

using namespace std;

class Admin{
	private:
		void addCustomer();
		void addOrder();
		void viewActiveCustomers();
		void packagesInTransit();
		void CouriersInTransit();
		
	public: 
		Admin();
		~Admin();
		void trackOrder(string orderNum);
        void updateOrder(string orderNum);
};


Admin::Admin(){
	
}

void Admin::trackOrder(string orderNum){
	string word;

	ifstream fileIn("Orders.txt");
	if(fileIn.fail()){
		cout << "No order tracking could be performed! File does not exist!" << endl;
		exit(0);
	} else
		
	//implicit call to good
	while(fileIn){
		stringstream inputStream;
		string temp;
		vector<string> order;
		int y = 0;
		
		//gets a line from the file as a string
		getline(fileIn, temp);
		//converts the string into a string stream
		inputStream << temp;
		//uses string stream to break the string up into strings seperated by the | delimiter
		while(getline(inputStream,word,'|')){
			//adds each entry to a vector
			order.push_back(word);
		}
		//checks if the order numbers match
		if(orderNum.compare(order[0]) == 0){
			ClearScreen();	//clears the screen and displays order info
			cout << "Order Number: " << order[0] << endl;
			cout << "Package Location: " << order[2] << endl;
			cout << "Order Status: " << order[5] << endl;
			cout <<"Press any key to continue";
			cin.ignore();
			return;
		}
	}

	fileIn.close();
	return;
}

void Admin::updateOrder(string orderNum) {
	string word, new_location;
        int action;
        vector<string> order;
	ifstream fileIn("Orders.txt");
	ofstream fileOut("Backup.txt");
	
	if(fileIn.fail()){
		cout << "No order update could be performed! File does not exist!" << endl;
		exit(0);
	} else
		
		//implicit call to good
	while(fileIn){
		stringstream inputStream;
		string temp;
		int y = 0;
		
		//gets a line from the file as a string
		getline(fileIn, temp);
		//converts the string into a string stream
		inputStream << temp;
		//uses string stream to break the string up into strings seperated by the | delimiter
		while(getline(inputStream,word,'|')){
			//adds each entry to a vector
			order.push_back(word);
		}
		
	}
	
	string input;
	//select remove or update order location
	while(1) {
		cout << "What action would you like to perform?" <<
			"\n[0] Remove Order" << "\n[1] Update Order Location" << endl;
		cin >> action;
		cin.ignore();
		if((action != 1 && action != 0)) {
			cout << "Invalid selection, try again." << endl << endl;
		}
		else break;
	}
	
	if(action == 0) {
		for(int i = 0; i < order.size(); i++) {
			if(order[i] == orderNum) {
				order.erase (order.begin()+i);
				order.erase (order.begin()+i+1);
				order.erase (order.begin()+i+2);
				order.erase (order.begin()+i+3);
				order.erase (order.begin()+i+4);
				order.erase (order.begin()+i+5);
			}
			else if(i == order.size()-1) {
				cout << "Error, order not found." << endl;
			}
		}
	}
	if(action == 1) { //if update, store new location
		cout << "Enter the current location: " << endl;
		getline(cin, new_location);
		for(int j = 0; j < order.size(); j++) {
			if(order[j] == orderNum) { //replace current location
				//replace(order.begin()+j+2, order.begin()+j+2, order[j+2], new_location);
                            order[j+2] = new_location;
				if(order[j+3] == new_location) { //check for order complete
                                    order[j+5] = "Delivered";
				}
			}
			else if(j == order.size()-1) {
				cout << "Error, order not found." << endl;
			}
		}
	}
	//write data to new file
    for(int k = 0; k < order.size(); k++) {
        fileOut << order[k];
        fileOut << '|';
        if(k != order.size()-1 && (k-1)%6 == 0 && k != 0) {
            fileOut << '\n';
        }
    }
        fileIn.close();
        fileOut.close();
}

Admin::~Admin(){
	
}

#endif