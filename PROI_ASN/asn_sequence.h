#ifndef ASN_SEQUENCE_H
#define ASN_SEQUENCE_H

#include "asn_object.h"
#include <vector>

class asn_sequence: public asn_object
{
protected:
	std::vector <asn_object*> elements;
public:
	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	int getSize();
	bool addElement(asn_object* obj);
	asn_object* getElement();
	asn_sequence(void);
	~asn_sequence(void);
};

#endif