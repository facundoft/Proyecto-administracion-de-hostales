#include "CTRLUsuario.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/Integer.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/String.h"
#include "../clases/estructuras/Estadia.h"
#include "../clases/estructuras/Huesped.h"
#include "../clases/estructuras/Hostal.h"
#include "CTRLHostal.h"

CTRLUsuario::CTRLUsuario() : IUsuario()
{
    this->usuarios = new OrderedDictionary();
    this->empleados = new OrderedDictionary();
    this->huespedes = new OrderedDictionary();
}
CTRLUsuario *CTRLUsuario::instance = nullptr;

CTRLUsuario *CTRLUsuario::getInstance()
{
    if (instance == nullptr)
    {
        instance = new CTRLUsuario();
    }
    return instance;
}

bool CTRLUsuario::registrarEmpleado(string email, string nombre, string password, tipoEmpleado cargo)
{
    OrderedKey *mailKey = new String(email);
    ICollectible *encontro = empleados->find(mailKey);

    if (encontro == NULL)
    {
        this->email = email;
        this->nombre = nombre;
        this->password = password;
        this->cargo = cargo;
        this->tipoUsuario = "empleado";
    }
    delete mailKey;
    return (encontro != NULL);
}
<<<<<<< HEAD
bool CTRLUsuario::seleccionEstadia(string email, int codE)
{
    IKey *k = new String(email);
    hu = (Huesped *)huespedes->find(k);
    if (hu)
    {
        estadia = hu->getEstadia(codE);
        if (estadia)
            return true;
    }
    delete k;
    return false;
}
bool CTRLUsuario::existeUsuario(string email)
{
    IKey *k = new String(email);
    bool m = usuarios->member(k);
    delete k;
    return m;
}

