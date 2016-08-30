//E. Generate a String, v1.4
#include <iostream>
#include <string>
using namespace std;

class Branch {
public:
	unsigned long long n, x, y;
	int i;
	int j;
	string patch;
	Branch(unsigned long long n, unsigned long long x, unsigned long long y) {
		this->n = n;
		this->i = 0;
		this->j = 0;
		this->x = x;
		this->y = y;
		this->patch.append(to_string(n));
	}
	Branch(Branch *br)
	{
		this->n = br->n;
		this->i = br->i;
		this->j = br->j;
		this->x = br->x;
		this->y = br->y;
		this->patch = br->patch;


	}
	~Branch() {}

	unsigned long long getN() { return n; }

	Branch plusN() { n++; i++;  return this; }
	Branch minusN() { n--; i++; return this; }
	Branch minusEND() { i += (int)n - 1; n = 1; return this; }
	Branch halfN() { n = n >> 1; j++;   return this; }
	unsigned long long getTotalSec() { return ((i*x) + (j*y)); }
	bool yLanger() { return y > x;  }
	void upPatch() { patch.append(" ");  patch.append(to_string(n)); }

};



void factory(Branch br, unsigned long long &min, unsigned long long &sum) {
	br.upPatch();

	if (br.getN() == 1) {
		br.minusN();
		//br.minusN();
		if (min > br.getTotalSec())
			min = br.getTotalSec();
		sum++;
		cout << br.patch << "\t" <<br.getTotalSec() << endl;
		cout << " i "<< br.i << " j: " << br.j << endl;

		return;
	}

	if (br.getN() & 1) {
		Branch brL(br);
		Branch brR(br);
		factory(brR.plusN(), min, sum);
		factory(brL.minusN(), min, sum);


	}
	else {
		if (br.n > (br.y/br.x)*2 )
			factory(br.halfN(), min, sum);
		else
			factory(br.minusEND(), min, sum);
		
	}

}

int main() {
	unsigned long long n, x, y, sum;
	//n = 10; x = 99; y = 62;
	sum = 0;
	//n = 6; x = 5 ; y = 16;
	//n = 1; x = 10; y = 1;
	//n = 8, x = 4, y = 8;
	//n = 57, x = 5289, y = 8444; //excpected 2519291691
	//cin >> n >> x >> y;
	//n = 9; x = 1; y = 10;
	n = 382; x = 81437847; y = 324871127;
	//n = 244; x = 575154303; y = 436759189;

	unsigned long long min = 0;
	min--;
	Branch br(n, x, y);
	factory(br, min, sum);
	cout << min << endl;
	cout << sum << endl;
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
		