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
	int log,check = 0;
	
	//allows the user three login attempts
	while(check < 4){
		//gets login info; this is case sensitive and uses the full name, however that was defined upon account creation as the username
		cout << "Please Enter Your Username: ";
		getline(cin,user);
		cout << "Please Enter Your Password: ";
		getline(cin,pass);
	
		try{
			//tries to login
			log = login(user,pass);
		}catch(const char* loginError){
			//displays error if login failed for any reason
			cout << loginError << endl;
			cout << "Please try again: " << endl;
			check++;
		}
	
	}
	
	return 1;
 }