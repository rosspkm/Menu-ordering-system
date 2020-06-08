#include <iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;
//MenuItem struct
struct menuItemType {
	string menuItem;
	double menuPrice;
	int Count;
};
//Function prototypes
void getData(menuItemType* pMenu);
void printCheck(vector<menuItemType> order);
void showMenu(menuItemType pMenu[], vector<menuItemType>& order);
int main()
{
	//Create menuItem array
	menuItemType menuList[8];
	//Order vector
	vector<menuItemType> order;
	//Read data from file and store into array
	getData(menuList);
	//Show menu and take order from customer
	showMenu(menuList, order);
	//Print bill
	printCheck(order);
}
/*
   Function: getData
   ParamIn: Array pointer
   ParamOut: None
   Description: Open file read menu details line by line
   Split line to get item name and price add into array
   and close file
*/
void getData(menuItemType* pMenu) {
	ifstream infile("items.txt");
	string line;
	for (int i = 0; i < 8; i++) {
		getline(infile, line);
		pMenu->menuItem = line.substr(0, line.length() - 5);
		pMenu->menuPrice = stod(line.substr(line.length() - 4, line.length()));
		pMenu->Count = 0;
		pMenu++;
	}
	infile.close();
}
/*
Function: showMenu
ParamIn: Menu array and order vector
ParamOut: None
Description: Display breakfast menu
			  Prompt for user choice and count
			  Add into order vector
			  with calculated price
*/
void showMenu(menuItemType pMenu[], vector<menuItemType>& order) {
	int opt, cnt;
	char ch;
	cout << fixed << setprecision(2);
	do {
		//Display menu
		cout << "BreakFast Menu:-" << endl;
		for (int i = 0; i < 8; i++) {
			cout << (i + 1) << "   ";
			cout.width(20); cout << left << pMenu[i].menuItem << right << "$" << pMenu[i].menuPrice << endl;
		}
		//Prompt for user choice
		cout << "Enter your choice(1-8): ";
		cin >> opt;
		while (opt < 1 || opt>8) {
			cout << "Enter your choice(1-8): ";
			cin >> opt;
		}
		//Prompt for number of item order
		cout << "Enter number of items: ";
		cin >> cnt;
		//Add corresponding value to order vector
		if (opt == 1) {
			menuItemType item = pMenu[0];
			item.Count = cnt;
			item.menuPrice = item.menuPrice * cnt;
			order.push_back(item);
		}
		else if (opt == 2) {
			menuItemType item = pMenu[1];
			item.Count = cnt;
			item.menuPrice = item.menuPrice * cnt;
			order.push_back(item);
		}
		else if (opt == 3) {
			menuItemType item = pMenu[2];
			item.Count = cnt;
			item.menuPrice = item.menuPrice * cnt;
			order.push_back(item);
		}
		else if (opt == 4) {
			menuItemType item = pMenu[3];
			item.Count = cnt;
			item.menuPrice = item.menuPrice * cnt;
			order.push_back(item);
		}
		else if (opt == 5) {
			menuItemType item = pMenu[4];
			item.Count = cnt;
			item.menuPrice = item.menuPrice * cnt;
			order.push_back(item);
		}
		else if (opt == 6) {
			menuItemType item = pMenu[5];
			item.Count = cnt;
			item.menuPrice = item.menuPrice * cnt;
			order.push_back(item);
		}
		else if (opt == 7) {
			menuItemType item = pMenu[6];
			item.Count = cnt;
			item.menuPrice = item.menuPrice * cnt;
			order.push_back(item);
		}
		else if (opt == 8) {
			menuItemType item = pMenu[7];
			item.Count = cnt;
			item.menuPrice = item.menuPrice * cnt;
			order.push_back(item);
		}
		//Repetition pary
		cout << "\nDo you want to enter again(y/n)? ";
		cin >> ch;
		cout << endl;
	} while (toupper(ch) == 'Y');
}
/*
Function: printCheck
ParamIn: Order vector
ParamOut: None
Description: Loop through order print details and calculate total tax and due
Display bill
*/
void printCheck(vector<menuItemType> order) {
	cout << fixed << setprecision(2);
	double total = 0;
	cout << "\nWelcome to Johnny's Restaurant" << endl;
	for (int i = 0; i < order.size(); i++) {
		cout.width(20); cout << left << order[i].menuItem << right << order[i].Count;
		cout.width(15); cout << right << "$" << order[i].menuPrice << endl;
		total += order[i].menuPrice;
	}
	cout.width(35); cout << left << "Amount Total" << right << "$" << total << endl;
	cout.width(35); cout << left << "Tax" << right << "$" << 0.22 << endl;
	cout.width(35); cout << left << "Amount Due" << right << "$" << (total + .22) << endl;
}