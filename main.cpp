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
#include<iomanip>
#include<algorithm>

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
	
	return 1;
 }