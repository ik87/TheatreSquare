#include <iostream>
#include <cmath>
#include <string>

using std::string;

string multy(string a, string b);
//string sum(string a, string b, int i);


int main(unsigned  int argc, char* argv[])
{
	char a[100] = "257";//175 + 125 + 50
	char b[100] = "25"; 
	//175 + 1250 + 5000 = 6425
	string t = multy(a,b);

	std::cout << t  << std::endl;

	return 0;
}

string multy(string a, string b) {

	string buffer = "";
	int mem = 0;
	int t = 0;

	
	for (int i = a.length(); i ; i--)
	{
		for (int j = b.length(); j; j--, t++)
		{
			if(a.length()){
				for(int n = 0; n < i;n++)
					buffer += std::to_string(0);
			}
mem =  ((a[i - 1] - '0') * (b[j - 1] - '0')) + mem / 10;
			if ((j - 1) == 0) {
				
				buffer += std::to_string(mem % 10);
			if(mem > 10)
				buffer += std::to_string(mem / 10);
				buffer += '+';
			}
			else {		
				buffer += std::to_string(mem % 10);			
			}
			
		}

		mem = 0;

	}
	
	return buffer;
}
/*
string sum(string a, string b, int i) {
	string equal;
	equal +
	
}
*/