#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
// struct for all the variables
struct person
{
  string name;
  double income;
};

struct liability
{
  double ele;
  double water;
  double gas;
  double wifi;
  double phone;
  double insurance;
  double loansOther;
};

struct assets
{
  double cashOnHand;
	double checkingAccounts;
	double savingsAccounts;
	double moneyMarkets;
	double primaryResidence;
	double vehicle;
	double otherAssets;
};

int main()
{
  //declaration of the structs
  person p;
  liability l;
  assets a;

//Making person
  cout<<"Enter the name: ";
  cin>>p.name;
  cout<<"Enter the income: $";
  cin>>p.income;

  //cout<<p.name<<endl<<p.income;
//making liabilities
  cout<<"Electricity: $";
  cin>>l.ele;
  cout<<"Water: $";
  cin>>l.water;
  cout<<"Gas: $";
  cin>>l.gas;
  cout<<"Wi-Fi: $";
  cin>>l.wifi;
  cout<<"Phone: $";
  cin>>l.phone;
  cout<<"Insurance: $";
  cin>>l.insurance;
  cout<<"Other Liability: $";
  cin>>l.loansOther;

  //cout<<l.ele<<endl<<l.water<<endl<<l.gas<<endl<<l.wifi<<endl<<l.phone<<endl<<l.insurance<<endl<<l.loansOther<<endl;
// making assets
  cout<<"Cash On Hand: $";
  cin>>a.cashOnHand;
  cout<<"Checking Accounts: $";
  cin>>a.checkingAccounts;
  cout<<"Savings Accounts: $";
  cin>>a.savingsAccounts;
  cout<<"Money Market: $";
  cin>>a.moneyMarkets;
  cout<<"Primary Residence: $";
  cin>>a.primaryResidence;
  cout<<"Vehicle : $";
  cin>>a.vehicle;
  cout<<"Other Assets : $";
  cin>>a.otherAssets;

// computing the net worth
  double tot_asset = a.cashOnHand + a.checkingAccounts + a.savingsAccounts + a.moneyMarkets + a.primaryResidence + a.vehicle + a.otherAssets;
  double tot_lia = l.ele + l.water + l.gas + l.wifi + l.phone + l.insurance + l.loansOther;
  double networth = p.income + tot_asset - tot_lia;

//printing to the file
  ofstream fdata;
  fdata.open("Report.txt");
  fdata<<"-----Net Worth Report-----"<<endl<<endl;
  fdata<<"Name: "<<p.name;
  fdata<<"\t\tIncome: $"<<p.income<<endl<<endl;
  fdata<<"\n****Liabilitities****"<<endl<<endl;
  fdata<<"Electricity: $"<<l.ele<<endl<<"Water: $"<<l.water<<endl<<"Gas: $"<<l.gas<<endl<<"Wi-Fi: $"<<l.wifi<<endl<<"Phone: $"<<l.phone<<endl<<"Insurance: $"<<l.insurance<<endl<<"Other Liability: $"<<l.loansOther<<endl;
  fdata<<"Total Liabilities: $"<<tot_lia<<endl<<endl;

  fdata<<"\n****Assets:****"<<endl<<endl;
  fdata<<"Cash On Hand: $"<<a.cashOnHand<<endl<<"Checking Accounts: $"<<a.checkingAccounts<<endl<<"Savings Accounts: $"<<a.savingsAccounts<<endl<<"Money Market: $"<<a.moneyMarkets<<endl<<"Primary Residence: $"<<a.primaryResidence<<endl<<"Vehicle : $"<<a.vehicle<<endl<<"Other Assets : $"<<a.otherAssets<<endl<<endl;
  fdata<<"Total Assets: $"<<tot_asset<<endl<<endl;
  fdata<<"\nYour net worth is $"<<networth<<endl<<endl;

  //printing to the screen
  cout<<"\n\nTotal Liabilities: $"<<tot_lia<<endl<<endl;

  cout<<"Total Assets: $"<<tot_asset<<endl<<endl;

  cout<<"\nYour net worth is $"<<networth<<endl<<endl;


	fdata.close();

}
