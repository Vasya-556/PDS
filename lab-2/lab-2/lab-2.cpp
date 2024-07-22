#include <iostream>
#include <string>

using namespace std;

void table() {
	cout << "=============" << endl;
	cout << "|p|q|r|func |" << endl;
	for (int p = 0; p < 2; p++)
		for (int q = 0; q < 2; q++)
			for (int r = 0; r < 2; r++) {
				cout << "-------------" << endl;
				cout << "|" << p << "|" << q << "|" << r << "|" << ((!(p && q) || (p && r)) && (!(p && r) || (p && q))) << "    |" << endl;
			}
	cout << "=============" << endl;
}

int main()
{
	table();
}