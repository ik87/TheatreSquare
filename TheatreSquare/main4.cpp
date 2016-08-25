//E. Generate a String, v3
#include <iostream>
using namespace std;

int main()
{
	unsigned long long n, x, y, i, p, j, min, sum, current;
	n = 8, x = 15; y = 10;// 1,2,4,8,7 //1,2,3,6,7
	i = 1;	// aa..				// 1,2,3,4,5,6,7
	j = 1;
	p = 1;	//aa..*2				//123487
	min = n *  x;			//13//3+2
	sum = 1;
	current = 1;
	while (true) 
	{

		while (p++)
		{
			i++;
			sum = (i<< j);
			if(n < sum && n > (p = (i-1 << j))){
				if((sum - n)  >  (n - p))//-,+
				{
					sum = --i << j;
					 i += (n - p);
					 sum += (n - p);
				}
					else 
				{
					sum -= (sum - n); 
					i += (sum - n);
				}
				
			}
			cout << "sum: " << sum << endl;
			cout << "i : " << i << endl;
			cout << "j : " << j << endl;
			cout << "min (c): " << min << endl;
			cin.get();
			if (sum == n) {
				current = (p * x) + (j * y);
				if (min > current)
					min = current;
					break;
			}
			
		}
		i = 1;
		j++;
	}


	return 0;
}