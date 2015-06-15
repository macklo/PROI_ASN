/** \file asn_object.h
    \brief Deklaracja klasy asn_object
*/

#ifndef ASN_OBJECT_H
#define ASN_OBJECT_H

#include <iostream>
#include <string>
#include <sstream>

/** \brief Klasa abstrakcyjna, klasa podstawowa dla wszystkich pozosta³ych
 *
 * 	Klasa ta jest punktem wyjœcia dla ka¿dej klasy pochodnej u¿ywanej w programie.
 */
class asn_object
{
protected:
	int tag; //!< TAG, zapisany w formacie dziesiêtnym
	int size; //!< Rozmiar - iloœæ oktetów
	bool writeable; //!< Okreœla czy dany obiekt mo¿na zapisaæ w postaci ASN1
	int hex2int(char c); //!< Konwersja z formatu szesnastkowego do liczby dziesiêtnej
	std::string int2hex(int n); //!< Konwersja z liczby dziesiêtnej do formatu szesnastkowego
	int read(std::istream& istr); //!< Odczytuje oktet (dwa znaki) i zwraca je w postaci dziesiêtnej
	bool checkTag(std::istream& istr); //!<Odczytuje oktet i sprawdza czy zgadza siê z tagiem obiektu
	bool readSize( std::istream& istr); //!<Odczytuje oktet i zapisuje jego rozmiar
public:
	virtual int readAll(std::istream& istr) = 0; //!<Odczytuje obiekt ze streama
	virtual bool writeAll(std::ostream& ostr) = 0; //!<Zapisuje obiekt do streama
	virtual int getSize() = 0; //!<Zwraca rozmiar obiektu (liczbê oktetów potrzebnych na jego zapisanie)
	asn_object(void);
	~asn_object(void);
};

#endif