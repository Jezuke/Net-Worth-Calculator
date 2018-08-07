#include "pro_gui.hpp"
#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

int main(int argc, char** argv){
	Main kit(argc,argv);

	Person p = Dialogs::inputInfo("Information");
	p.fillLiaAss();

	liability l;
	string * ret = Dialogs :: input("Liability (monthly)");

	for(int i = 0; i<7;i++)
	{
		l.liaValue.push_back(stof(ret[i]));
	}

	/*l.ele = stof(ret[0]);
	l.water = stof(ret[1]);
	l.gas = stof(ret[2]);
	l.wifi = stof(ret[3]);
	l.phone = stof(ret[4]);
	l.insurance = stof(ret[5]);
	l.loansOther = stof(ret[6]);*/

	double totalLia = l.total_lia();

	Assets a;
	string * retAsset= Dialogs::inputAssets("Asset(monthly)");
	
	for(int j = 0; j<7;j++)
	{
		a.assValue.push_back(stof(retAsset[j]));
	}

	/*a.cashOnHand= stof(retAsset[0]);
	a.checkingAccounts= stof(retAsset[1]);
	a.savingsAccounts =stof(retAsset[2]);
	a.MoneyMarkets=stof(retAsset[3]);
	a.PrimaryResidence=stof(retAsset[4]);
	a.vehicle=stof(retAsset[5]);
	a.other = stof(retAsset[6]);*/

	double totalAssets = a.total_assets();

	double totalNet =p.income+ totalAssets-totalLia;

	Dialogs::message("Here is your report: " + p.name + " with income of $" + to_string(p.income).substr(0,to_string(p.income).size()-4),"Thank you");
	Dialogs::message("Total Liabilities:  $"+to_string(totalLia).substr(0, to_string(totalLia).size()-4), "Thank you!");
	Dialogs::message("Total Assets: $ "+ to_string(totalAssets).substr(0, to_string(totalAssets).size()-4), "Thank you!");
	Dialogs::message("Total Net Worth as of the current month: $" + to_string(totalNet).substr(0, to_string(totalNet).size()-4), "Thank you!");

	//Place in function
	ofstream report;
	report.open("networth.txt");
	report<<"\n****Liabilitities****\n\n";
	for(int x= 0; x<p.liabilities.size();x++)
	{
		report << p.liabilities[x]<<l.liaValue[x]<<endl;
	}
	report<<"\n****Assets:****\n\n";
	for(int x= 0; x<p.liabilities.size();x++)
	{
		report << p.assets[x]<<a.assValue[x]<<endl;
	}
	
	report.close();
	return 0;

}
