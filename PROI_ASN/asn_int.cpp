#include "asn_int.h"
/*
int power(int x, int w){
	int wyn = 1;
	for (int i = 0; i<2;i++){
		wyn = wyn*x;
	}
	return wyn;
}*/

void asn_int::setValue(int x){
	value = x;
}

int asn_int::getValue(){
	return value;
}

asn_int::asn_int(void)
{
	tag = 2;
	value = 0;
}

bool asn_int::readContent(std::istream& istr){
	for (int i = 2*size-2; i>=0; i=i-2){
		int x = read(istr);
		int m =1;
		for (int j = 0; j<i;j++){
			m= m*16;
		}

		value = + x*m;
	}
	return true;
}

bool asn_int::readAll(std::istream& istr){
	if(!checkTag(istr))
		return false;
	readSize(istr);
	readContent(istr);
	return true;
}

asn_int::~asn_int(void)
{
}

