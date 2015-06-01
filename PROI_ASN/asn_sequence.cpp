#include "asn_sequence.h"

bool asn_sequence::readContent(std::istream& istr){
	for (std::vector<asn_object*>::iterator it = elements.begin() ; it != elements.end(); ++it){
		(*it)->readAll(istr);
	}
	return true;
}

bool asn_sequence::readAll(std::istream& istr){
	if(!checkTag(istr))
		return false;
	//checkTag(istr);
	readSize(istr);
	std::cout<<size;
	readContent(istr);
	return true;
}

asn_sequence::asn_sequence(void)
{
	tag = 48;
}


asn_sequence::~asn_sequence(void)
{
}
