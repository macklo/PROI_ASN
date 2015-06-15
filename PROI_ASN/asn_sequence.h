/**
 * \file asn_sequence.h
 * \brief Deklaracja klasy reprezentującej sekwencje
 */

#ifndef ASN_SEQUENCE_H
#define ASN_SEQUENCE_H

#include "asn_object.h"
#include <vector>
/** \brief Klasa reprezentująca sekwencje
 */
class asn_sequence: public asn_object
{
protected:
	std::vector <asn_object*> elements; //!<Wektor zawierający elementy z sekwencji
public:
	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	int getSize();
	bool addElement(asn_object* obj); //!<Dodaje element do wektora @param obj Wsaźnik na obiekt (typu asn_object) do dodania
	asn_sequence(void);
	~asn_sequence(void);
};

#endif