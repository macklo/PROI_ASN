/** \file asn_object.h
    \brief Deklaracja klasy asn_object
*/

#ifndef ASN_OBJECT_H
#define ASN_OBJECT_H

#include <iostream>
#include <string>
#include <sstream>

/** \brief Klasa abstrakcyjna, klasa podstawowa dla wszystkich pozosta�ych
 *
 * 	Klasa ta jest punktem wyj�cia dla ka�dej klasy pochodnej u�ywanej w programie.
 */
class asn_object
{
protected:
	int tag; //!< tag, zapisany w formacie dziesi�tnym
	int size; //!< Rozmiar - ilo�� oktet�w potrzebnych na zapisanie danych (bez tag i size)
	bool writeable; //!< Okre�la czy dany obiekt mo�na zapisa� w postaci ASN1
	int hex2int(char c); //!< Konwersja z formatu szesnastkowego do liczby dziesi�tnej
	std::string int2hex(int n); //!< Konwersja z liczby dziesi�tnej do formatu szesnastkowego
	int read(std::istream& istr); //!< Odczytuje oktet (dwa znaki) i zwraca je w postaci dziesi�tnej
	bool checkTag(std::istream& istr); //!<Odczytuje oktet i sprawdza czy zgadza si� z tagiem obiektu @param istr Wska�nik na strumie� wej�ciowy @return true gdy operacja zako�czy�a si� powodzeniem @return false gdy operacja zako�czy�a si� niepowodzeniem (b��d odczytu, lub b��dny tag)
	bool readSize( std::istream& istr); //!<Odczytuje oktet i zapisuje jego rozmiar @param istr Wska�nik na strumie� wej�ciowy @return true gdy odczyt zako�czy� si� powodzeniem @return false gdy odczyt zako�czy� si� niepowodzeniem
public:

	/**
	* \brief Odczytuje obiekt ze streama i zwraca ilo�� odczytanych oktet�w 
	* @param istr Wska�nik na strumie� wej�ciowy
	* @return Ilo�� odczytanych oktet�w
	* @return -1 w przypadku gdy odczyt zako�czy� si� niepowodzeniem
	*/
	virtual int readAll(std::istream& istr) = 0; //!<
	/**
	* \brief Zapisuje obiekt do streama w postaci zakodowanej w ASN 
	* @param ostr Wska�nik na strumie� wyj�ciowy
	* @return true - gdy zapis si� powi�d�
	* @return false - gdy zapis si� nie powi�d�
	*/
	virtual bool writeAll(std::ostream& ostr) = 0; 
	/**
	* \brief Zwraca rozmiar obiektu (liczb� oktet�w potrzebnych na zapisanie zawartych w nim danych). 
	* Uwaga: Zwracana liczba nie uzwzgl�dnia miejsca na tag i size
	* @return Liczba oktet�w potrzebynych do zapisania danych
	*/
	virtual int getSize() = 0; 
	asn_object(void);
	~asn_object(void);
};

#endif