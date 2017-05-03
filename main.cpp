//============================================================================
// Software Development Final Project
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
#include<limits>

#include"Admin.h"
#include"Courier.h"
#include"Customer.h"
#include"UserInterface.h"
#include"Miscellaneous.h"
#include"Login.h"

using namespace std;

 int main(){
	ClearScreen();
	string user;
	string pass;
	int log;
	
	cout << "Please Enter Your Username: ";
	getline(cin,user);
	cout << "Please Enter Your Password: ";
	getline(cin,pass);
	
	try{
		log = login(user,pass);
	}catch(const char* loginError){
		cout << loginError << endl;
	}
	
	return 1;
 }