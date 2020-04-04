#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class schedule {
public:
	int idx;
	int start;
	int end;
	int assign;
	schedule(int _i, int _s, int _e, int _a) :idx(_i), start(_s), end(_e), assign(_a) {}
};

bool startCompare(schedule a, schedule b) {
	return a.start < b.start;
}
bool idxCompare(schedule a, schedule b) {
	return a.idx < b.idx;
}
int main() {

	int tc;
	cin >> tc;
	for (int ti = 1; ti <= tc; ti++) {
		int n;
		cin >> n;
		vector<schedule> arr;
		int last[2] = { 0, };
		
		for (int i = 0; i < n; i++) {
			int start, end;
			cin >> start;
			cin >> end;
			arr.push_back(schedule(i, start, end, -1));
		}
		
		sort(arr.begin(), arr.end(), startCompare);
		bool impossible = false; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 2; j++) {
				if (arr[i].start >= last[j]) {
					last[j] = arr[i].end;
					arr[i].assign = j;
					break;
				}
			}
			if (arr[i].assign < 0) {
				impossible = true;
				break;
			}
		}

		sort(arr.begin(), arr.end(), idxCompare);

		cout << "Case #" << ti << ": ";
		if(!impossible){
			for (int i = 0; i < n; i++) {
				if (arr[i].assign == 0) {
					cout << "C";
				}
				else {
					cout << "J";
				}
			}
		}
		else {
			cout << "IMPOSSIBLE";
		}
		cout << endl;
		
	
	}
	return 0;
}