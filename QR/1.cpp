#include<iostream>

using namespace std;
int main() {

	int tc;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++) {
		int n;
		int arr[101][101] = { 0 }; 
		cin >> n;

		int k = 0;
		int r = 0;
		for (int i = 0; i < n; i++){
			int check[101] = { 0 }; 
			bool block = false;
			for (int j = 0; j < n; j++) {
				
				cin >> arr[i][j];
				if (i == j) {
					k += arr[i][j];
				}

				if (check[arr[i][j]] == 0 && !block) {
					check[arr[i][j]] = 1;
				}
				else if(check[arr[i][j]] == 1 && !block) {
					block = true;
					r++;
				}
			}
		}

		int c = 0;
		for (int i = 0; i < n; i++) {
			int check[101] = { 0 };
			bool block = false;
			for (int j = 0; j < n; j++) {
				if (check[arr[j][i]] == 0 && !block) {
					check[arr[j][i]] = 1;
				}
				else if (check[arr[j][i]] == 1 && !block) {
					block = true;
					c++;
				}
			}
		}

		cout <<"Case #"<<ti<<": "<< k<<" "<<r<<" "<<c<<endl;

	
	}
	return 0;
}