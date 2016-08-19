#include <iostream>
#include <cmath>
#include <string>

using std::string;

string multy(string a, string b);
string sum(string a);


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
		if(a.length() - i){
			buffer += '+';
				for(int n = 0; n < a.length() - i;n++)
					buffer += std::to_string(0);
					
			}
		for (int j = b.length(); j; j--, t++)
		{
			
mem =  ((a[i - 1] - '0') * (b[j - 1] - '0')) + mem / 10;
			if ((j - 1) == 0) {
				
				buffer += std::to_string(mem % 10);
			if(mem > 10)
				buffer += std::to_string(mem / 10);
				
			}
			else {		
				buffer += std::to_string(mem % 10);			
			}
			
		}

		mem = 0;

	}
	
	return buffer;
}

string sum(string a) {
	//571+0521+0005
	int x,y;
	string s;
	for(int i = 0; i < a.length(); i++){
		x = a[i] - '0';
		for(int j = i; j; j++){
			if(a[j] == '+'){
				
			}
		}
		}
		else
	}
	
}
