#ifndef ASN_SEQUENCE_H
#define ASN_SEQUENCE_H

#include "asn_object.h"
#include <vector>

class asn_sequence: public asn_object
{
protected:
	std::vector <asn_object*> elements;
public:
	bool readContent(std::istream& istr);
	bool readAll(std::istream& istr);
	asn_sequence(void);
	~asn_sequence(void);
};

#endif