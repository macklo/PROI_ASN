/*! \file asn_int.h
    \brief Klasa reprezentuj¹ca ca³kowit¹ liczbê dziesiêtn¹
*/

#ifndef ASN_INT_H
#define ASN_INT_H

#include "asn_object.h"
#include <iostream>
#include <cmath>

/** \brief Klasa reprezentuj¹ca ca³kowit¹ liczbê dziesiêtn¹ (integer)
 */
class asn_int : public asn_object
{
protected:
	
private:
	int value; //!<Przechowywana wartoœæ
public:
	void setValue(int x); //!<Ustawianie nowej wartoœci @param x Liczba ca³kowita do zapisania
	/**
	 * \brief Sprawdza czy obiekt ma zapisan¹ wartoœæ i j¹ zwraca
	 * @see writeable
	 */
	int getValue(); 
	int getSize(); //!<Zwraca rozmiar obiektu (liczbê oktetów potrzebnych na jego zapisanie)

	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	asn_int(void);
	asn_int(int x); //!< Konstruktor deklaruj¹cy zawartoœæ @param x Wartoœæ do zapisania
	~asn_int(void);
};

#endif