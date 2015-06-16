/*! \file asn_int.h
    \brief Klasa reprezentuj�ca ca�kowit� liczb� dziesi�tn�
*/

#ifndef ASN_INT_H
#define ASN_INT_H

#include "asn_object.h"
#include "invertable.h"
#include "showable.h"
#include <iostream>
#include <cmath>

/** \brief Klasa reprezentuj�ca ca�kowit� liczb� dziesi�tn� (integer)
 */
class asn_int : public asn_object, public invertable, public showable
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
	int getSize(); //!<Zwraca rozmiar obiektu (liczb� oktet�w potrzebnych na jego zapisanie) @return Liczba oktet�w potrzebnych na zapisanie obiektu
	double invert(); //!<Zwraca liczb� odwrotn� do value @return Liczba odwrotna do value @return 0 gdy obiekt nie zawiera liczby lub value jest r�wne 0
	void show();

	int readAll(std::istream& istr);
	bool writeAll(std::ostream& ostr);
	asn_int(void);
	asn_int(int x); //!< Konstruktor deklaruj�cy zawarto�� @param x Warto�� do zapisania
	~asn_int(void);
};

#endif