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

class Admin{
	public: 
		Admin();
		~Admin();
		void trackOrder();
	protected:
		void updateOrder();
	private:
		void addCustomer();
		void addOrder();
		void viewActiveCustomers();
		void packagesInTransit();
		void CouriersInTransit();
};

class Courier : public Admin {
	public:
		Courier();
		~Courier();
		void getHistory();
};

class Customer : public Courier{
	public:
		Customer();
		~Customer();
		void getHistory();
};

