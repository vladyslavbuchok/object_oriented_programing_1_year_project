#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <iostream>
#include <vector>
struct product{
    std::string product_name;
    int ilosc;
    double stawka_VAT;
    double cena;
};

enum platnosc{
    karta, blik, gotowka
};

class order
{
    std::vector<product> products;
    std::string data_zamowienia;
    platnosc sposob_platnosci;
    double cena_zamowienia;
public:
    order(std::string data_zamowienia, platnosc sposob_platnosci);
    void setSposobPlatnosci(platnosc sposob_platnosci);
    void dodajProduct(std::vector<struct product> &lista_productow, std::string product_name, int ilosc);
    void zmienZamowienie(std::vector<struct product> &lista_productow, std::string product_name, int ilosc);
    std::string orderToString();
};

#endif // ORDER_H
