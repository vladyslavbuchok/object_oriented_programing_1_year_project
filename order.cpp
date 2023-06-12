#include "order.h"
#include <QDebug>

order::order(std::string data_zamowienia, platnosc sposob_platnosci)
{
    this->data_zamowienia = data_zamowienia;
    this->sposob_platnosci = sposob_platnosci;
    this->cena_zamowienia = 0;
}

void order::setSposobPlatnosci(platnosc sposob_platnosci)
{
    this->sposob_platnosci = sposob_platnosci;
}

void order::dodajProduct(std::vector<struct product> &lista_productow, std::string product_name, int ilosc)
{
    if(ilosc>0){
        if(!lista_productow.empty()){
            for(struct product& i : lista_productow){
                if(i.product_name == product_name && ilosc<=i.ilosc){
                    this->products.push_back(i);
                    this->products.back().ilosc = ilosc;
                    i.ilosc -= ilosc;
                    return;
                }
            }
            qDebug("Niema takigo produktu w potrzebnej ilosci");
        }else qDebug("Lista produktow pusta");
    }
}

void order::zmienZamowienie(std::vector<product> &lista_productow, std::string product_name, int ilosc)
{
    int szukany_product_index = -1;
    int szukany_product_lista_index = -1;
    for(int i = 0; this->products.size(); i++){
        if(this->products.at(i).product_name == product_name){szukany_product_index = i; break;}
    }
    for(int i = 0; lista_productow.size(); i++){
        if(lista_productow.at(i).product_name == product_name){szukany_product_lista_index = i; break;}
    }

    if(szukany_product_index == -1){
        qDebug("Niema takiego produktu w zamowieniu!");
        dodajProduct(lista_productow, product_name, ilosc);
        return;
    }

    if(szukany_product_lista_index == -1){
        qDebug("Niema takiego produktu w liscie produktow");
        return;
    }

    if(ilosc <= 0){
        lista_productow.at(szukany_product_lista_index).ilosc += this->products.at(szukany_product_index).ilosc;
        this->products.erase(this->products.begin() + szukany_product_index);
    }else if(ilosc > lista_productow.at(szukany_product_lista_index).ilosc + this->products.at(szukany_product_index).ilosc){qDebug("Nie wystarcz danego produktu"); return;}
    else{
        lista_productow.at(szukany_product_lista_index).ilosc -= ilosc + this->products.at(szukany_product_index).ilosc;
        this->products.at(szukany_product_index).ilosc = ilosc;
    }
}

std::string order::orderToString()
{
    std::string info = "Data zamowienia: " + this->data_zamowienia;
    return info;
}

