#include"Miscellaneous.h"

#ifndef __Admin_h_INCLUDED__
#define __Admin_h_INCLUDED__

using namespace std;

class Admin{
	public:
		void addUser();
		void addOrder();
		void viewActiveCustomers();
		void packagesInTransit();
		void couriersInTransit();
		
	public:
		string username;
		string password;
		string rank;
	
		Admin();
		~Admin();
		void trackOrder(string orderNum);		
        void updateOrder(string orderNum);
};


Admin::Admin(){
	rank = "admin";
}

void Admin::addOrder() {
    string name, curLoc, destLoc, courName, status, line, temp;
    int orderNum,check1,check2 = 0;
    vector<string> customerList;
    vector<string> courierList;
    vector<string> name_match;
    ifstream fileIn("Authentication.txt");
    ofstream fileOut("Orders.txt", ios::app);
    srand(time(NULL));
    orderNum = rand() % 10000000 + 99999999;
    cout << "Enter current location of parcel: ";
    getline(cin, curLoc);
    cout << "Enter destination location: ";
    getline(cin, destLoc);

    //read in all names to compare
    while (getline(fileIn, line)) {
        stringstream inputStream;
        inputStream << line;
        vector<string> vTemp;
        while (getline(inputStream, temp, '|')) {
            vTemp.push_back(temp);
        }
        if ((vTemp[2].compare("courier")) == 0) { //used to check if courier
            courierList.push_back(vTemp[0]);
        }
        if((vTemp[2].compare("customer")) == 0) {	//used to check if customer
            customerList.push_back(vTemp[0]);
        }
    }
		//allows user to enter a customer name
        cout << "Enter customer name: ";
        while(getline(cin, name)) {
			//checks if customer exists
            if(find(customerList.begin(), customerList.end(), name) != customerList.end()) {
                break;
            }
            else {
				//error if customer doesnt exist
                cout << "Error, name not registered. Try again: ";
				check1++;
				//loop breaks if user repeatedly inputs a wrong name
				if(check1 > 3){
					cout << "Sorry, this doesn't seem to be working.  Please try again later." << endl;
				}
            }
        }
		//allows user to enter a courier name
        cout << "Enter courier name: ";
        while(getline(cin, courName)) {
			//checks for valid courier
            if(find(courierList.begin(), courierList.end(), courName) != courierList.end()) {
                break;
            }
            else {
				//error if courier doesnt exist
                cout << "Error, courier not registered. Try again: ";
				check2++;
				//loop breaks if user repeatedly inputs a wrong name
				if(check2 > 3){
					cout << "Sorry, this doesn't seem to be working.  Please try again later." << endl;
				}
            }
        }
             
    //adds order
        cout << "Order Successfully Added!\n" << endl;
    fileOut << '\n' << orderNum << '|' << name << '|' << curLoc << '|' << destLoc << '|' << courName << '|' << "In Transit" << '|';
}
void Admin::updateOrder(string orderNum) {
	string line, new_location, sTemp, input;
	int action;
	vector<string> order;
	
        vector<string> new_order;
        
	ifstream fileIn("Orders.txt");
	
	//error if file doesnt exist
	if(fileIn.fail()){
		cout << "No order update could be performed! File does not exist!" << endl;
		exit(0);
	}
	
	//each order in entry in vector 'order'
	while(getline(fileIn, line)) {
                stringstream inputStream;
		inputStream << line;
                vector<string> vTemp;
		while(getline(inputStream, sTemp, '|')) {
			vTemp.push_back(sTemp);
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
	ofstream fileOut("Orders.txt");
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

void Admin::addUser() {
    string name, pass, rank;
    int choice;
    ofstream fileOut("Authentication.txt", ios::app);
    fileOut << '\n';
    cout << "Adding: \n(0) Admin \n(1) Courier \n(2) Customer" << endl;
    cin >> choice;
    cin.ignore();
    cout << "Enter name of user: \n";
    getline(cin, name);
    cout << "\nEnter password of user: \n";
    getline(cin, pass);
    if(choice == 0) rank = "admin";
    if(choice == 1) rank = "courier";
    if(choice == 2) rank = "customer";
    fileOut << name << '|' << pass << '|' << rank << '|';
    fileOut.close();
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
		vector<string> order;
		int y = 0;
	
		//converts the string into a string stream
		inputStream << temp;
		//uses string stream to break the string up into strings seperated by the | delimiter
		while(getline(inputStream,word,'|')){
			//adds each entry to a vector
			order.push_back(word);
		}
		//checks if the order numbers match
		if(orderNum.compare(order[0]) == 0){	
			//additional check for customers to make usre they can not track an order that does not belong to them
			if(username.compare(order[1]) != 0 && rank.compare("customer") == 0){
				cout  << "No order number could be found that is owned by you." << endl;
				return;
			}	
			//ClearScreen();	//clears the screen and displays order info
			cout << "Order Number: " << order[0] << endl;
			cout << "Package Location: " << order[2] << endl;
			cout << "Order Status: " << order[5] << endl;
			fileIn.close();
			return;
		}
	}

	fileIn.close();
	//throws error if order didnt exist
	throw "That order number could not be found!\n";
	return;
}

void Admin::packagesInTransit(){
	string word,temp;
	vector< vector<string> > activeOrders;
	vector<string> setup;
	boolean copied = false;

	ifstream fileIn("Orders.txt");
	if(fileIn.fail()){
		//error if file doesnt exist
		cout << "No order tracking could be performed! File does not exist!" << endl;
		exit(0);
	} else
		
	//implicit call to good
	while(getline(fileIn, temp)){
		stringstream inputStream;
		vector<string> order;
		int y = 0;
		
		//converts the string into a string stream
		inputStream << temp;
		
		//uses string stream to break the string up into strings seperated by the | delimiter
		while(getline(inputStream,word,'|')){
			//adds each entry to a vector
			order.push_back(word);
		}
		//checks if the order is still in transit
		if(order[5].compare("In Transit") == 0){
			//adds the vector filed in last while loop to the 2 dimensional vector activeOrders
			activeOrders.push_back(order);
		}
		//creates a template for the output
		if(!copied)
			setup = order;
		copied = true;
	}
	
	//sometimes formatting messes up here if in full screen terminal - no idea why
	cout <<"    ";
	//dispalys column names
	for(int y = 0; y < setup.size(); y++){
			cout << left  << setw(20) << setup[y];
	}
	//displays all the info row by row
	for(int i = 0; i < activeOrders.size(); i++){
		cout << endl << "(" << i+1 << ") ";
		for(int y = 0; y < activeOrders[i].size(); y++){
			cout << left  << setw(20) << activeOrders[i][y];
		}
	}

	cout << endl;
	fileIn.close();
	return;	
}


void Admin::couriersInTransit(){
	string word,temp;
	vector<string> couriers;
	vector<string> setup;

	ifstream fileIn("Orders.txt");
	if(fileIn.fail()){
		//error if file doesnt exist
		cout << "No order tracking could be performed! File does not exist!" << endl;
		exit(0);
	} else
		
	//implicit call to good
	while(getline(fileIn, temp)){
		stringstream inputStream;
		vector<string> order;
		int y = 0;
		
		//converts the string into a string stream
		inputStream << temp;
		
		//uses string stream to break the string up into strings seperated by the | delimiter
		while(getline(inputStream,word,'|')){
			//adds each entry to a vector
			order.push_back(word);
		}
		//checks if the order is still in transit
		if(order[5].compare("In Transit") == 0){
			//checks if courier name has already been recorded - makes list unique
			if(find(couriers.begin(), couriers.end(), order[4]) == couriers.end())
				couriers.push_back(order[4]);
		}
		
	}
	
	//dispalys recorded info
	for(int i = 0; i < couriers.size(); i++){
		cout << "(" << i+1 << ") " << couriers[i] << endl;
	}

	cout << endl;
	fileIn.close();
	return;	
}

void Admin::viewActiveCustomers(){
	string word,temp;
	vector<string> customers;
	vector<string> setup;

	ifstream fileIn("Orders.txt");
	if(fileIn.fail()){
		//error if file doesnt exist
		cout << "No order tracking could be performed! File does not exist!" << endl;
		exit(0);
	} else
		
	//implicit call to good
	while(getline(fileIn, temp)){
		stringstream inputStream;
		vector<string> order;
		int y = 0;
		
		//converts the string into a string stream
		inputStream << temp;
		
		//uses string stream to break the string up into strings seperated by the | delimiter
		while(getline(inputStream,word,'|')){
			//adds each entry to a vector
			order.push_back(word);
		}
		//checks if the order is still in transit
		if(order[5].compare("In Transit") == 0){
			//checks if customers name has already been recorded - makes list unique
			if(find(customers.begin(), customers.end(), order[1]) == customers.end())
				customers.push_back(order[1]);
		}
		
	}
	
	//displays recorded info
	for(int i = 0; i < customers.size(); i++){
		cout << "(" << i+1 << ") " << customers[i] << endl;
	}

	cout << endl;
	fileIn.close();
	return;	
}


Admin::~Admin(){
	
}

#endif