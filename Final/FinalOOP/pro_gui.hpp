/*
Name: Archit Kalpeshkumar Jaiswal/Michael Jezreel Aquitania
UTA ID: 1001543326/1001542979
Extra Credit
*/
#ifndef _CLOSET_FUNC_C
#define _CLOSET_FUNC_C
#include <iostream>
#include <memory>
#include <vector>
#include <gtkmm.h>
#include <string>

using namespace std;
using namespace Gtk;

//creates dialog and prompt messages

class Person
{

public:
	vector<string> liabilities;
	vector<string> assets;
	string name;
	double income;

	void fillLiaAss()
	{
		liabilities.push_back("Electricity Bill: $");
		liabilities.push_back("Water Bill: $");
		liabilities.push_back("Gas Bill: $");
		liabilities.push_back("Internet Bill: $");
		liabilities.push_back("Insurance Premium: $");
		liabilities.push_back("Phone bill: $");
		liabilities.push_back("Loans Installment: $");

		assets.push_back("Cash in Hand: $");
		assets.push_back("Checking Account: $");
		assets.push_back("Savings Account: $");
		assets.push_back("Brokerage Accounts (stocks,etc.): $");
		assets.push_back("Primary Residence: $");
		assets.push_back("Vehicle: $");
		assets.push_back("Other: $");
	}	

};


class liability
{
public:
	vector <double> liaValue;

	double total_lia()
	{
		
		double total = 0;
		for(int i = 0; i< liaValue.size();i++)
		{
			total = total + liaValue[i];
		}
		return total;
	}

};

class Assets
{
public:
	vector <double> assValue;

	double total_assets()
	{
		double total=0;
		for(int i = 0; i<assValue.size();i++)
		{
			total = total+assValue[i];
		}
		return total;
	}

};

class Dialogs
{

public:

  static void message(string msg, string title)
  {
    MessageDialog *dialog = new MessageDialog(title);
    dialog->set_secondary_text(msg, true);
    dialog->run();

    dialog->close();

    while (Main::events_pending())

    Main::iteration();

    delete dialog;
  }

//accepts user inputs
   static string * input(string title, string default_text="")
  {
	    Gtk::Label *lab[7];
	    Gtk::Entry *ent[7];

	    Gtk::Dialog *dialog = new Gtk::Dialog();
	    dialog->set_title(title);
	    

	    Gtk::Label *label = new Gtk::Label("Liabilities ($)");
	    dialog->get_content_area()->pack_start(*label);
	    label->show();

	//labels above each entry box
	   lab[0] = new Gtk::Label("Electricity Bill: ");
	    ent[0] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[0]);
	    lab[0]->show();
	    ent[0]->set_text(default_text);
	    ent[0]->set_max_length(50);
	    ent[0]->show();
	    dialog->get_vbox()->pack_start(*ent[0]);

	    lab[1] = new Gtk::Label("Water Bill: ");
	    ent[1] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[1]);
	    lab[1]->show();
	    ent[1]->set_text(default_text);
	    ent[1]->set_max_length(50);
	    ent[1]->show();
	    dialog->get_vbox()->pack_start(*ent[1]);

	    lab[2] = new Gtk::Label("Gas Bill: ");
	    ent[2] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[2]);
	    lab[2]->show();
	    ent[2]->set_text(default_text);
	    ent[2]->set_max_length(50);
	    ent[2]->show();
	    dialog->get_vbox()->pack_start(*ent[2]);

	    lab[3] = new Gtk::Label("Internet Bill: ");
	    ent[3] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[3]);
	    lab[3]->show();
	    ent[3]->set_text(default_text);
	    ent[3]->set_max_length(50);
	    ent[3]->show();
	    dialog->get_vbox()->pack_start(*ent[3]);

	    lab[4] = new Gtk::Label("Phone bill: ");
	    ent[4] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[4]);
	    lab[4]->show();
	    ent[4]->set_text(default_text);
	    ent[4]->set_max_length(50);
	    ent[4]->show();
	    dialog->get_vbox()->pack_start(*ent[4]);

	    lab[5] = new Gtk::Label("Insurance Premium: ");
	    ent[5] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[5]);
	    lab[5]->show();
	    ent[5]->set_text(default_text);
	    ent[5]->set_max_length(50);
	    ent[5]->show();
	    dialog->get_vbox()->pack_start(*ent[5]);

	    lab[6] = new Gtk::Label("Loans Installment: ");
	    ent[6] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[6]);
	    lab[6]->show();
	    ent[6]->set_text(default_text);
	    ent[6]->set_max_length(50);
	    ent[6]->show();
	    dialog->get_vbox()->pack_start(*ent[6]);

	 dialog->add_button("Cancel", 0);

	    dialog->add_button("OK",1);

	    dialog->set_default_response(1);
	    int result = dialog->run();
		
		string * text = new string[7]; //gets the different values from the entyr boxes and puts them in array
		for(int i=0; i<7; i++)
		{
			text[i] = ent[i]->get_text();

			if(default_text == text[i])
			{
			text[i] ="0";
			}
		}

	    dialog->close();

	    while (Main::events_pending())
	  	{  
			Main::iteration();
		}
	
		if(result==0)
		{
			Main::quit();
		}

	    delete dialog;
		for(int i=0;i<7;i++)
		{
		    delete lab[i];

		    delete ent[i];
		}

			return text;

	}