bool CTRLUsuario::existeHuesped(string email)
{
    IKey *k = new String(email);
    bool m = huespedes->member(k);
    delete k;
    return m;
}
bool CTRLUsuario::existeEmpleado(string email)
{
    IKey *k = new String(email);
    bool m = empleados->member(k);
    delete k;
    return m;
=======
bool CTRLUsuario::existeUsuario(string email)
{
    return usuarios->member(new String(email));
>>>>>>> ba0a0c4726cf278116f9daf1138da820a6c43289
}
bool CTRLUsuario::registrarHuesped(string email, string nombre, string password, bool esTecnoPacker)
{
    OrderedKey *mailKey = new String(email);
    ICollectible *encontro = empleados->find(mailKey);
    if (encontro == NULL)
    {
        this->email = email;
        this->nombre = nombre;
        this->password = password;
        this->esTecnoPacker = esTecnoPacker;
        this->tipoUsuario = "huesped";
    }
    delete mailKey;
    return (encontro != NULL);
}

void CTRLUsuario::confirmarAltaUsuario()
{
    OrderedKey *nuevakey = new String(email);

    if (usuarios->find(nuevakey))
    {
        cout << "Mail ya registrado" << endl;
<<<<<<< HEAD
        delete nuevakey;
=======
>>>>>>> ba0a0c4726cf278116f9daf1138da820a6c43289
        return;
    }
    if (tipoUsuario == "huesped")
    {
        Huesped *nuevo = new Huesped(nombre, email, password, esTecnoPacker);

        usuarios->add(nuevakey, nuevo);
        huespedes->add(nuevakey, nuevo);
    }
    else if (tipoUsuario == "empleado")
    {
        Empleado *nuevo = new Empleado(nombre, email, password, cargo);

        usuarios->add(nuevakey, nuevo);
        empleados->add(nuevakey, nuevo);
    }
}
void CTRLUsuario::finalizarEstadia(int cod)
{
    if (hu)
    {
        hu->finalizarEstadia(cod);
    }
}

<<<<<<< HEAD
void CTRLUsuario::ingresarRespuesta(string respuesta, string mailHuesped, string mailEmpleado, int codEstadia)
{
    IKey *kH = new String(mailHuesped);
    IKey *kE = new String(mailEmpleado);
    Huesped *h = dynamic_cast<Huesped *>(huespedes->find(kH));
    Empleado *e = dynamic_cast<Empleado *>(empleados->find(kE));
    if (h != nullptr)
    {
        h->ingresarRespuesta(respuesta, e, codEstadia);
    }
    delete kE;
    delete kH;
}

std::set<dataCalificacion> CTRLUsuario::listarComentarios(string mail)
{
    IKey *k = new String(mail);
    set<dataCalificacion> calificaciones;
    Empleado *e = dynamic_cast<Empleado *>(empleados->find(k));
=======
void CTRLUsuario::ingresarRespuesta(string respuesta, string mail, int codEstadia)
{
    Huesped *h = dynamic_cast<Huesped *>(huespedes->find(new String(mail)));
    if (h != nullptr)
    {
        h->ingresarRespuesta(respuesta, codEstadia);
    }
}

std::set<string *> CTRLUsuario::listarComentarios(string mail)
{
    if (empleados->isEmpty())
    {
        cout << "No hay empleados registrados." << endl;
    }
    set<string *> dataEmpleado;
    Empleado *e = dynamic_cast<Empleado *>(empleados->find(new String(mail)));
>>>>>>> ba0a0c4726cf278116f9daf1138da820a6c43289
    if (e != nullptr)
    {
        calificaciones = e->listarComentariosHostal();
    }
    delete k;
    return calificaciones;
}

set<dataEstadia> CTRLUsuario::ListarEstadiasFinalizadas(string mail)
{
    set<dataEstadia> dataestadias;
<<<<<<< HEAD
    IKey *k = new String(mail);
    hu = dynamic_cast<Huesped *>(huespedes->find(k));
    if (hu != NULL)
=======
    Huesped *h = dynamic_cast<Huesped *>(huespedes->find(new String(mail)));
    if (h != nullptr)
>>>>>>> ba0a0c4726cf278116f9daf1138da820a6c43289
    {
        dataestadias = hu->devolverEstadiasF();
    }
    delete k;
    return dataestadias;
}

<<<<<<< HEAD
=======
// IDictionary * CTRLUsuario::listarUsuarios() {}
bool CTRLUsuario::modificarMail(string algo) {}

>>>>>>> ba0a0c4726cf278116f9daf1138da820a6c43289
dataHuesped CTRLUsuario::mostraHuesped()
{
    Huesped *huespedAux = (Huesped *)user;
    return huespedAux->devolverDatos();
}

dataEmpleado CTRLUsuario::mostrarEmpleado()
{
    Empleado *empleadoAux = (Empleado *)user;
    return empleadoAux->devolverDatos();
}

void CTRLUsuario::mostrarDatos()
{
    if (user == NULL)
    {
        cout << "Mail no registrado" << endl;
        return;
    }
    if (typeid(*user) == typeid(Huesped))
    {
        cout << "Tipo: Huesped" << endl
             << mostraHuesped();
    }
    else
        cout << "Tipo: Empleado" << endl
             << mostrarEmpleado();
}

void CTRLUsuario::seleccionarHuesped(string email)
{
    if (huespReserva == NULL)
    {
        huespReserva = new OrderedDictionary();
    }

    String *hueskey = new String(email);
    Huesped *h = (Huesped *)huespedes->find(hueskey);

    huespReserva->add(hueskey, h);
}

<<<<<<< HEAD
bool CTRLUsuario::listarEstadias(string email)
{
    String *hueskey = new String(email);
    hu = (Huesped *)huespedes->find(hueskey);
    delete hueskey;
    if (hu)
    {
        return hu->listarEstadias();
    }
    else
        return false;
}

void CTRLUsuario::seleccionarReserva(int codigoR, string email)
{
    if (hu == NULL || hu->getEmail() != email)
    {
        String *k = new String(email);
        hu = (Huesped *)huespedes->find(k);
        delete k;
    }
    if (hu)
    {
        hu->registrarEstadia(codigoR);
    }
=======
void CTRLUsuario::seleccionarReserva(int codigoR, string email)
{
    hu->registrarEstadia(codigoR);
>>>>>>> ba0a0c4726cf278116f9daf1138da820a6c43289
}

void CTRLUsuario::seleccionarUsuario(string mail)
{
    String *key = new String(mail);
    this->email = mail;
    user = (Usuario *)usuarios->find(key);
<<<<<<< HEAD
    delete key;
=======
>>>>>>> ba0a0c4726cf278116f9daf1138da820a6c43289
}

void CTRLUsuario::calificarEstadia(string mail, int codigo, int calificacion, const string comentario)
{
    if (hu == NULL || hu->getEmail() != mail)
    {
         String *key = new String(mail);
        hu = (Huesped *)huespedes->find(key);
        delete key;
    }
    if (hu)
    {
        hu->calificarEstadia(codigo, calificacion, comentario);
    }
    else
        cout << "Huesped invalido";
}

CTRLUsuario ::~CTRLUsuario() {}

std::set<string *> CTRLUsuario::listarUsuarios()
{
    set<string *> emails;
    if (usuarios->isEmpty())
    {
        cout << "No hay usuarios registrados." << endl;
    }
    else
    {
        IIterator *it;
        it = usuarios->getIterator();
        while (it->hasCurrent())
        {
            std::string nombre = dynamic_cast<Usuario *>(it->getCurrent())->getEmail();
            emails.insert(&nombre);
            cout << nombre << endl;
            it->next();
        }
    }
    return emails;
}
IDictionary *CTRLUsuario::ListarReservasHuesped(string email)
{
    IDictionary *listaR = new OrderedDictionary(); // DICCIONARIO A DEVOLVER
    this->email = email;
    String *mailk = new String(email);

    hu = (Huesped *)huespedes->find(mailk); // EL SISTEMA RECUERDA Y NUNCA OLVIDARA ESAS FRIAS NOCHES DE INVIERNO DONDE TUVO QUE DEBUGGEAR UN CODIGO DE C++ CON PUNTEROS A OBJETOS
    delete mailk;
    IDictionary *resH = hu->getReservas();
    if (resH->isEmpty())
        return NULL;
    for (IIterator *it = resH->getIterator(); it->hasCurrent(); it->next())
    {
        Reserva *r = (Reserva *)it->getCurrent();
        if (r->getEstado() != estadoReserva::cancelada)
        {
            cout << "Reserva " << r->getCodigo() << endl;
            Integer *codR = new Integer(r->getCodigo());
            listaR->add(codR, codR);
        }
    }
    return listaR;
}

std::set<string *> CTRLUsuario::listarEmpleados()
{
    set<string *> email;
    if (empleados->isEmpty())
    {
        cout << "No hay empleados registrados." << endl;
    }
    else
    {
        IIterator *it;
        it = empleados->getIterator();
        while (it->hasCurrent())
        {
            std::string nombre = dynamic_cast<Empleado *>(it->getCurrent())->getEmail();
            email.insert(&nombre);
            cout << nombre << endl;
            it->next();
        }
    }
    return email;
}

std::set<string *> CTRLUsuario::ListarHuespedes()
{
    set<string *> email;
    if (huespedes->isEmpty())
    {
        cout << "No hay Huespedes registrados." << endl;
    }
    else
    {
        IIterator *it;
        it = huespedes->getIterator();
        while (it->hasCurrent())
        {
            std::string nombre = dynamic_cast<Huesped *>(it->getCurrent())->getEmail();
            email.insert(&nombre);
            cout << nombre << endl;
            it->next();
        }
    }
    return email;
}

void CTRLUsuario::confirmarAsignacionEmpleadoHostal(string email, string cargo, string nombreH)
{
    // listarEmpleados(); en el main listo los empleados
    // listarhostales(); en el main listo los hostales

    IKey *mailKey = new String(email);
    ICollectible *encontro = empleados->find(mailKey);

    if (encontro == NULL)
    {
        cout << "No existe un empleado con este email" << endl;
        return;
    }
    CTRLHostal *CTH = CTRLHostal::getInstance();
    Hostal *h = CTH->buscarHostal(nombreH);
    if (h == NULL)
        return;
    Empleado *e = (Empleado *)encontro;

    if (cargo == "administracion ")
    {
        e->setCargo(administracion);
    }
    if (cargo == "recepcion")
    {
        e->setCargo(recepcion);
    }
    if (cargo == "limpieza")
    {
        e->setCargo(limpieza);
    }
    if (cargo == "infraestructura")
    {
        e->setCargo(infraestructura);
    }

    h->asignarEmpleado(mailKey, e);
}
dataReserva CTRLUsuario::mostrarReserva()
{
    Reserva *r = estadia->getReserva();
    return r->devolverDatos();
}
dataCalificacion CTRLUsuario::mostrarCalificacion()
{
    Calificacion *c = estadia->getCalificacion();
    if (c == NULL)
        return dataCalificacion();
    return c->devolverDatos();
}