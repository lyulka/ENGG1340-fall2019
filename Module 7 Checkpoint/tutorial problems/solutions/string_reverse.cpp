#include <iostream>
#include <string>

using namespace std;

/*
// iterative version
string reverse( string s )
{
	string r;
	r.clear();

	for (int i = 0; i < s.length(); ++i)
		r = s[i] + r;

	return r;
}
*/


// recursive versioln
string reverse( string s )
{
	if ( s.length() == 0)
		return s;
	else
		return s[s.length()-1] + reverse(s.substr(0,s.length()-1)); 
}



int main()
{
	string s;
	cout << "Please input a string: ";
	cin >> s;

	cout << "String in reverse = " << reverse(s) << endl;


	return 0;

}