// Example program
#include <iostream>
using namespace std;

int main() {
	long long n, m, a, i, j;
	cin >> n >> m >> a;
	//664 = 4 
	//n = 1, m = 2, a = 1;
	i = 1;
	j = 1;
	if (a == 1)
		cout << n * m;
	else {
		while (true) { // 12-
			if((n -= a) > 0) {
				i++;
				continue;
			} else if ((m -= a) > 0) {
				j++;
				continue;
			}
			else
				break;
		}
		cout << i * j;
	}

	return 0;
}
