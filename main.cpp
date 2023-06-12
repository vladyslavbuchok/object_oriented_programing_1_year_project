#include "smallstore.h"
#include "customer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SmallStore w;
    w.show();
    return a.exec();
}


