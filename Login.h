 
#ifndef __Login_h_INCLUDED__
#define __Login_h_INCLUDED__

int login(string name, string password){
	string user;
	string pass;
	string rank;
	UI ui;
	
	ifstream fileIn("Authentication.txt");
	if(fileIn.fail()){
		cout << "No Authentication could be performed! File does not exist!" << endl;
		exit(0);
	}
	
	while(!fileIn.eof()){
		fileIn >> user >> pass >> rank;
		//cout << "username: " << user << endl << "password: " << pass << endl;
		if(name == user && password == pass){
			if(rank == "admin"){
				fileIn.close();
				Admin admin;
				ui.display(admin);
				return 1;
			}
			if(rank == "courier"){
				fileIn.close();
				Courier courier;
				ui.display(courier);
				return 2;
			}
			if(rank == "customer"){
				fileIn.close();
				Customer customer;
				ui.display(customer);
				return 3;
			}
		}
	}
	
	fileIn.close();
	return -1;	
 }

 #endif