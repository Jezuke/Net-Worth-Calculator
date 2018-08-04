/*
Name: Archit Kalpeshkumar Jaiswal
UTA ID: 1001543326
HW5
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

class liability
{
public:

  double ele;
  double water;
  double gas;
  double wifi;
  double phone;
  double insurance;
  double loansOther;

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

	    Gtk::Dialog *dialog = new Gtk::Dialog();
	    dialog->set_title(title);
	    Gtk::Label *lab[7];
	    Gtk::Entry *ent[7];
	    //Gtk::Label *label = new Gtk::Label(msg);

		//electricity
		lab[0] = new Gtk::Label("How much was you last month's electricity bill? ");
	    ent[0] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[0]);
	    lab[0]->show();
	    ent[0]->set_text(default_text);
	    ent[0]->set_max_length(50);
	    ent[0]->show();
	    dialog->get_vbox()->pack_start(*ent[0]);

	    //water
	    lab[1] = new Gtk::Label("How much was you last month's water bill? ");
	    ent[1] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[1]);
	    lab[1]->show();
	    ent[1]->set_text(default_text);
	    ent[1]->set_max_length(50);
	    ent[1]->show();
	    dialog->get_vbox()->pack_start(*ent[1]);

	    //gas
	    lab[2] = new Gtk::Label("How much was you last month gas bill? ");
	    ent[2] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[2]);
	    lab[2]->show();
	    ent[2]->set_text(default_text);
	    ent[2]->set_max_length(50);
	    ent[2]->show();
	    dialog->get_vbox()->pack_start(*ent[2]);

	    //wifi
	    lab[3] = new Gtk::Label("How much was you last month's Internet bill? ");
	    ent[3] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[3]);
	    lab[3]->show();
	    ent[3]->set_text(default_text);
	    ent[3]->set_max_length(50);
	    ent[3]->show();
	    dialog->get_vbox()->pack_start(*ent[3]);

	    //phone
	    lab[4] = new Gtk::Label("How much was you last month's phone bill? ");
	    ent[4] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[4]);
	    lab[4]->show();
	    ent[4]->set_text(default_text);
	    ent[4]->set_max_length(50);
	    ent[4]->show();
	    dialog->get_vbox()->pack_start(*ent[4]);

	    //insurance
	    lab[5] = new Gtk::Label("How much was you last month's insurance premium? ");
	    ent[5] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[5]);
	    lab[5]->show();
	    ent[5]->set_text(default_text);
	    ent[5]->set_max_length(50);
	    ent[5]->show();
	    dialog->get_vbox()->pack_start(*ent[5]);

	    //loans
	    lab[6] = new Gtk::Label("How much was you last month's loans instalment? ");
	    ent[6] = new Gtk::Entry();
	    dialog->get_content_area()->pack_start(*lab[6]);
	    lab[6]->show();
	    ent[6]->set_text(default_text);
	    ent[6]->set_max_length(50);
	    ent[6]->show();
	    dialog->get_vbox()->pack_start(*ent[6]);

	    //last
	    dialog->add_button("Reset", 0);

	    dialog->add_button("OK",1);

	    dialog->set_default_response(1);

	    int result = dialog->run();

		string * text = new string[7];
		for(int i=0; i<7; i++)
		{
			text[i] = ent[i]->get_text();

			if(default_text == text[i])
			{
			text[i] ="0";
			}
		}

	    dialog->close();

	    while (Gtk::Main::events_pending())

	    Gtk::Main::iteration();

	    delete dialog;
		for(int i=0;i<7;i++)
		{
		    delete lab[i];

		    delete ent[i];
		}


			/*ele = stof(text[0]);
			water = stof(text[1]);
			gas = stof(text[2]);
			wifi = stof(text[3]);
			phone = stof(text[4]);
			insurance = stof(text[5]);
			loansOther = stof(text[6]);*/
			return text;

	}



//asks conformation question
  static int question(string msg,string title, vector<std::string> buttons)
  {

    Dialog *dialog = new Gtk::Dialog();
    dialog->set_title(title);
    Label *label = new Gtk::Label(msg);
    dialog->get_content_area()->pack_start(*label);
    label->show();
    for (int i = 0; i < (int)buttons.size(); i++)
    dialog->add_button(buttons[i], i); //i	corresponds	to	signal
    int result = dialog->run();
    dialog->close();
    while (Main::events_pending())
    Main::iteration();
    delete dialog;
    delete label;
    return result; //returns	number-signals	to	us	which	button	was	pushed
  }
};

//holds information about seller


#endif
