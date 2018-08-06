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

	double totalLia = l.total_lia();

	Assets a;
	string * retAsset= Dialogs::inputAssets("Asset(monthly)");

	a.cashOnHand= stof(retAsset[0]);
	a.checkingAccounts= stof(retAsset[1]);
	a.savingsAccounts =stof(retAsset[2]);
	a.MoneyMarkets=stof(retAsset[3]);
	a.PrimaryResidence=stof(retAsset[4]);
	a.vehicle=stof(retAsset[5]);
	a.other = stof(retAsset[6]);

	double totalAssets = a.total_assets();

	double totalNet = totalAssets-totalLia;

	Dialogs::message("Total Liabilities:  $"+to_string(totalLia).substr(0, to_string(totalLia).size()-4), "Thank you!");
	Dialogs::message("Total Assets: $ "+ to_string(totalAssets).substr(0, to_string(totalAssets).size()-4), "Thank you!");
	Dialogs::message("Total Net Worth as of the current month: $" + to_string(totalNet).substr(0, to_string(totalNet).size()-4), "Thank you!");

	return 0;


}
