#include <iostream>
#include <cstring>

using namespace std;

struct Item {
	string item_name;
	int amount;
	float price;
};

int main () {
	int x;
	int total = 0;
	int GrandTotal;
	cout << "Enter number of Items sold today (Maximum 10): ";
	cin >> x;
	

	cout << endl;
 	if (x <= 10) {
 		for (int i = 0; i < x; i++) {
			Item item[i];
		
			cout << "Enter Details for item " << i + 1 << ":\n";
			cout  << "Name: ";
			cin >> item[i].item_name;
			cout  << "Quantity Sold: ";
			cin >> item[i].amount;
			cout  << "Price: ";
			cin >> item[i].price;
			cout << endl;
		}
	
		cout << "----------------------------------------------------" << endl;
		cout << "                   SALES REPORT                     " << endl;
		cout << "----------------------------------------------------" << endl;
		cout << "Item         Quantity   Price     Total Sales       " << endl;
		cout << "----------------------------------------------------" << endl;
	
		for (int i = 0; i < x; i++) {
			Item item[i];
			total = item[i].price * item[i].amount;
			GrandTotal += total;
			cout << item[i].item_name << "\t" << "\t" << item[i].amount << "\t" << item[i].price << "\t" << "       " << total << endl;
		}
		
		
		cout << "----------------------------------------------------" << endl;
		cout << "Grand Total Sales: " << GrandTotal;
		
	} else if (x > 10) {
		cout << "Too many items!";
	}
	return 0;
}