static string * inputAssets(string title, string default_text="")
{

	Gtk::Label *lab1[7];
	 Gtk::Entry *ent1[7];

	Gtk::Dialog *dialog = new Gtk::Dialog();
	    dialog->set_title(title);

	    Gtk::Label *label = new Gtk::Label("Assets ($)");
	    dialog->get_content_area()->pack_start(*label);
	    label->show();

	//labels above each entry box
	   lab1[0] = new Gtk::Label("Cash in Hand: ");
	    ent1[0] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab1[0]);
	    lab1[0]->show();
	    ent1[0]->set_text(default_text);
	    ent1[0]->set_max_length(50);
	    ent1[0]->show();
	    dialog->get_vbox()->pack_start(*ent1[0]);


	    lab1[1] = new Gtk::Label("Checking Account: ");
	    ent1[1] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab1[1]);
	    lab1[1]->show();
	    ent1[1]->set_text(default_text);
	    ent1[1]->set_max_length(50);
	    ent1[1]->show();
	    dialog->get_vbox()->pack_start(*ent1[1]);


	    lab1[2] = new Gtk::Label("Savings Account: ");
	    ent1[2] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab1[2]);
	    lab1[2]->show();
	    ent1[2]->set_text(default_text);
	    ent1[2]->set_max_length(50);
	    ent1[2]->show();
	    dialog->get_vbox()->pack_start(*ent1[2]);

	    lab1[3] = new Gtk::Label("Brokerage Accounts (stocks,etc.): ");
	    ent1[3] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab1[3]);
	    lab1[3]->show();
	    ent1[3]->set_text(default_text);
	    ent1[3]->set_max_length(50);
	    ent1[3]->show();
	    dialog->get_vbox()->pack_start(*ent1[3]);


	    lab1[4] = new Gtk::Label("Primary Residence: ");
	    ent1[4] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab1[4]);
	    lab1[4]->show();
	    ent1[4]->set_text(default_text);
	    ent1[4]->set_max_length(50);
	    ent1[4]->show();
	    dialog->get_vbox()->pack_start(*ent1[4]);


	    lab1[5] = new Gtk::Label("Vehicle: ");
	    ent1[5] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab1[5]);
	    lab1[5]->show();
	    ent1[5]->set_text(default_text);
	    ent1[5]->set_max_length(50);
	    ent1[5]->show();
	    dialog->get_vbox()->pack_start(*ent1[5]);

	 
	    lab1[6] = new Gtk::Label("Other: ");
	    ent1[6] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab1[6]);
	    lab1[6]->show();
	    ent1[6]->set_text(default_text);
	    ent1[6]->set_max_length(50);
	    ent1[6]->show();
	    dialog->get_vbox()->pack_start(*ent1[6]);

	    //last
	    dialog->add_button("Cancel", 0);

	    dialog->add_button("OK",1);

	    dialog->set_default_response(1);

	    int result = dialog->run();

		string * text = new string[7];
		for(int i=0; i<7; i++)
		{
			text[i] = ent1[i]->get_text();

			if(default_text == text[i])
			{
			text[i] ="0";
			}
		}

	    dialog->close();

	    while (Main::events_pending())
		{
			Main::iteration();
		}
			
		if(result==0)
		{
			Main::quit();
		}

	    delete dialog;
		for(int i=0;i<7;i++)
		{
		    delete lab1[i];

		    delete ent1[i];
		}

			return text;

}

static Person inputInfo(string title, string default_text="")
{
	Dialog dialog;	
	dialog.set_title(title);

	dialog.add_button("Cancel", 0);
	dialog.add_button("OK",1);
	dialog.set_default_response(1);

	Label label("Enter your name:");
	dialog.get_content_area()->pack_start(label);
	label.show();
	Entry entryName;
	entryName.set_text(default_text);
	entryName.set_max_length(50);
	entryName.show();
	dialog.get_vbox()->pack_start(entryName);

	Label label2("Enter your income ($):");
	dialog.get_content_area()->pack_start(label2);
	label2.show();
	Entry entryIncome;
	entryIncome.set_text(default_text);
	entryIncome.set_max_length(50);
	entryIncome.show();
	dialog.get_vbox()->pack_start(entryIncome);

	int result=dialog.run();
	Person p1;
	p1.name = entryName.get_text();
	p1.income=stof(entryIncome.get_text());

	dialog.close();
	while(Main::events_pending())
	{
		Main::iteration();
	}
		
	if(result == 1)
		return p1;
	else
		Main::quit();
}
};



#endif
