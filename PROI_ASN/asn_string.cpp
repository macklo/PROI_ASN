#include "asn_string.h"


asn_string::asn_string(void)
{
	tag = 19;
	//value = '\0';
}

bool asn_string::readContent(std::istream& istr){
	for (int i = 0; i<size; i++){
		char x = read(istr);
		value = value + x;
	}
	return true;
}

bool asn_string::readAll(std::istream& istr){
	if(!checkTag(istr))
		return false;
	readSize(istr);
	readContent(istr);
	return true;
}

asn_string::~asn_string(void)
{
}
