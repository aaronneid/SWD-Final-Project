#include"Miscellaneous.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <limits>

#ifndef __Admin_h_INCLUDED__
#define __Admin_h_INCLUDED__

using namespace std;

class Admin{
	public:
		void addCustomer();
		void addOrder();
		void viewActiveCustomers();
		void packagesInTransit();
		void CouriersInTransit();
		
	public:
		string username;
		string password;
	
		Admin();
		~Admin();
		void trackOrder(string orderNum);
        void updateOrder(string orderNum);
};


Admin::Admin(){
	
}

void Admin::trackOrder(string orderNum){
	string word,temp;

	ifstream fileIn("Orders.txt");
	if(fileIn.fail()){
		cout << "No order tracking could be performed! File does not exist!" << endl;
		exit(0);
	} else
		
	//implicit call to good
	while(getline(fileIn, temp)){
		stringstream inputStream;
//string temp;
		vector<string> order;
		int y = 0;
		
		//gets a line from the file as a string
//getline(fileIn, temp);
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
			return;
		}
	}

	fileIn.close();
	return;
}

void Admin::updateOrder(string orderNum) {
	string line, new_location, sTemp, input;
	int action;
	vector<string> order;
	
        vector<string> new_order;
        
	ifstream fileIn("Orders.txt");
	ofstream fileOut("Backup.txt");
	
	if(fileIn.fail()){
		cout << "No order update could be performed! File does not exist!" << endl;
		exit(0);
	}
	
	//each order in entry in vector 'order'
	while(getline(fileIn, line)) {
            //cout << "test";
                stringstream inputStream;
		inputStream << line;
                vector<string> vTemp;
		while(getline(inputStream, sTemp, '|')) {
			vTemp.push_back(sTemp);
                        //cout << vTemp[0] << endl;
                }
		if((vTemp[0].compare(orderNum)) == 0) {
                    new_order = vTemp;
                } //found order, put in separate vector
                else order.push_back(line); //if order not found, put this order in order vector
	}
	if(new_order.size() == 0) {
		cout << "Order not found." << endl; 
		return;
	}
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
		for(int k = 0; k < order.size(); k++) {
                    fileOut << order[k];
                    if(k != order.size()-1)
                        fileOut << '\n';
		}
	}
	
	if(action == 1) {
            //if update, store new location
            cout << "Enter the current location: " << endl;
            getline(cin, new_location);
		new_order[2] = new_location;
		if(new_order[2].compare(new_order[3]) == 0) new_order[5] = "Delivered";
		
		for(int k = 0; k < order.size(); k++) {
                    fileOut << order[k];
                    if(k != order.size()) fileOut << '\n';
		}
		//Write modified order back to output file
		for(auto &k : new_order) {
			fileOut << k;
			fileOut << '|';
		}
	}
	
	fileIn.close();
        fileOut.close();
}

Admin::~Admin(){
	
}

#endif