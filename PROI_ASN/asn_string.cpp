#include "asn_string.h"


asn_string::asn_string(void)
{
	tag = 19;
	writeable = 0;
	//value = '\0';
}

asn_string::asn_string(std::string str)
{
	tag = 19;
	value = str;
	writeable = 1;
}

void asn_string::setValue(std::string str){
	value = str;
	writeable = 1;
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
			istr.clear();
			istr.seekg(0);
			writeable = 0;
			/*
			for(int i = 0; i<readOctets; i++){
				istr.unget();
				istr.unget();
			}*/
			return -1;
		}
		readOctets++;
		writeable = 1;
		value = value + x;
	}
	return readOctets;
}
bool asn_string::writeAll(std::ostream& ostr){
	if(writeable){
		ostr<<int2hex(tag)<<int2hex(getSize());
		for(int i = 0; i<value.size();i++){
			ostr<<int2hex(value[i]);
		}
		return true;
	}
	else return 0;
}

int asn_string::getSize(){
	size =  value.length();
	return size;
}

asn_string::~asn_string(void)
{
}
