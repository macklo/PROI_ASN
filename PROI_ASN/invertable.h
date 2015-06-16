/**
 * \file invertable.h
 * \brief Deklaracja wirtualnej klasy odwracaj�cej.
 */

#ifndef INVERT_H
#define INVERT_H


/** \brief Interfejs odwracaj�cy liczby
 */
class invertable{
public:
	virtual double invert() = 0; //!< Zwraca liczb� odwrotn� do zapisanej w obiekcie
};

#endif