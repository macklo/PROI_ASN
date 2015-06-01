#include "asn_person.h"

asn_person::asn_person(void)
{
	//tag = 30;
	elements.push_back(&imie);
	elements.push_back(&nazwisko);
	elements.push_back(&wiek);
}


asn_person::~asn_person(void)
{
}
