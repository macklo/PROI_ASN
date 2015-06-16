/**
 * \file invertable.h
 * \brief Deklaracja wirtualnej klasy odwracaj¹cej.
 */

#ifndef INVERT_H
#define INVERT_H


/** \brief Interfejs odwracaj¹cy liczby
 */
class invertable{
public:
	virtual double invert() = 0; //!< Zwraca liczbê odwrotn¹ do zapisanej w obiekcie
};

#endif