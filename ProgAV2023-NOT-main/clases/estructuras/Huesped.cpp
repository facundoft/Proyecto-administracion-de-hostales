#include <iostream>
#include "Huesped.h"
#include "Estadia.h"
#include "Reserva.h"
#include "../../ICollection/Integer.h"
using namespace std;

Huesped::Huesped(string _nombre, string _email, string _password, bool _esTecnoPacker) : Usuario(_nombre, _email, _password)
{
    esTecnoPacker = _esTecnoPacker;
    reservas = new OrderedDictionary();
    estadias = new OrderedDictionary();
}
void Huesped::eliminarReserva(IKey *cod)
{
    reservas->remove(cod);
}
bool Huesped::getEsTecnoPacker()
{
    return esTecnoPacker;
}
bool Huesped::listarEstadias()
{
    for (IIterator *it = estadias->getIterator(); it->hasCurrent(); it->next())
    {
        Estadia *e = (Estadia *)it->getCurrent();
        cout << "Codigo: " << e->getCodigo() << endl;
    }
    return !(estadias->isEmpty());
}

void Huesped::setEsTecnoPacker(bool _esTecnoPacker)
{
    esTecnoPacker = _esTecnoPacker;
}
IDictionary *Huesped::getEstadia()
{
    return estadias;
}
void Huesped::eliminarEstadia(int estadia)
{
    IKey *k = new Integer(estadia);
    estadias->remove(k);
}
Estadia *Huesped::getEstadia(int codE)
{
    Estadia *e = (Estadia *)estadias->find(new Integer(codE));
    return e;
}
dataHuesped Huesped::devolverDatos()
{
    dataHuesped salida = dataHuesped(this->getName(), this->getEmail(), this->getPassword(), this->getEsTecnoPacker());
    return salida;
}
set<dataEstadia> Huesped::devolverEstadiasF()
{
    set<dataEstadia> dataEs;
    for (IIterator *it = estadias->getIterator(); it->hasCurrent(); it->next())
    {
        Estadia *e = (Estadia *)it->getCurrent();
        if (e->finalizoEstadia())
        {
            dataEstadia estsH = e->devolverDatos();
            cout << "Codigo: " << estsH.codigoEstadia << endl;
            dataEs.insert(estsH);
        }
    }
    return dataEs;
}

void Huesped::calificarEstadia(int codigo, int calificacion, string comentario)
{
    Integer *k = new Integer(codigo);
    Estadia *e = (Estadia *)estadias->find(k);
    if (e)
    {
        e->calificarEstadia(calificacion, comentario, this);
    }
    else
        cout << "Estadia " << codigo << " no registrada" << endl;
    ;
    delete k;
}
void Huesped::finalizarEstadia(int codigo)
{
    IKey *k = new Integer(codigo);
    Estadia *e = (Estadia *)estadias->find(k);
    if (e)
    {
        e->finalizar();
    }
    delete k;
}
void Huesped::addEstadia(IKey *k, Estadia *e)
{
    estadias->add(k, e);
}
void Huesped::agregarReserva(IKey *key, Reserva *r)
{
    reservas->add(key, r);
}
IDictionary *Huesped::getReservas()
{
    return reservas;
}
void Huesped::registrarEstadia(int codigo)
{
    Integer *codk = new Integer(codigo);
    Reserva *r = (Reserva *)reservas->find(codk);
    if (r == NULL)
    {
        cout << "Reserva inexistente";
    }
    else
    {
        r->registrarEstadia(this);
    }
    delete codk;
}

void Huesped::ingresarRespuesta(string respuesta, Empleado *e, int codigo)
{
    Estadia *est = dynamic_cast<Estadia *>(estadias->find(new Integer(codigo)));
    est->ingresarRespuesta(respuesta, e);
}