#ifndef ASN_STRING_H
#define ASN_STRING_H

#include "asn_object.h"
#include <string>

class asn_string : public asn_object
{
private:
	std::string value;

public:
	bool readContent(std::istream& istr);
	bool readAll(std::istream& istr);
	asn_string(void);
	~asn_string(void);
};

#endif