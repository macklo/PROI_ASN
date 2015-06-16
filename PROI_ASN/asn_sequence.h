/**
 * \file asn_sequence.h
 * \brief Deklaracja klasy reprezentuj�cej sekwencje
 */

#ifndef ASN_SEQUENCE_H
#define ASN_SEQUENCE_H

#include "asn_object.h"
#include "showable.h"
#include <vector>
/** \brief Klasa reprezentuj�ca sekwencje - zbi�r obiekt�w typu asn_object
 *
 */
class asn_sequence: public asn_object
{
protected:
	std::vector <asn_object*> elements; //!<Wektor zawieraj�cy elementy z sekwencji
public:
	/**
	* \brief Odczytuje elementy z wej�ciowego strumienia. Gdy lista element�w 
	* jest pusta odczytuje on atomatycznie tzn. tworzy nowe obiekty 
	* i dodaje je do listy, a w przeciwnym przypadku wywo�uje funkcje
	* readAll() kolejnych element�w z listy.
	@param istr Strumie� wej�ciowy
	*/
	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	int getSize();
	/**
	* \brief Dodaje element do wektora. Nale�y zwr�ci� uwag� na 
	* kolejno�� dodawanych element�w.
	* @param obj Wsa�nik na obiekt (typu asn_object) do dodania
	*/
	bool addElement(asn_object* obj); 
	asn_sequence(void);
	~asn_sequence(void);
};

#endif