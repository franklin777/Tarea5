#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "Nodo.h"
using namespace std;


template <typename Tipo>
class Lista
{
public:
    Nodo<Tipo>* inicio;

    Lista()
    {
        inicio = NULL;
    }

    void imprimir()
    {
        for(Nodo<Tipo>* temp = inicio;
            temp!=NULL;
            temp = temp->sig)
        {
            cout<<temp->num<<endl;
        }
    }

    void agregarAlInicio(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            nuevo->sig = inicio;
            inicio = nuevo;
        }
    }

    void agregarAlFinal(Tipo valor_nuevo)
    {
        Nodo<Tipo> *nuevo = new Nodo<Tipo>(valor_nuevo);

        if(inicio == NULL)
        {
            inicio = nuevo;
        }else
        {
            Nodo<Tipo>*temp = inicio;
            while(temp->sig!=NULL)
            {
                temp=temp->sig;
            }
            temp->sig = nuevo;
        }
    }

    void borrar(Tipo valor_a_borrar)
    {
        if(inicio->num == valor_a_borrar)
        {
            Nodo<Tipo>* borrar = inicio;
            inicio = inicio->sig;
            delete borrar;
        }else
        {
            Nodo<Tipo>* temp = inicio;
            while(temp->sig->num!=valor_a_borrar)
            {
                temp=temp->sig;
                if(temp->sig==NULL)
                    return;
            }
            Nodo<Tipo>* borrar = temp->sig;
            temp->sig = temp->sig->sig;
            delete temp->sig;
        }
    }

    //Devuelve true si la lista esta vacia, de lo contrario devuelve false
    bool estaVacia()
    {
        if (inicio==NULL) //Si el inicio es igual a NULL
            return true; //Devolvemos true
        return false;//Si no False
    }

    //Devuelve el valor almacenado en el primer nodo de la lista
    Tipo obtenerPrimerValor()
    {
        Tipo val=inicio->valor; //Variable que almacena el primer valor
        return val; //Retorno la variable
    }

    //Devuelve el valor almacenado en el ultimo nodo de la lista
    Tipo obtenerUltimoValor()
    {
        Nodo<Tipo>*i; //Variable que servirá para recorrer la lista, tipo Tipo.
        for(i=inicio; i->sig!=NULL; i=i->sig) //Va desde el principio al final.
        {}
        return i->valor; //Ahora que el apuntador se encuentra en la última posición de la lista, devolvemos ese valor.
    }

    //Devuelve el valor mayor almacenado en la lista
    Tipo obtenerMayor()
    {
        int val=NULL; //Variable que almacenará el valor mayor de la lista, inicializada en NULL.
        Nodo<Tipo>*i=inicio; //Variable que nos servirá para recorrer la lista.
        do //Inicio del ciclo.
        {
            i=i->sig; // Avanza a la siguiente posicion de la lista
            if((i->valor)>val)
                val=i->valor; // Si se encuentra un número mayor que el actual, se procede a cambiarlo por ese.
        }while(i->sig!=NULL); //Mientras sea diferente a NULL y llegue al final
        return val; //Regresa el valor mayor que se encontro al recorrer la lista.
       // Me guié del siguiente foro para este ejercicio en específico http://www.c.conclase.net/edd/?cap=001f
    }

};
#endif // LISTA_H
