#ifndef ASN_OBJECT_H
#define ASN_OBJECT_H

#include <iostream>

class asn_object
{
protected:
	int tag;
	int size;

	int hex2int(char c);
	int read(std::istream& istr);
	bool checkTag(std::istream& istr);
	bool readSize( std::istream& istr);
	
public:
	
	//virtual bool readContent( std::istream& istr) = 0;
	virtual bool readAll(std::istream& istr) = 0;
	asn_object(void);
	~asn_object(void);
};

#endif