/**
 * \file showable.h
 * \brief Deklaracja wirtualnej klasy wypisuj�cej dane do standardowego wyj�cia (cout).
 */

#ifndef SHOWABLE_H
#define SHOWABLE_H

#include <iostream>

/** \brief Interfejs wypisuj�cy dane do standardowego wyj�cia (cout).
 */
class showable{
public:
	virtual void show() = 0; //!< Wypisuje dane z obiektu do standardowego wyj�cia (cout)
};

#endif