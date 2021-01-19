#include "principal.h"
#include "ui_principal.h"

#include <QFileDialog>
#include <QDebug>


#include <calculosalario.h>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);

    connect(ui->actionCalcular,SIGNAL(triggered(bool)),
            this,SLOT(on_cmdCalcular_released()));
    connect(ui->cmdCalcular,SIGNAL(released(bool)),
            this,SLOT(on_plainTextEdit_textChanged()));
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_cmdCalcular_released()
{
    //Obtener datos de la UI
    QString nombre=this->ui->inNombre->text();
    int horas=this->ui->inHoras->value();
    char jornada = 'm';
    float salario = 0;



    if (this->ui->inMatutino->isChecked()){
        jornada = 'm';
        salario = (horas * 5.15)*2 ;
        //Tomando en cuenta el valor básico de un suelo de 400$
        //Hora de trabajo al 25% (recargas)
        //Adicional a cada hora de trabajo ,recargo de las obras
        //multiplico por 2 las horas extras del trabajador

    }else if (this->ui->inVespertino->isChecked()){
        jornada = 'v';
        salario = (horas * 8.50)*2 ;
        //Hora de trabajo al 50% (recargas)
        //multiplico por 2 las horas extras del trabajador


    }else{
        jornada = 'n';
        salario = (horas * 12.65)*2 ;
        //Hora de trabajo al 100% (recargas)

    }


    // Calculo del descuento

    float descuento = salario * 9.5 /100;
    float salarioNeto = salario - descuento;


   //Crear el objeto para calcular el salario
   CalculoSalario rolPagos (nombre,horas,jornada);
   rolPagos.calcular();

  // qDebug()<< rolPagos.salario()<< rolPagos.descuento()<< rolPagos.salarioNeto();

   //Imprimir el resultado del usuario
   QString total = "\nNombre: " +nombre+ "\n";
   total += "Salario $" +QString::number(salario) + "\n";

   total += "Descuento %"+QString::number(descuento)+ "\n";
   total += "Salario neto: $" + QString::number(salarioNeto) + "\n";
   total += "--\n";



   ui->outCalcular->appendPlainText(total);
   depurar();

}

void Principal::guardarpc()
{
    //Guarda el algoritmo programado a la carpeta específica del computador
    QString fileName = QFileDialog::getSaveFileName(this,
                       "Guardar datos del salario", QDir::home().absolutePath(), "Archivo de configuracion (*.cfg)");
    QFile data(fileName);
}

void Principal::depurar()
{
    ui->inNombre->setText("");
    ui->inHoras->setValue(0);
    ui->inMatutino->setChecked(true);
    ui->inVespertino->setChecked(true);
    ui->inNocturno->setChecked(true);
    ui->inNombre->setFocus();

}

