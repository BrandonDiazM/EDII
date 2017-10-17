#ifndef CONTACTO_H_INCLUDED
#define C0NTACTO_H_INCLUDED

#include <iostream>
#include <string>

class Contacto{

private:
    std::string primerNombre;
    std::string apellidoPaterno;
    std::string direccion;
    std::string ciudad;
    std::string estado;
    std::string codigoPostal;
public:
    Contacto() : primerNombre(""), apellidoPaterno(""), direccion("")
                  ,ciudad(""), estado(""), codigoPostal("") {}

    void setPrimerNombre(const std::string & e ){
        primerNombre = e;
    }

    std::string getPrimerNombre(){
        return primerNombre;
    }

    void setApellidoPaterno(const std::string & e){
        apellidoPaterno = e;
    }
    std::string getApellidoPaterno(){
        return apellidoPaterno;
    }

    void setDireccion(const std::string & e){
        direccion = e;
    }
    std::string getDireccion(){
        return direccion;
    }

    void setCiudad(const std::string & e){
        ciudad = e;
    }
    std::string getCiudad(){
        return ciudad;
    }

    void setEstado(const std::string & e){
        estado = e;
    }
    std::string getEstado(){
        return estado;
    }

    void setCodigoPostal(const std::string & e){
        codigoPostal = e;
    }
    std::string getCodigoPostal(){
        return codigoPostal;
    }

};


#endif // CONTACTO_H_INCLUDED
