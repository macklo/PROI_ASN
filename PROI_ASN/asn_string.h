#ifndef ASN_STRING_H
#define ASN_STRING_H

#include "asn_object.h"
#include <string>

class asn_string : public asn_object
{
private:
	std::string value;

public:
	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	int getSize();
	asn_string(void);
	asn_string(std::string str);
	~asn_string(void);
};

#endif