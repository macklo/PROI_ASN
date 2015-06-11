#ifndef ASN_OBJECT_H
#define ASN_OBJECT_H

#include <iostream>
#include <string>
#include <sstream>

class asn_object
{
protected:
	int tag;
	int size;

	int hex2int(char c);
	std::string int2hex(int n);
	int read(std::istream& istr);
	bool checkTag(std::istream& istr);
	bool readSize( std::istream& istr);
public:
	virtual int readAll(std::istream& istr) = 0;
	virtual bool writeAll(std::ostream& ostr) = 0;
	virtual int getSize() = 0;
	asn_object(void);
	~asn_object(void);
};

#endif