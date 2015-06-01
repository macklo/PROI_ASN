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
	bool readContent(std::istream& istr);
	void setValue(int x);
	int getValue();
	bool readAll(std::istream& istr);
	asn_int(void);
	~asn_int(void);
};

#endif