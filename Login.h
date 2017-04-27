 
#ifndef __Login_h_INCLUDED__
#define __Login_h_INCLUDED__

int login(string name, string password){
	string word;
	UI ui;
	
	ifstream fileIn("Authentication.txt");
	if(fileIn.fail()){
		cout << "No Authentication could be performed! File does not exist!" << endl;
		exit(0);
	}
	
	while(fileIn){
		stringstream inputStream;
		string temp;
		vector<string> account;
		int y = 0;
		
		//gets a line from the file as a string
		getline(fileIn, temp);
		//converts the string into a string stream
		inputStream << temp;
		//uses string stream to break the string up into strings seperated by the | delimiter
		while(getline(inputStream,word,'|')){
			//adds each entry to a vector
			account.push_back(word);
		}
		//checks if a valid login has been entered
		if(name.compare(account[0]) && password.compare(account[1])){
			//checks for the rank of the user
			if(account[2].compare("admin")){
				fileIn.close();
				Admin admin;
				ui.display(admin);
				return 1;
			}
			if(account[2].compare("courier")){
				fileIn.close();
				Courier courier;
				ui.display(courier);
				return 2;
			}
			if(account[2].compare("customer")){
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