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

int asn_string::readAll(std::istream& istr){
	if(!checkTag(istr))
		return -1;
	if(!readSize(istr))
		return -1;
	int readOctets = 2;

	for (int i = 0; i<size; i++){
		char x = read(istr);
		if (x<0){
			for(int i = 0; i<readOctets; i++){
				istr.unget();
				istr.unget();
			}
			return -1;
		}
		readOctets++;
		value = value + x;
	}
	return readOctets;
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
