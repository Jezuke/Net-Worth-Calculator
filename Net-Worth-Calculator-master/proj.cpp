#include "pro_gui.hpp"
#include <iostream>
#include <fstream>
#include<iomanip>
using namespace std;

void output(string file, Person p, liability l, Assets a, double totalLia, double totalAssets, double totalNet)
{
	ofstream report;
	report.open(file);
	report<<"---------Month's Net Worth Report--------\n\n";
	report<<"Name: " << p.name << "	" << "	Income: $" <<p.income<<"\n\n";
	report<<"\n****Liabilitities****\n\n";
	for(int x= 0; x<p.liabilities.size();x++)
	{
		report << p.liabilities[x]<<l.liaValue[x]<<endl;
	}
	report<<"\n====Total Liabilities: $" << totalLia<< "====\n";
	report<<"\n****Assets:****\n\n";
	for(int x= 0; x<p.liabilities.size();x++)
	{
		report << p.assets[x]<<a.assValue[x]<<endl;
	}
	report<<"\n====Total Assets: $" << totalAssets<<"====\n";
	report<<"\n\n=======Net Worth: $"<<totalNet<<"=========\n"<<endl;

	report.close();
}

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

	double totalLia = l.total_lia();

	Assets a;
	string * retAsset= Dialogs::inputAssets("Asset(monthly)");
	
	for(int j = 0; j<7;j++)
	{
		a.assValue.push_back(stof(retAsset[j]));
	}

	double totalAssets = a.total_assets();

	double totalNet =p.income+ totalAssets-totalLia;

	Dialogs::message("Here is your report: " + p.name + " with income of $" + to_string(p.income).substr(0,to_string(p.income).size()-4),"Thank you");
	Dialogs::message("Total Liabilities:  $"+to_string(totalLia).substr(0, to_string(totalLia).size()-4), "Thank you!");
	Dialogs::message("Total Assets: $ "+ to_string(totalAssets).substr(0, to_string(totalAssets).size()-4), "Thank you!");
	Dialogs::message("Total Net Worth as of the current month: $" + to_string(totalNet).substr(0, to_string(totalNet).size()-4), "Thank you!");


	output("networth.txt", p, l, a, totalLia,totalAssets,totalNet);

	return 0;

}
