/**
 * \file showable.h
 * \brief Deklaracja wirtualnej klasy wypisuj¹cej dane do standardowego wyjœcia (cout).
 */

#ifndef SHOWABLE_H
#define SHOWABLE_H

#include <iostream>

/** \brief Interfejs wypisuj¹cy dane do standardowego wyjœcia (cout).
 */
class showable{
public:
	virtual void show() = 0; //!< Wypisuje dane z obiektu do standardowego wyjœcia (cout)
};

#endif