#include "pro_gui.hpp"
#include <iostream>

using namespace std;

int main(int argc, char** argv){
	Main kit(argc,argv);
	liability l;
	string * ret = Dialogs :: input("Liability (monthly)");

	l.ele = stof(ret[0]);
	l.water = stof(ret[1]);
	l.gas = stof(ret[2]);
	l.wifi = stof(ret[3]);
	l.phone = stof(ret[4]);
	l.insurance = stof(ret[5]);
	l.loansOther = stof(ret[6]);

	Dialogs::message("electricity is "+ret[0], "Thank you!");

	return 0;


}
