#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib>
#include "yugioh_menu.h"
#include "../Techniques/Sequential/sequential.h"
#include "../Techniques/DynamicHash/extendibleHash.h"
#include "lol_menu.h"

#define salto cout << endl

using namespace std;

bool esEntero(string linea)
{
    bool esEntero = true;
    int longitud = linea.size();

    if (longitud == 0)
    {
        esEntero = false;
    }
    else if (longitud == 1 && !isdigit(linea[0]))
    {
        esEntero = false;
    }
    else
    {
        int indice = 0;
        if (linea[0] == '+' || linea[0] == '-')
        {
            indice = 1;
        }
        else
        {
            indice = 0;
        }

        while (indice < longitud)
        {
            if (!isdigit(linea[indice]))
            {
                esEntero = false;
                break;
            }
            indice++;
        }
    }

    return esEntero;
}


void menu_principal(Sequential<Record<char[30]>, string> &seq, ExtendibleHash<int> &eh);

void yugioh(Sequential<Record<char[30]>, string> &seq)
{
    string input;
    int opcion;
    bool repite = true;
    do
    {
        cout << "\e[1;1H\e[2J";
        cout << "Elegiste la tabla Yu-Gi-Oh" << endl;
        salto;
        cout << "¿Que accion quieres realizar?" << endl;
        cout << "-> Elige un numero" << endl;
        salto;
        salto;
        cout << "1. Volver al inicio" << endl;
        salto;
        cout << "2. Insertar registros aleatorios" << endl;
        salto;
        cout << "3. Insertar registro nuevo" << endl;
        salto;
        cout << "4. Buscar un registro" << endl;
        salto;
        cout << "5. Buscar un rango de registros" << endl;
        salto;
        cout << "6. Eliminar un registro" << endl;
        salto;
        cout << "7. Ver todos los registros" << endl;
        salto;
        cout << "8. Salir" << endl;
        salto;

        getline(cin, input);
        if (esEntero(input))
        {
            repite = false;
        }
    } while (repite);

    opcion = atoi(input.c_str());
    switch (opcion)
    {
    case 1:
        return;
        break;
    case 2:
        insertar_secuencial(seq);
        break;
    case 3:
        insertar_registro_secuencial(seq);
        break;
    case 4:
        buscar_registro_secuencial(seq);
        break;
    case 5:
        buscar_rango_registro_secuencial(seq);
        break;
    case 6:
        eliminar_registro_secuencial(seq);
        break;
    case 7:
        showData(seq);
        break;
    case 8:
        exit(-1);
        break;
    default:
        yugioh(seq);
        break;
    }
}

void Lol(ExtendibleHash<int> &eh)
{
    string input;
    int opcion;
    bool repite = true;
    do
    {
        cout << "\e[1;1H\e[2J";
        cout << "Elegiste la tabla League of Legends" << endl;
        salto;
        cout << "Que accion quieres realizar?" << endl;
        cout << "-> Elige un numero" << endl;
        salto;
        salto;
        cout << "1. Volver al inicio" << endl;
        salto;
        cout << "2. Insertar registros aleatorios" << endl;
        salto;
        cout << "3. Insertar registro nuevo" << endl;
        salto;
        cout << "4. Buscar un registro" << endl;
        salto;
        cout << "5. Buscar un rango de registros" << endl;
        salto;
        cout << "6. Eliminar un registro" << endl;
        salto;
        cout << "7. Salir" << endl;
        salto;

        getline(cin, input);
        if (esEntero(input))
        {
            repite = false;
        }
    } while (repite);

    opcion = atoi(input.c_str());
    switch (opcion)
    {
    case 1:
        return;
        break;
    case 2:
        insertar_hash(eh);
        break;
    case 3:
        insertar_registro_hash(eh);
        break;
    case 4:
        buscar_registro_hash(eh);
        break;
    case 5:
        buscar_rango_registro_hash(eh);
        break;
    case 6:
        eliminar_registro_hash(eh);
        break;
    case 7:
        exit(-1);
        break;
    default:
        Lol(eh);
        break;
    }
}

void menu_principal(Sequential<Record<char[30]>, string> &seq, ExtendibleHash<int> &eh)
{

    while (1)
    {
        string input;
        int opcion;
        bool repite = true;
        do
        {
cout<<"  ______      ______    ______     ______     " << endl;
cout<<".' ____ \'   .' ___  |  |_   _ \'   |_   _ `.  " << endl;
cout<<"| (___ \'_| / .'   \'_|    | |_) |    | | `. \' " << endl;
cout<<" _.____`.  | |   ____    |  __'.    | |  | | " << endl;
cout<<"| \'____) | \' `.___]  |  _| |__) |  _| |_.' / " << endl;
cout<<" \'______.'  `._____.'  |_______/  |______.' " << endl;
cout<<" " << endl;
cout<<" " << endl;
            cout << "Bienvenido a tu almacenamiento de datos" << endl;
            salto;
            cout << "Que tabla quieres modificar?" << endl;
            cout << "-> Elige un numero" << endl;
            salto;
            salto;
            cout << "1. Yu-Gi-Oh! - Secuencial" << endl;
            salto;
            cout << "2. LeagueofLegends - Extendible Hash" << endl;
            salto;
            cout << "3. Salir" << endl;
            salto;

            getline(cin, input);
            if (esEntero(input))
            {
                repite = false;
            }
        } while (repite);

        opcion = atoi(input.c_str());

        switch (opcion)
        {
        case 1:
            yugioh(seq);
            break;
        case 2:
            Lol(eh);
            break;
        case 3:
            exit(-1);
            break;
        default:
            menu_principal(seq, eh);
            break;
        }
    }
}

#endif