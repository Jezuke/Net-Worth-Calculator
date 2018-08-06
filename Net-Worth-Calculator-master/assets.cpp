#include <iostream>
#include <vector>
#include <gtkmm.h>

using namespace std;
using namespace Gtk;
class Assets
{
public:
	vector <string> other;
	vector<double> otherF;
	double cashOnHand;
	double checkingAccounts;
	double savingsAccounts;
	double MoneyMarkets;
	double PrimaryResidence;
	double vehicle;

	double total_assets()
	{
		double otherT=0;
		for(int i = 0; i<other.size();i++)
		{
			otherT = otherT+otherF[i];
		}
		double total = otherT+cashOnHand+checkingAccounts+savingsAccounts+MoneyMarkets+PrimaryResidence+vehicle;
		return total;
	}

	void add_other(string otherAsset, double amount)
	{
		other.push_back(otherAsset);
		otherF.push_back(amount);
	}
};

class AssetWindow:public Gtk::Window
{
public:
	AssetWindow()
	{
		set_title("Assets");
		Box box1 (ORIENTATION_VERTICAL);
		Box box_top(ORIENTATION_VERTICAL);
		set_size_request(500,100);
		add(box_top);
		
		Label l1("Cash on Hand:");
		box_top.pack_start(l1);
	}

}
