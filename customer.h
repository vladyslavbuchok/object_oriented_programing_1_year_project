#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "order.h"
#include <iostream>
#include <vector>
using namespace std;



enum sex{ M, F};
class customer
{
private:
    string imie;
    string nazwisko;
    short wiek;
    sex plec;
    string address_dostawy;
    string numer_telefonu;
    vector<order> zamowienia;
public:
    customer(string imie, string nazwisko, short wiek, sex plec, string address_dostawy, string numer_telefonu);
    void setName(string imie);
    void setSurname(string nazwisko);
    void setAge(short wiek);
    void setSex(sex plec);
    void setAddress(string address_dostawy);
    void setPhoneNum(string numer_telefonu);
    void dodajZamowienia(order zamowienie);
    std::string customerToText();
};

#endif // CUSTOMER_H
