//E. Generate a String, v1.0
#include <iostream>
using namespace std;

int main(){
	unsigned long n,x,y;
	n = 7; x = 99; y = 62;
//n = 6; x = 5 ; y = 16;

	bool xBig = x > y;
	int i = 0, j = 0;
	// 99+62+62+99+62 = 384
	//1010	101	10	1
	//10		 5		 2	 1
	//		cp+w+cp+cp+w
	//w+cp+cp+cp
	//w+w+w+cp;
	
	
	while(n){
	
		if(n & 1 ){ // if 1
			i++; // 1
			n = n >> 1;
			n = n << 1;
		}
	else{
		j++;
		n = n >> 1;
	}

	
 	cout << n << endl;
 	
	}
	
	cout << "i " << i << "; j " << j << endl;
	return 0;
}