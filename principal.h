#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();


private slots:

//  realizar el calculo();
    void on_cmdCalcular_released();
    void guardarpc();


private:
    Ui::Principal *ui;
    void depurar();
};
#endif // PRINCIPAL_H

