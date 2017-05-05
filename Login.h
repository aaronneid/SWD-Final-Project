 
#ifndef __Login_h_INCLUDED__
#define __Login_h_INCLUDED__

int login(string name, string password){
	string word,temp;
	UI ui;
	
	ifstream fileIn("Authentication.txt");
	if(fileIn.fail()){
		//throws error if authentication file could not be opened
		throw "No Authentication could be performed! File does not exist!";
	}
	
	//gets a line from the file as a string
	while(getline(fileIn, temp)){
		stringstream inputStream;
		vector<string> account;
		int y = 0;

		//converts the string into a string stream
		inputStream << temp;
		//uses string stream and getline to break the string up into strings seperated by the | delimiter
		while(getline(inputStream,word,'|')){
			//adds each entry to a vector
			account.push_back(word);
		}
		
		//checks if a valid login has been entered
		if(!name.compare(account[0]) && !password.compare(account[1])){
			//checks for the rank of the user
			if(!account[2].compare("admin")){
				fileIn.close();
				Admin admin;
				admin.username = account[0];
				admin.password = account[1];
				ui.display(admin);
				fileIn.close();
				return 1;
			}
			if(!account[2].compare("courier")){
				fileIn.close();
				Courier courier;
				courier.username = account[0];
				courier.password = account[1];
				ui.display(courier);
				fileIn.close();
				return 2;
			}
			if(!account[2].compare("customer")){
				fileIn.close();
				Customer customer;
				customer.username = account[0];
				customer.password = account[1];
				ui.display(customer);
				fileIn.close();
				return 3;
			}
		}

	}
	
	fileIn.close();
	//throws error if there is no matching info in the authentication file
	throw "No user could be found with that username and password.";
	return -1;	
 }

 #endif