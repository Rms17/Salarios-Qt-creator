#include "calculosalario.h"
#include "calculosalario.h"
// parent padre
// QObject clase padre

CalculoSalario::CalculoSalario (QObject *parent) : QObject(parent)
{

}

//Constructor mismo nombre de la clase recibe mi nombre, horas y jornada "variables"
CalculoSalario::CalculoSalario(QString nombre, int horas, char jornada):CalculoSalario(nullptr)
{
    this->m_nombre=nombre; //lo que recibe
    this->m_horas = horas;
    this->m_jornada=jornada;

}



void CalculoSalario::calcular()
{
    float valorHora=0;
    switch (this->m_jornada){
    case 'v':
        valorHora = VALOR_HORA_VESPERTINO;
        break;
    case 'm':
        valorHora = VALOR_HORA_MATUTINO;
        break;
    case 'n':
        valorHora = VALOR_HORA_NOCTURNO;
        break;

    default:
        break;
    }



    m_salario = m_horas * valorHora;
    m_descuento = m_salarioNeto * PORCENTAJE_DESCUENTO/100;
    m_salarioNeto = m_salario - m_descuento;

}

float CalculoSalario::descuento() const
{
    return m_descuento;
}

float CalculoSalario::salarioNeto() const
{
    return m_salarioNeto;
}

float CalculoSalario::salario() const
{
    return m_salario;
}
