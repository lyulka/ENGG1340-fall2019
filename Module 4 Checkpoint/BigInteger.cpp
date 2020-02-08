// BigInteger.cpp
// The implementation file of the class BigInteger

#include <iostream>
#include <string>
#include "BigInteger.h"
using namespace std;

// The member function to set the number of a BigInteger object given an input string value
void BigInteger::setNumber( string number ){
  if( number[0]=='-' ){
    sign='-';
    number = number.substr( 1 );
  }else{
    sign = '+';
  }
  length = number.length();
  int j = 0;
  for( int i=number.length()-1; i>=0; i-- ){
    value[j] = number[i]-'0';
    j++;
  }
}

// The member function to return the string representation of the BigInteger object
string BigInteger::getNumber() const{
  string s;
  s = s + (sign=='-'?"-":"");
  for( int i=length-1; i>=0; i-- )
    s = s + (char)(value[i]+'0');
  return s;
}

// Overload operator <<  for cout << BigInteger object
ostream& operator<<( ostream & cout, const BigInteger& b ){ 
    string s;
    // One line of code: Assign the string representation of b to s
    s = b.getNumber();
    // One line of code: cout the value of s
    cout << s;
    // One line of code: return cout
    return cout;
} 


// Overload operator >>  for cin >> BigInteger object
istream & operator>>( istream& cin, BigInteger& b ){
     string s;
     cin >> s;
     b.setNumber( s );
     return cin;
}



// A global function operator+() that overload the "+" operator for adding two BigInteger values.
BigInteger operator+( const BigInteger& a, const BigInteger& b ){
  BigInteger c;
  if( a.sign=='+' && b.sign=='+' ){
    c.sign = '+';
    int carry = 0;
    int i;
    for( i = 0 ; i<a.length || i<b.length; i++ ){
      c.value[i] = ( (i<a.length?a.value[i]:0) + (i<b.length?b.value[i]:0) + carry )%10;
      carry = ( (i<a.length?a.value[i]:0) + (i<b.length?b.value[i]:0) + carry )/10;
    }
    if( carry > 0 ){
      c.value[i] = carry;
      i++;
    }
    c.length = i;
    return c;
  }else if( a.sign=='-' && b.sign=='-' ){
    BigInteger a2 = a;
    a2.sign = '+';
    BigInteger b2 = b;
    b2.sign = '+';
    c = a2 + b2;
    c.sign = '-';
    return c;
  }else if( a.sign=='+' && b.sign=='-' ){
    int carry = 0;
    int i;
    for( i = 0 ; i<a.length || i<b.length; i++ ){
      //we first borrow 10 from the digit on the left and find the difference
      c.value[i] = ( (i<a.length?a.value[i]:0) + 10 - (i<b.length?b.value[i]:0) + carry )%10;
      //Since we have borrowed 10 from the digit on the left,
      //the carry is one less than the original carry
      carry = ( (i<a.length?a.value[i]:0) + 10 - (i<b.length?b.value[i]:0) + carry )/10 - 1;
    }
    c.sign = '+';
    c.length = i;
    while( c.value[c.length-1]==0 && c.length>0 ){
      c.length--;
    }
    c.length = c.length>0?c.length:1;
    if( carry == 0 ){
      return c;
    }else{
      //we have actually borrowed 1000...000 (totally i 0's), so minus it back
      BigInteger d;
      d.sign = '+';
      d.length = i+1;
      for( int j=0; j<i; j++ )
        d.value[j] = 0;
      d.value[i] = 1;
      c.sign = '-';
      c = d + c;
      c.sign = '-';
      return c;
    }
  }else{
    return b + a;
  }
}


