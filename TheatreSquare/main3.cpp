#include <iostream>
using namespace std;

int main()
{
	unsigned int count;

	cin >> count;
	count = count < (sizeof(count) * 8) ? count : (sizeof(count) * 8) - 1;
	count = 1 << count;

	if (count > 1000000)
		cout << "TOO HARD" <<std::endl;
	else
		cout << count << endl;

	return 0;
}