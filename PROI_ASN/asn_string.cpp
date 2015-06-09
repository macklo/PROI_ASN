#include "asn_string.h"


asn_string::asn_string(void)
{
	tag = 19;
	//value = '\0';
}

asn_string::asn_string(std::string str)
{
	tag = 19;
	value = str;
}

bool asn_string::readAll(std::istream& istr){
	if(!checkTag(istr))
		return false;
	readSize(istr);
	for (int i = 0; i<size; i++){
		char x = read(istr);
		value = value + x;
	}
	return true;
}
bool asn_string::writeAll(std::ostream& ostr){
	ostr<<int2hex(tag)<<int2hex(getSize());
	for(int i = 0; i<value.size();i++){
		ostr<<int2hex(value[i]);
	}
	return true;
}

int asn_string::getSize(){
	size =  value.length();
	return size;
}

asn_string::~asn_string(void)
{
}
