#include "asn_sequence.h"
#include "asn_int.h"
#include "asn_object.h"
#include "asn_string.h"

class asn_person : public asn_sequence
{
private:
	asn_string imie;
	asn_string nazwisko;
	asn_int wiek;
public:
	asn_person(void);
	~asn_person(void);
};

