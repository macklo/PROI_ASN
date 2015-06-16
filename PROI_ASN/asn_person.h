/**
 * \file asn_sequence.h
 * \brief Deklaracja klasy reprezentuj�cej osob�
 */
#include "asn_sequence.h"
#include "asn_int.h"
#include "asn_object.h"
#include "asn_string.h"
/** \brief Klasa reprezentuj�ca osob�
 */
class asn_person : public asn_sequence
{
private:
	asn_string imie; //!<Imi� osoby
	asn_string nazwisko; //!<Nazwisko osoby
	asn_int wiek; //!<Wiek osoby
	asn_sequence friends; //!<Lista przyjaci� osoby
public:
	asn_person(void);
	~asn_person(void);
};

