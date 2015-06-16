/**
 * \file asn_sequence.h
 * \brief Deklaracja klasy reprezentuj¹cej sekwencje
 */

#ifndef ASN_SEQUENCE_H
#define ASN_SEQUENCE_H

#include "asn_object.h"
#include "showable.h"
#include <vector>
/** \brief Klasa reprezentuj¹ca sekwencje - zbiór obiektów typu asn_object
 *
 */
class asn_sequence: public asn_object
{
protected:
	std::vector <asn_object*> elements; //!<Wektor zawieraj¹cy elementy z sekwencji
public:
	/**
	* \brief Odczytuje elementy z wejœciowego strumienia. Gdy lista elementów 
	* jest pusta odczytuje on atomatycznie tzn. tworzy nowe obiekty 
	* i dodaje je do listy, a w przeciwnym przypadku wywo³uje funkcje
	* readAll() kolejnych elementów z listy.
	@param istr Strumieñ wejœciowy
	*/
	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	int getSize();
	/**
	* \brief Dodaje element do wektora. Nale¿y zwróciæ uwagê na 
	* kolejnoœæ dodawanych elementów.
	* @param obj WsaŸnik na obiekt (typu asn_object) do dodania
	*/
	bool addElement(asn_object* obj); 
	asn_sequence(void);
	~asn_sequence(void);
};

#endif