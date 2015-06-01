#include "asn_object.h"

int asn_object::hex2int(char c){
	if(isdigit(c))
		return c - '0';
	else
		return tolower(c) - 'a' + 10;
}

int asn_object::read(std::istream& istr){
	char c1, c2;
	istr>>c1>>c2;
	if(!isxdigit(c1) || !isxdigit(c2))
		return 1;
	return hex2int(c1)*16 + hex2int(c2);
}

bool asn_object::checkTag(std::istream& istr){
	int rtag = read(istr);
	if(rtag != tag){
		istr.unget();
		istr.unget();
		return false;
	}
	else
		return true;
}

bool asn_object::readSize(std::istream& istr){
	int rsize = read(istr);
	if (rsize>127)
		return false;
	size = rsize;
	return true;
}
/*
bool asn_object::readAll(std::istream& istr){
	if(!checkTag(istr))
		return false;
	readSize(istr);
	readContent(istr);
	return true;
}
*/
asn_object::asn_object(void)
{
}


asn_object::~asn_object(void)
{
}
