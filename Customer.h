#include"Courier.h"

#ifndef __Customer_h_INCLUDED__
#define __Customer_h_INCLUDED__

using namespace std;

class Customer : public Courier{
	public:
		Customer();
		~Customer();
		void getHistory();
};

Customer::Customer(){
	rank = "customer";
}

void Customer::getHistory(){
string word,temp;
	vector< vector<string> > history;
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
		//checks if the order belongs to the current customer
		if(order[1].compare(username) == 0){
			history.push_back(order);
		}
		
		//creates template
		if(!copied)
			setup = order;
		copied = true;
	}
	
	//sometimes formatting messes up here if in full screen terminal - no idea why
	//dispalys column names
	cout << "    " << left << setw(20) << setup[0] << setw(20) << setup[3] << setw(20) << setup[5] << endl;
	//displays all the info row by row
	for(int i = 0; i < history.size(); i++){
		cout << endl << "(" << i+1 << ") " << setw(20)
		<< history[i][0]<< setw(20) << history[i][3]<< setw(20) << history[i][5];
	}

	cout << endl;
	fileIn.close();
	return;	
}
Customer::~Customer(){
	
}


#endif