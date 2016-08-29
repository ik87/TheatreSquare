//E. Generate a String, v1.1
#include <iostream>
using namespace std;

int testBit(unsigned long n);
int countN(unsigned long n);

int main(){
	unsigned long n,x,y, size;
	//n = 10; x = 99; y = 62;
	//n = 6; x = 5 ; y = 16;
	//n = 1; x = 10; y = 1;
	//n = 8, x = 4, y = 8;
	n = 57, x = 5289, y = 8444;

	//size = 
	int i = 0, j = 0, pX = 0, pY = 0;
	// 99+62+62+99+62 = 384
	//1010	101	10	1
	//10		 5		 2	 1
	//		cp+w+cp+cp+w
	//w+cp+cp+cp
	//w+w+w+cp;
	
	
	while(n){


		switch (testBit(n))
		{
			case 1: i++; n++; break;
			case -1: i++; n--; break;
		}


		if(n & 1 ){ // if 1
			i++; // 1
			n = n >> 1;
			n = n << 1;
		}
		else{
			//if (n % 2 == 0 && n != 1) {
				if ((pX = (n * x) ) >= (pY = (y * countN(n)))) { //4, 8
					j++;
					n = n >> 1;
				}
				else {
					i += n - (n >> 1);
					n = n >> 1;
				}
			//}

	}

	
 	cout << n << endl;
 	
	}
	
	cout << "i " << i << "; j " << j << endl;
	cout << (i * x) + (j * y) << endl;
	return 0;
}

int testBit(unsigned long n) {
	int bit = sizeof(n) * 8;
	
	for (size_t i = 2; i < bit; i++)
	{
		if ((n + 1) == 1 << i)
			return 1;
		if ((n - 1) == 1 << i)
			return -1;
	}
	return 0;
}
int countN(unsigned long n) {
	if (n == 4)
		return 2;
	int bit = (sizeof(n) * 8);
	for (size_t i = bit; i; i--)
	{
		if ( n & 1 << i)
			return i;
	}
}
