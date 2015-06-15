/**
 * \file asn_string.h
 * \brief Deklaracja klasy reprezentuj�cej napisy
 */


#ifndef ASN_STRING_H
#define ASN_STRING_H

#include "asn_object.h"
#include <string>
/** \brief Klasa reprezentuj�ca napisy
 */
class asn_string : public asn_object
{
private:
	std::string value; //!<Zapisany napis

public:
	void setValue(std::string str); //!<Ustawianie nowej warto�ci @param str Napis do zapisania
	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	int getSize();
	asn_string(void);
	asn_string(std::string str); //!< Konstruktor deklaruj�cy zawarto�� @param str Warto�� do zapisania
	~asn_string(void);
};

#endif