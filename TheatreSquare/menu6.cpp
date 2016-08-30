//E. Generate a String, v1.3
#include <iostream>
//#include <string>
using namespace std;

class Branch {
private:
	int i;
	int j;
	unsigned long n, x, y;


public:
//	string patch;
	Branch(unsigned long n, unsigned long x, unsigned long y) {
		this->n = n;
		this->i = 0;
		this->j = 0;
		this->x = x;
		this->y = y;
	//	this->patch = std::to_string(n);
	}
	Branch(Branch *br)
	{
		this->n = br->n;
		this->i = br->i;
		this->j = br->j;
		this->x = br->x;
		this->y = br->y;


	}
	~Branch() {}

	unsigned long getN() { return n; }

	Branch plusN() { n++; i++;  return this; }
	Branch minusN() { n--; i++; return this; }
	Branch halfN() { n = n >> 1; j++;   return this; }
//	void addPatch() { patch += to_string(int(n)); }
	unsigned long getTotalSec() { return ((i*x) + (j*y)); }
	bool yLanger() {return (y > x);}

};



void factory(Branch br, unsigned long &min) {
	

	if (br.getN() == 1) {
		br.minusN();
		//br.minusN();
		if (min > br.getTotalSec())
			min = br.getTotalSec();
		
		return;
	}
	if (br.getN() & 1) {
		Branch brL(br);
		Branch brR(br);
		factory(brR.plusN(), min);
		factory(brL.minusN(), min);


	}
	else {
		if(br.getN() == 2 && br.yLanger())
			factory(br.minusN(), min);
		else
			factory(br.halfN(), min);
	}
}

int main() {
	unsigned long n, x, y;
	//n = 10; x = 99; y = 62;
	//n = 6; x = 5 ; y = 16;
	//n = 1; x = 10; y = 1;
	//n = 8, x = 4, y = 8;
	n = 57, x = 5289, y = 8444;
	//n = 8; x = 1; y = 1;
	unsigned long min = 0;
	min--;
	Branch br(n, x, y);
	factory(br, min);
	cout << min << endl;
	return 0;
}
/*9 = 8+1 4 2 1
9 = 10-1 5-1 4 2 1
		 /---------57--------------\
	  (56+1)			   /----- (58-1)-------------------------\	
	    14		 |		  /										  \
	    /\ 		 |	    (28+1)							/---------(30-1)---------\
	   /  \		 |		  14		|		 /---------(14+1)-------\		|	(16-1)
  (6+1)	  (8-1)	 |		/	  \		|	 /--(6+1)-\			|	  (8-1)		|		8
2+1	|4-1|	4	 |	  (6+1)	  (8-1)	|	(2+1)    (4-1)		|		4		|		4
1	|2	|	2	 |	   /\	 |	4	|	  1	 |  	2		|		2		|		2
	|1	|	1	 |(2+1) (4-1)|	2	|		 |  	1		|		1		|		1
				 |	1  |  2
					   |  1
*/				
		