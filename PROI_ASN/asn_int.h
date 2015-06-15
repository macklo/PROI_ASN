/*! \file asn_int.h
    \brief Klasa reprezentuj�ca ca�kowit� liczb� dziesi�tn�
*/

#ifndef ASN_INT_H
#define ASN_INT_H

#include "asn_object.h"
#include <iostream>
#include <cmath>

/** \brief Klasa reprezentuj�ca ca�kowit� liczb� dziesi�tn� (integer)
 */
class asn_int : public asn_object
{
protected:
	
private:
	int value; //!<Przechowywana warto��
public:
	void setValue(int x); //!<Ustawianie nowej warto�ci @param x Liczba ca�kowita do zapisania
	/**
	 * \brief Sprawdza czy obiekt ma zapisan� warto�� i j� zwraca
	 * @see writeable
	 */
	int getValue(); 
	int getSize(); //!<Zwraca rozmiar obiektu (liczb� oktet�w potrzebnych na jego zapisanie)

	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	asn_int(void);
	asn_int(int x); //!< Konstruktor deklaruj�cy zawarto�� @param x Warto�� do zapisania
	~asn_int(void);
};

#endif