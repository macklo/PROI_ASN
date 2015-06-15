#include "asn_sequence.h"
#include "asn_int.h"
#include "asn_string.h"

int asn_sequence::readAll(std::istream& istr){
	if(!checkTag(istr))
		return -1;
	if(!readSize(istr))
		return -1;
	int readOctets = 2;
	int charleft = size;
	if(elements.empty()){
		while (charleft > 0){
			int tmptag = read(istr), x;
			if (tmptag < 0) {
				istr.clear();
				istr.seekg(0);
				writeable = 0;
				return -1;
			}
			istr.unget();
			istr.unget();
			if(tmptag==2){
				asn_int *tmpi = new asn_int;
				x = tmpi->readAll(istr);
				if(x <0) return -1;
				charleft = charleft-x;
				readOctets += x;
				addElement(tmpi);
			}
			else if(tmptag==19){
				asn_string *tmps = new asn_string;
				x = tmps->readAll(istr);
				if(x <0) return -1;
				charleft = charleft-x;
				readOctets += x;
				addElement(tmps);
			}
			else if(tmptag==48){
				asn_sequence *tmpss = new asn_sequence;
				x = tmpss->readAll(istr);
				if(x <0) return -1;
				charleft =charleft-x;
				readOctets += x;
				addElement(tmpss);
			}
			else{
				istr.clear();
				istr.seekg(0);
				writeable = 0;
				return -1;
			}
		}
		writeable = 1;
		return readOctets;
	}
	else{
		for (std::vector<asn_object*>::iterator it = elements.begin() ; it != elements.end(); ++it){
			int x = (*it)->readAll(istr);
			if (x<0){
				istr.clear();
				istr.seekg(0);
				/*
				for(int i = 0; i<readOctets; i++){
					istr.unget();
					istr.unget();
				}*/
				return -1;
			}
			readOctets += x;
		}
		writeable = 1;
		return readOctets;
	}
}

bool asn_sequence::writeAll(std::ostream& ostr){
	if(writeable){
		ostr<<int2hex(tag)<<int2hex(getSize());
		for (std::vector<asn_object*>::iterator it = elements.begin() ; it != elements.end(); ++it){
			(*it)->writeAll(ostr);
		}
		return true;
	}
	else return 0;
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
	writeable = 0;
}


asn_sequence::~asn_sequence(void)
{
}
