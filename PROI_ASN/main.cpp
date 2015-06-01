#include <iostream>
#include <cstdint>
#include <string>
#include <sstream>
#include "asn_int.h"
#include "asn_string.h"
#include "asn_person.h"

int main(){
	asn_int x;
	asn_string s;
	asn_person p;
	x.setValue(5);
	std::stringstream ss;
	//ss<<"300a301713aaaaaaaaaaaa1304aaaaaaaa020113";
	//ss<<"020113";
	//ss<<"13064D616369656A";
	//ss<<"13044B6C6F73";
	ss<<"301113064D616369656A13044B6C6F73020113";
	p.readAll(ss);
	int a = 0x0F;
	//std::cout<<x.getValue()<<std::endl;
	std::system("pause");
	return 0;
}