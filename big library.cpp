#include <iostream>
#include "lip.h"
#include <string>
#include <stdlib.h>

using namespace std;

class bigint{
	public:
//******************************************************************************
	verylong number;
	verylong value;
	verylong result;

//******************************************************************************	

	verylong operator+(long value){
		verylong result = 0;
		zsadd(number, value, &result); // result = number + value
		return result;
	}
	
//******************************************************************************

	verylong operator-(verylong value){
		verylong result = 0;
		zsub(number, value, &result); // result = number - value
		return result;
	}

//******************************************************************************

	verylong operator*(long value){
		verylong result = 0;
		zsmul(number, value, &result); // result = number * value
		return result;		
	}
	
//******************************************************************************

	verylong operator/(long value){
		verylong result = 0;
		zsdiv(number, value, &result); // result = number / value
		return result;	
	}
	
//******************************************************************************

	verylong operator^(verylong value){
		zsq(value, &result); // number = number ^ 2
		return number;		
	}

//******************************************************************************

	verylong operator%(verylong value){
		verylong result = 0;
		zmod(number, value, &result); // result = number % value
		return result;		
	}

//******************************************************************************

	bigint(long n){
		number=0;
		char buffer[256];
		lltoa(n, buffer, 10);
		//s=a_toito_string(n);
		zsread(buffer,&number);
	}
	bigint(char *s){
	//	char
	number=0;
		zsread(s,&number);
	}
	bigint& operator= (bigint const& );

//******************************************************************************

	~bigint(){
	zfree(&number);
	zfree(&value);
	zfree(&result);
	}

};

int main(int argc, char** argv) {

	bigint s = 10;
	bigint a = 11;
	bigint res = a+s;

	return 0;
}
