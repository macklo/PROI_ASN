/**
 * \file asn_string.h
 * \brief Deklaracja klasy reprezentującej napisy
 */


#ifndef ASN_STRING_H
#define ASN_STRING_H

#include "asn_object.h"
#include "showable.h"
#include <string>
/** \brief Klasa reprezentująca napisy
 */
class asn_string : public asn_object, public showable
{
private:
	std::string value; //!<Zapisany napis

public:
	void setValue(std::string str); //!<Ustawianie nowej wartości @param str Napis do zapisania
	/**
	* \brief Zwraca string zapisany w obiekcie.
	* @return String zapisany w obiekcie
	*/
	std::string getString();
	void show();
	
	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	int getSize();
	asn_string(void);
	asn_string(std::string str); //!< Konstruktor deklarujący zawartość @param str Wartość do zapisania
	~asn_string(void);
};

#endif