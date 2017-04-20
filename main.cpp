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
	protected:
		void updateOrder();
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
	int test;
	
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

