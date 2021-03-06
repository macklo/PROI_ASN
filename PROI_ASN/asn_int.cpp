#include "asn_int.h"

void asn_int::setValue(int x){
	value = x;
	writeable = 1;
}

int asn_int::getValue(){
	if(writeable) return value;
	else return -1;
}

int asn_int::getSize(){
	std::string tmp = int2hex(value);
	size = tmp.size() / 2;
	return size;
}

double asn_int::invert(){
	if (writeable && value != 0) return 1/value;
	else return 0;
	
}

void asn_int::show(){
	if (writeable) std::cout<<"Obiekt int, wartosc:"<<value<<std::endl;
	else std::cout<<"Obiekt int, obiekt jest pusty"<<std::endl;
}

asn_int::asn_int(void)
{
	tag = 2;
	value = 0;
	writeable = 0;
}

asn_int::asn_int(int x)
{
	tag = 2;
	value = x;
	writeable = 1;
}

int asn_int::readAll(std::istream& istr){
	if(!checkTag(istr))
		return -1;
	if(!readSize(istr))
		return -1;
	int readOctets = 2;
	for (int i = 2*size-2; i>=0; i=i-2){
		int x = read(istr);
		if (x<0){
			writeable = 0;
			istr.clear();
			istr.seekg(0);
			/*
			for(int i = 0; i<readOctets; i++){
				istr.unget();
				istr.unget();
			}*/

			return -1;
		}
		readOctets++;
		int m =1;
		for (int j = 0; j<i;j++){
			m= m*16;
		}
		writeable = 1;
		value = + x*m;
	}
	return readOctets;
}

bool asn_int::writeAll(std::ostream& ostr){
	if(writeable){
		ostr<<int2hex(tag)<<int2hex(getSize())<<int2hex(value);
		return true;
	}
	else return false;
}

asn_int::~asn_int(void)
{
}

