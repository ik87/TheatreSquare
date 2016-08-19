#include <iostream>
#include <cmath>
#include <string>

using std::string;

string Calc(double n, double m, unsigned  int a);
string multy(string a, string b);
string sum(string a);
string convertRevers(string a);


int main(int argc, char* argv[])
{
	unsigned int _a;
	double _n;
	double _m;

	std::cin >> _n >> _m >> _a;
	std::cout << Calc(_n, _m, _a);
	return 0;


}

string multy(string a, string b) {

	string buffer = "";
	int mem = 0;
	int t = 0;


	for (int i = a.length(); i; i--)
	{
		if (a.length() - i) {
			buffer += '+';
			for (int n = 0; n < (a.length() - i); n++)
				buffer += std::to_string(0);
		}
		for (int j = b.length(); j; j--, t++)
		{

			mem = ((a[i - 1] - '0') * (b[j - 1] - '0')) + mem / 10;
			if ((j - 1) == 0) {

				buffer += std::to_string(mem % 10);
				if (mem > 10)
					buffer += std::to_string(mem / 10);

			}
			else {
				buffer += std::to_string(mem % 10);
			}

		}

		mem = 0;

	}


	return sum(buffer);
}

string sum(string a) {

	int x = 0;
	int	y = 0;
	int  buffer = 0;
	string s = "";
	int j = 1;

	bool on = false;
	for (int i = 0; j < a.length() - 1; i++) {
		if (a[i] != '+')
			x = a[i] - '0'; //5,7,1
		else
			x = 0; // 0

		while (j) {
			j++;
			if (a[j] == '+' && on == false) {
				on = true;
				j++;
			}
			if (a[j] == '+' && on == true) {
				s += a.substr(j);
				a = s;
				i = -1;
				j = 1;
				s = "";
				x = y = 0;
				buffer = 0;
				on = false;
				break;
			}
			if (on) {
				y = a[j] - '0'; //0,5,2,1
				buffer = x + y + (buffer / 10); //5,12,4,1
				s += std::to_string(buffer % 10); //5,2,4,1
				break;
			}


		}
	}


	return convertRevers(s);

	//return s;
}

string Calc(double n, double m, unsigned  int a) {
	unsigned int x, y;
	if (a == 1 && n > 1 && m > 1) {
		return multy(std::to_string((int)n), std::to_string((int)m));
	}
	if (n <= a && m <= a)
		return "1";
	if (n > a)
		x = ceil(n / a);
	else {
		x = 1;
	}
	if (m > a)
		y = ceil(m / a);
	else {
		y = 1;
	}

	if (n <= a)
		x = 0;
	if (m <= a)
		y = 0;
	return std::to_string(x + y);
}

string convertRevers(string a)
{
	string str = "";


	for (int i = a.length(); i; i--)
	{
		str += a[i - 1];
	}
	return str;
}