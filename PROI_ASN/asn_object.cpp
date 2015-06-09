#include "asn_object.h"

int asn_object::hex2int(char c){
	if(isdigit(c))
		return c - '0';
	else
		return tolower(c) - 'a' + 10;
}

std::string asn_object::int2hex(int n){
	std::stringstream ss;
	ss<< std::hex << n;
	std::string tmp= ss.str();
	if(tmp.size() % 2) tmp = '0' + tmp;
	for(int i =0; i<tmp.size(); i++){
		char(c) = tmp[i];
		if(isalpha(c))
			tmp[i] =  toupper(c);
	}
	return ( tmp );
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
	if (rsize>127){
		for(int i = 0 ; i<4;i++)
		istr.unget();
		return false;
	}
	size = rsize;
	return true;
}


asn_object::asn_object(void)
{
}


asn_object::~asn_object(void)
{
}
