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
#include<vector>
#include<stdlib.h>
#include<stdio.h>

#include"Admin.h"
#include"Courier.h"
#include"Customer.h"
#include"UserInterface.h"
#include"Miscellaneous.h"
#include"Login.h"

using namespace std;

 int main(){
	 string user;
	 string pass;
	 int log;
	 
	 
	 cout << "Please Enter Your Username: ";
	 getline(cin,user);
	 cout << "Please Enter Your Password: ";
	 getline(cin,pass);
	 
	 log = login(user,pass);
	 /*
	int test, selection = 0;
	
	Admin adminTester;
	Courier courierTester;
	Customer customerTester;
	UI uiTest;
	
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

	adminTester.updateOrder("1234545");
	
	uiTest.display(adminTester);
	uiTest.display(courierTester);
	uiTest.display(customerTester);
	*/
 }