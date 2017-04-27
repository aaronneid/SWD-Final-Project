#include"Admin.h"

#ifndef __Courier_h_INCLUDED__
#define __Courier_h_INCLUDED__

using namespace std;

class Courier : public Admin {
	public:
		Courier();
		~Courier();
		void getHistory();
};

Courier::Courier(){
	
}

Courier::~Courier(){
	
}

#endif