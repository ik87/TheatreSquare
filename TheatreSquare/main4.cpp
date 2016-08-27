//E. Generate a String, v4
#include <iostream>
using namespace std;
#define DEBUG() \
	std::cout << "n: " << n << std::endl; \
	std::cout << "sum: " << sum << std::endl; \
	std::cout << "i : " << i << std::endl; \
	std::cout << "j : " << j << std::endl; \
	std::cout << "min (c): " << min << std::endl; \
	std::cout << ((i * x) + (j * y)); \
	std::printf(" = (i*x) + (j*y)\n" ); \
	std::cin.get();

int main()
{
	unsigned long long n, x, y, i, p, j, min, sum, current;
	n = 9; x = 1; y = 3;// xx=2,y=4,y=8,x
	i = 1;	// aa..				// 1,2,3,4,5,6,7
	j = 1;	//aa..*2				//123487
	min = n *  x;			//13//3+2
	sum = 1;
	current = 1;
	while (true) 
	{

		while (true)
		{
			i++;
			sum = (i<< j);
			if(i == 1 && sum > n) {
				cout << min << endl;
				return 0;
			}
			if(n < sum && n > (p = (i-1 << j))){
			cout << "n < sum && n > p" << endl;
			cout << n << " < " << sum << " && ";
			cout << n << " > " << p << endl;
			if(((sum - n) + i )  <  ((n - p) + (i - 1)))//-,+
				{
					i += (sum - n);
				}
					else
				{
					cout << "*";
					 i += (n - p);
					 i--;
				}
				
				sum = n;
				
			}
		DEBUG();
			if (sum == n) {
				current = (i * x) + (j * y);
				if (min > current)
					min = current;
					cout << "#"<< endl;
		DEBUG();
					break;
			}
			
		}
		i = 0;
		j++;
	}


	return 0;
}