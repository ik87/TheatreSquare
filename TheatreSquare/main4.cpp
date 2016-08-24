#include <iostream>
using namespace std;

int main()
{
	long long n, x, y, i, j, min, sum, current;
	n = 8, x = 1, y = 1;
	i = 0;
	j = 0;
	min = 1 << ((sizeof(n) * 8)) ;
	sum = 1;
	current = 1;
	while (true) 
	{
		sum = ++i; // a..

		while (true)
		{
			j++; // a.. * 2
			sum = sum << sum;
			if (sum == n) {
				current = (i * x) + (j * y);
				if (min > current)
					min = current;
			}

			
			
		}
		
	}


	return 0;
}