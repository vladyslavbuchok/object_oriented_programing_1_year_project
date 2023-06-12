#include "customer.h"

customer::customer(string imie, string nazwisko, short wiek, sex plec, string address_dostawy, string numer_telefonu)
    :imie(imie), nazwisko(nazwisko), wiek(wiek), plec(plec), address_dostawy(address_dostawy), numer_telefonu(numer_telefonu)
{

}

void customer::setName(string imie)
{
    this->imie = imie;
}

void customer::setSurname(string nazwisko)
{
    this->nazwisko = nazwisko;
}

void customer::setAge(short wiek)
{
    this->wiek = wiek;
}

void customer::setSex(sex plec)
{
    this->plec = plec;
}

void customer::setAddress(string address_dostawy)
{
    this->address_dostawy = address_dostawy;
}

void customer::setPhoneNum(string numer_telefonu)
{
    this->numer_telefonu = numer_telefonu;
}

void customer::dodajZamowienia(order zamowienie)
{
    this->zamowienia.push_back(zamowienie);
}

string customer::customerToText()
{
    std::string info = this->imie + " " + this->nazwisko + " (";
    info += (this->plec == M) ? "M) Age: "+to_string(this->wiek)+"\n" : "F) Age: "+to_string(this->wiek)+"\n" ;
    info += "Numer telefoniczny: " + this->numer_telefonu + " Adres dostawy: " + this->address_dostawy;
    return info;
}
