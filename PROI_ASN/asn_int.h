#ifndef ASN_INT_H
#define ASN_INT_H

#include "asn_object.h"
#include <iostream>
#include <cmath>

class asn_int : public asn_object
{
protected:
	
private:
	int value;
public:
	void setValue(int x);
	int getValue();
	int getSize();

	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	asn_int(void);
	~asn_int(void);
};

#endif