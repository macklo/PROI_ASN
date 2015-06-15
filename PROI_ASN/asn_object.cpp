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
	if(!(istr>>c1)){
		//istr.unget();
		return -1;
	}
	if(!(istr>>c2)){
		//istr.unget();
		istr.unget();
		return -1;
	}
	if(!isxdigit(c1) || !isxdigit(c2)){
		istr.unget();
		istr.unget();
		return -1;
	}
	return hex2int(c1)*16 + hex2int(c2);
}

bool asn_object::checkTag(std::istream& istr){
	int rtag = read(istr);
	if( rtag < 0) return false;
	if(rtag != tag){
		istr.clear();
		istr.seekg(0);
		return false;
	}
	else
		return true;
}

bool asn_object::readSize(std::istream& istr){
	int rsize = read(istr);
	if( rsize < 0) {
		istr.clear();
		istr.seekg(0);
		return false;
	}
	if (rsize>127){
		/*
		for(int i = 0 ; i<4;i++)
			istr.unget();*/
		/*
		std::string tmp;
		istr>>tmp;
		std::cout<<tmp<<std::endl;
		*/
		istr.clear();
		istr.seekg(0, std::ios::beg);
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
