//============================================================================
// Software Development Final Project First Iteration
// Description - Courier Tracking Program
//============================================================================

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int login(string name, string password);

class Admin{
	public: 
		Admin();
		~Admin();
		void trackOrder(string orderNum);
                void updateOrder(string orderNum);
	protected:
		
	private:
		void addCustomer();
		void addOrder();
		void viewActiveCustomers();
		void packagesInTransit();
		void CouriersInTransit();
};

Admin::Admin(){
	
}

void Admin::trackOrder(string orderNum){
	string order,x,location,status;

	ifstream fileIn("Orders.txt");
	if(fileIn.fail()){
		cout << "No order tracking could be performed! File does not exist!" << endl;
		exit(0);
	}
	
	while(!fileIn.eof()){
		fileIn >> order >> x >> location >> x >> x >> status;
		if(orderNum == order){
			cout << "Order Number: " << order << endl;
			cout << "Package Location: " << location << endl;
			cout << "Order Status: " << status << endl;
			return;
		}
		
	}
	
	fileIn.close();
}

void Admin::updateOrder(string orderNum) {
	string line, temp, new_location, cur_location, dest_location, status;
	vector<string> line_info;
	
	int found, line_num = -1, action = 0; //action: remove(0), update(1)
	ifstream file("Orders.txt");
        ofstream backup("Backup.txt");
        fstream fileOut("Orders.txt");
        
	if(file.fail()){
		cout << "No order update could be performed! File does not exist!" << endl;
		exit(0);
	}

	while(1) {
            string input;
	cout << "What action would you like to perform?" <<
		"\n[0] Remove Order" << "\n[1] Update Order Location" << endl;
            getline(cin, input);
            stringstream stream(input);
            if(stream >> action && (action == 1 || action == 0)) break;
            cout << "Invalid selection, try again." << endl << endl;
        }
	
        if(action == 1) { //if update, store new location
            cout << "Enter the current location: " << endl;
            getline(cin, new_location);
        }
              
        
	//read file into vector
	for(int i = 0; getline(file, temp); i++) {
            line_info.push_back(temp);
	}
        
        //copy file (backup)
        for(auto &i : line_info) {
            backup << i << endl;
        }
        for(int i = 0; i < line_info.size(); i++) {
            stringstream data_stream(line_info[i]);
            getline(data_stream, temp, ' ');
            if(temp == orderNum) { //if we store the line number, we can read 3 times more to get the current location
                line_num = i;
                getline(data_stream, cur_location, ' ');
                getline(data_stream, cur_location, ' '); //stores current location
                getline(data_stream, dest_location, ' '); //stores destination location
                getline(data_stream, temp, ' ');
                getline(data_stream, status, ' ');      //stores status
            }
            if(action == 0 && line_num != -1) { //remove case
                line_info[i].erase(line_info[i].begin()+line_num);
            }
            if(action == 1 && line_num != -1) { //update case
                line_info[i].replace(line_info[i].find(cur_location), cur_location.length(), new_location);
                if(new_location == dest_location) line_info[i].replace(line_info[i].find(status), status.length(), "complete");
                break;
            }
        }
        //cout << "Line Number: " << line_num << endl;
        //write data back out to file
        for(auto &i : line_info) {
            fileOut << i << endl;
        }
        file.close();
        backup.close();
        fileOut.close();
}

Admin::~Admin(){
	
}
class Courier : public Admin {
	public:
		Courier();
		~Courier();
		void getHistory();
};

Courier::Courier(){
	
}

Courier::~Courier(){
	
}

class Customer : public Courier{
	public:
		Customer();
		~Customer();
		void getHistory();
};

Customer::Customer(){
	
}

Customer::~Customer(){
	
}
 
 int main(){
	int test, selection = 0;
	
	Admin adminTester;
	Courier courierTester;
	Customer customerTester;
	
	cout << "testing admin login: "<< endl;
	 
	 //checks for an admin login
	test = login("Aaron","1234");
	 
	if(test == 1)
		//prints if the login worked
		cout << "Success!" << endl << endl;

	//test for a rudimentary tracking method
	cout << endl << "tracking order by admin:" << endl;
	adminTester.trackOrder("12345");
	
	cout << endl << "tracking order by courier:" << endl;
	courierTester.trackOrder("12345");
	
	cout << endl << "tracking order by customer:" << endl;
	customerTester.trackOrder("12345");
	
	
	while(selection != 0) {
		
	}
	adminTester.updateOrder("1234545");
 }
 
int login(string name, string password){
	string user;
	string pass;
	string rank;
	
	ifstream fileIn("Authentication.txt");
	if(fileIn.fail()){
		cout << "No Authentication could be performed! File does not exist!" << endl;
		exit(0);
	}
	
	while(!fileIn.eof()){
		fileIn >> user >> pass >> rank;
		//cout << "username: " << user << endl << "password: " << pass << endl;
		if(name == user && password == pass)
			if(rank == "admin"){
				fileIn.close();
				return 1;
			}
			if(rank == "courier"){
				fileIn.close();
				return 2;
			}
			if(rank == "customer"){
				fileIn.close();
				return 3;
			}
	}
	
	fileIn.close();
	return -1;	
 }

