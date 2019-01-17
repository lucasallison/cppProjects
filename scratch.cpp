#include <iostream> 
using namespace std;
	
const int n = 2, m = 2;
	
	bool idem (int stemmen[][n], int i1, int i2) {
		bool check1 = false, check2 = false;
		int totaal1 = 0, totaal2 = 0;

		for (int j = 0; j < n; j++) {
		if (stemmen[i1][j] == stemmen[i2][j]) {check1 = true;}
		totaal1 += stemmen[i1][j]; totaal2 += stemmen[i2][j];
		}

		if (totaal1 == totaal2 || totaal1 + 1 == totaal2 || totaal1 - 1 == totaal2) { check2 = true;}
	
	if (check1 && check2) return true; else return false;
	}	

int main () {
	bool iets = true;
	int A[m][n];
	A[0][0] = 1; A[0][1] = 2; 
	A[1][0] = 0; A[1][1] = 2;

	cout << idem (A, 0, 1) << iets;
	
return 0;
}
