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
	
}

Customer::~Customer(){
	
}


#endif