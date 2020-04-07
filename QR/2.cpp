#include<iostream>
#include<string>
using namespace std;
int main() {

	int tc;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++) {
		
		string s;
		cin >> s;
		cout << "Case #" << ti << ": ";
		int arr[101] = { 0 };
		for (int i = 0; i < s.length(); i++) {
			arr[i] = s[i] - '0';
		}

		for (int i = 0; i < s.length(); i++) {
			if (i == 0)
			{
				for (int j = 0; j < arr[i]; j++) {
					cout << "(";
				}
				cout << arr[i];
				continue;
			}
			
			if (arr[i - 1] > arr[i]) {  //)
				int jc = arr[i - 1] - arr[i];
				for (int j = 0; j < jc; j++) {
					cout << ")";
				}
			}
			else if (arr[i - 1] < arr[i]) {
				int jc = arr[i] - arr[i - 1];
				for (int j = 0; j < jc; j++) {
					cout << "(";
				}
			}
			cout << arr[i];
		}
		for (int j = 0; j < arr[s.length() - 1]; j++) {
			cout << ")";
		}
		cout << endl;
	
	}
	return 0;
}