//prog.cpp
//Programmer: Logan Kelsch
//Grocery List Program
//Date: 9/12/2023 - 9/19/23

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


int main(){
       //declaring in and out data access to final file
       ofstream outdata;
       outdata.open("Kelsch_Logan.txt");
       ifstream indata;
       indata.open("item.txt");
       //welcoming texts, 'comm' variable for out-of-major-loop execution
       cout<<"Welcome To Logan's Grocery System Menu\n------------\n";
       char comm = 'a';
       cout<<"1. Enter New Number (n)\n2. Quit and Print Receipt (q)\n\n";
       cin>>comm;
       cout<<endl;
       //initial pre-loop printing into file
       outdata<<"Item Number   \tItem Name\tUnit\tUnit Price\t Tax\tSubtotal\n";
       outdata<<"-----------   \t---------\t----\t----------\t ---\t--------\n";
       int itemNum;//itemNum is the intake data to compare to requested 'num'
       char itemName[30];//name grabbed when item found
       char taxable;//tax info grabbed when item found
       double tax;
       char type;//count type info grabbed when item found
       double price;//price is per unit after item found
       double count=1;//count is for math purposes of number/pounds
       double itemTot;//total price after calculations
       double total=0;//final price
       do{//following do while loop is to loop for every item wanted.
         indata.seekg(ios::beg);
          if(comm=='q')//used to break loop when user is done
            break;
	  bool itemFound = false; // used to ensure the item added exists in item.txt
  int num;
  bool escapeLoop = false; // used to exit search loop under eof condition
  while (itemFound ==
         false) { // used to ensure loop of entering and finding items
    escapeLoop = false;
    indata.clear(); // 23-24 used to reset file search location upon re-entry
    indata.seekg(ios::beg);
    cout << "\n\tPlease input item number:\n\n";
    cin >> num; // entry of search number
    int in;
    // now while loop to search for item
    indata >> in;
    while (num != in &&
           !escapeLoop) { // loop to pull in new data searching for item numbers
      if (indata.eof()) { // if loop has ran to the end of the file
        cout << "\n\tItem not Found. Please try again.";
        break;
      }
      indata >> in;           // main loop function
      while (indata.fail()) { // while data pulled in is not an int (item name
                              // or letter)
        indata.clear(); // 37-38 used to discard non int input
        indata.ignore(256, '\n');
        indata >> in;       // pulling in data until int
        if (indata.eof()) { // if within this next loop, end of file is reached
          cout << "\n\tItem not Found. Please try again.";
          escapeLoop = true; // used to cancel search, as the item is not there.
          break;
        }
      }
    }
    num == in ? itemFound = true : false; // if the item is found in item.txt
  }
	indata>>itemName;
	indata>>taxable;
	taxable=='t'?tax=1:tax=0;
	indata>>type;
	switch(type){
		case 's':
			count=1;
			break;
		case 'p':
			cout<<"\nHow many pounds would you like?\n\n";
			cin>>count;
			break;
		case 'n':
			cout<<"\nHow many would you like\n\n";
			cin>>count;
			break;
		}
	indata>>price;
	itemTot=count*price;
	tax=tax*.06*itemTot;
	total=total+itemTot+tax;
	//print each item
	outdata<<num<<right<<setw(27)<<itemName<<setw(7)<<count<<setw(14)<<price<<setw(6)<<fixed<<setprecision(2)<<tax<<setw(12)<<itemTot<<endl;
         //re-ask put at bottom of loop to make looping easy
          cout<<"\n\n1. Enter New Number (n)\n2. Quit and Print Receipt (q)\n\n";
          cin>>comm;
       }while(comm!='q');//while the user does not request to quit program
      outdata<<"\t\tTotal: $"<<total;//outputting total cost at bottom
       outdata.close();
      indata.close();
       return 0;
}


