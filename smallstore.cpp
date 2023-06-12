#include "smallstore.h"
#include "ui_smallstore.h"

SmallStore::SmallStore(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SmallStore)
{
    ui->setupUi(this);
}

SmallStore::~SmallStore()
{
    delete ui;
}

