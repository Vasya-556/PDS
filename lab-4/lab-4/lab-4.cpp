#include <iostream>
#include <string>

using namespace std;

void task1();
void task2();
int factorial(int n);

int main()
{
	cout << "task1:" << endl;
	task1();
	cout << "task2:" << endl;
	task2();
}

void task1() {
	int n;
	cout << "Enter n: "; cin >> n;
	string lecs = "";

	for (int i = 1; i <= n; i++)
	{
		lecs += to_string(i);
	}
	cout << lecs << endl;

	for (int i = 1; i < factorial(n); i++)
	{
		int j = n - 1;
		while (lecs[j - 1] >= lecs[j]) {
			j--;
		}
		int k = n;
		while (lecs[k - 1] <= lecs[j - 1]) {
			k--;
		}

		int temp = lecs[j - 1];
		lecs[j - 1] = lecs[k - 1];
		lecs[k - 1] = temp;
		for (int i = j, k = n; i < k; i++, k--) {
			int temp = lecs[i];
			lecs[i] = lecs[k - 1];
			lecs[k - 1] = temp;
		}
		cout << lecs << endl;
	}
}

void task2() {
	int n;
	unsigned int r;
	cout << "Enter n: ";
	cin >> n;
	do
	{
		cout << "Enter r(r<=n): ";
		cin >> r;
	} while (r > n);

	int lecs[100];
	
	for (int i = 0; i < r; i++)
		lecs[i] = i;

	for (int i = 0; i < r; i++)
		cout << lecs[i];
	cout << endl;

	int l = factorial(n) / (factorial(r) * factorial(n-r));

	for (int k = 2; k <= l; k++) {
		int i = r - 1;
		while (i >= 0 && lecs[i] == n - r + i)
		{
			i--;
		}

		if (i < 0)
			break;

		lecs[i] ++;

		for (int j = i + 1; j < r; j++) {
			lecs[j] = lecs[j - 1] + 1;
		}

		for (int j = 0; j < r; j++) {
			cout << lecs[j];
		}
		cout << endl;
	}
}

int factorial(int n) {
	if (n > 1)
		return n * factorial(n - 1);
	else
		return 1;
}