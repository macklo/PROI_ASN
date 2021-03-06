/**
 * \file invertable.h
 * \brief Deklaracja wirtualnej klasy odwracającej.
 */

#ifndef INVERT_H
#define INVERT_H


/** \brief Interfejs odwracający liczby
 */
class invertable{
public:
	virtual double invert() = 0; //!< Zwraca liczbę odwrotną do zapisanej w obiekcie
};

#endif