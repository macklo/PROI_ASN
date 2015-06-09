#include "asn_sequence.h"

bool asn_sequence::readAll(std::istream& istr){
	if(!checkTag(istr))
		return false;
	readSize(istr);
	for (std::vector<asn_object*>::iterator it = elements.begin() ; it != elements.end(); ++it){
		(*it)->readAll(istr);
	}
	return true;
}

bool asn_sequence::writeAll(std::ostream& ostr){
	ostr<<int2hex(tag)<<int2hex(getSize());
	for (std::vector<asn_object*>::iterator it = elements.begin() ; it != elements.end(); ++it){
		(*it)->writeAll(ostr);
	}
	return true;
}

int asn_sequence::getSize(){
	int sum = 0;
	for (std::vector<asn_object*>::iterator it = elements.begin() ; it != elements.end(); ++it){
		sum = sum + (*it)->getSize()+2;
	}
	size = sum;
	return size;
}

bool asn_sequence::addElement(asn_object* obj){
	elements.push_back(obj);
	return true;
}

asn_sequence::asn_sequence(void)
{
	tag = 48;
}


asn_sequence::~asn_sequence(void)
{
}
