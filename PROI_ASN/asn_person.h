/**
 * \file asn_sequence.h
 * \brief Deklaracja klasy reprezentuj¹cej osobê
 */
#include "asn_sequence.h"
#include "asn_int.h"
#include "asn_object.h"
#include "asn_string.h"
/** \brief Klasa reprezentuj¹ca osobê
 */
class asn_person : public asn_sequence
{
private:
	asn_string imie; //!<Imiê osoby
	asn_string nazwisko; //!<Nazwisko osoby
	asn_int wiek; //!<<Wiek osoby
	asn_sequence friends; //!Lista przyjació³ osoby
public:
	asn_person(void);
	~asn_person(void);
};

