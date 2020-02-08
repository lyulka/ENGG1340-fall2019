#ifndef BIGINTEGER_H
#define BIGINTEGER_H
// BigInteger.h
// The definition file of the class BigInteger
#include <string>
using namespace std;

class BigInteger{
   public:
      void setNumber( string );
      string getNumber() const;
   private:
      char sign;
      int length;
      int value[100];
      

friend BigInteger operator+( const BigInteger & a, const BigInteger & b );
friend ostream& operator<<( ostream& cout, const BigInteger & b );
friend istream & operator>>( istream& cin, BigInteger& b );
};

BigInteger operator+( const BigInteger & a, const BigInteger & b );
ostream& operator<<( ostream& cout, const BigInteger & b );
istream & operator>>( istream& cin, BigInteger& b );

#endif

