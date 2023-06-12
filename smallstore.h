#ifndef SMALLSTORE_H
#define SMALLSTORE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class SmallStore; }
QT_END_NAMESPACE

class SmallStore : public QMainWindow
{
    Q_OBJECT

public:
    SmallStore(QWidget *parent = nullptr);
    ~SmallStore();

private:
    Ui::SmallStore *ui;
};
#endif // SMALLSTORE_H
