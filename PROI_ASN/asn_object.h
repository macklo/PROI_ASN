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
	int tag; //!< tag, zapisany w formacie dziesiêtnym
	int size; //!< Rozmiar - iloœæ oktetów potrzebnych na zapisanie danych (bez tag i size)
	bool writeable; //!< Okreœla czy dany obiekt mo¿na zapisaæ w postaci ASN1
	int hex2int(char c); //!< Konwersja z formatu szesnastkowego do liczby dziesiêtnej
	std::string int2hex(int n); //!< Konwersja z liczby dziesiêtnej do formatu szesnastkowego
	int read(std::istream& istr); //!< Odczytuje oktet (dwa znaki) i zwraca je w postaci dziesiêtnej
	bool checkTag(std::istream& istr); //!<Odczytuje oktet i sprawdza czy zgadza siê z tagiem obiektu @param istr WskaŸnik na strumieñ wejœciowy @return true gdy operacja zakoñczy³a siê powodzeniem @return false gdy operacja zakoñczy³a siê niepowodzeniem (b³¹d odczytu, lub b³êdny tag)
	bool readSize( std::istream& istr); //!<Odczytuje oktet i zapisuje jego rozmiar @param istr WskaŸnik na strumieñ wejœciowy @return true gdy odczyt zakoñczy³ siê powodzeniem @return false gdy odczyt zakoñczy³ siê niepowodzeniem
public:

	/**
	* \brief Odczytuje obiekt ze streama i zwraca iloœæ odczytanych oktetów 
	* @param istr WskaŸnik na strumieñ wejœciowy
	* @return Iloœæ odczytanych oktetów
	* @return -1 w przypadku gdy odczyt zakoñczy³ siê niepowodzeniem
	*/
	virtual int readAll(std::istream& istr) = 0; //!<
	/**
	* \brief Zapisuje obiekt do streama w postaci zakodowanej w ASN 
	* @param ostr WskaŸnik na strumieñ wyjœciowy
	* @return true - gdy zapis siê powiód³
	* @return false - gdy zapis siê nie powiód³
	*/
	virtual bool writeAll(std::ostream& ostr) = 0; 
	/**
	* \brief Zwraca rozmiar obiektu (liczbê oktetów potrzebnych na zapisanie zawartych w nim danych). 
	* Uwaga: Zwracana liczba nie uzwzglêdnia miejsca na tag i size
	* @return Liczba oktetów potrzebynych do zapisania danych
	*/
	virtual int getSize() = 0; 
	asn_object(void);
	~asn_object(void);
};

#endif