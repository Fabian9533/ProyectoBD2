#ifndef PES_MENU_H
#define PES_MENU_H

#include "../Techniques/Sequential/sequential.h"
#include <stdio.h>
#include <time.h>
#define NOMBRE_ARCHIVO_PES "pes2021-all-players.csv"

using namespace std;

void post_insertar_aleatorio(Sequential<Record<char[30]>, string> &seq);

bool esEntero_p(string linea)
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

void insertar_secuencial(Sequential<Record<char[30]>, string> &seq)
{

    ifstream archivo(NOMBRE_ARCHIVO_PES);
    string linea;
    char delimitador = ',';
    // Leemos la primea linea para descartarla, pues es el encabezado
    getline(archivo, linea);
    vector<Record<char[30]>> records;

    // Leemos todos las linea
    clock_t t;

    while (getline(archivo, linea))
    {
        int height = 0;
        int weight = 0;
        int age = 0;
        int shirt_number = 0;

        stringstream stream(linea); //Convertir la cadena a un stream
        string Name, Team_name, League, Nationality, Region, Height, Weight, Age, Foot;
        //Extraer todos los valores
    
        getline(stream, Name, delimitador);
        getline(stream, Team_name, delimitador);
        getline(stream, League, delimitador);
        getline(stream, Nationality, delimitador);
        getline(stream, Region, delimitador);
        getline(stream, Foot, delimitador);

        stringstream _height(height);
        stringstream _weight(weight);
        stringstream _age(age);
        stringstream _shirt(shirt_number);

        _height >> height;
        _weight >> weight;
        _age >> age;
        _shirt >> shirt_number;

        Record<char[30]> temp(Name, shirt_number, Team_name, League, Nationality, Region, height, weight, age, Foot);

        //guardar en vector
        records.push_back(temp);
    }
    t = clock();
    int accesos = seq.insertAll(records);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    cout << endl;
    printf("El programa tomo %f segundos en insertar los %zu registros", time_taken, records.size());
    printf("\nEl programa tomo %d accesos a memoria secundaria", accesos);
    dump();
    post_insertar_aleatorio(seq);
}

void post_insertar_aleatorio(Sequential<Record<char[30]>, string> &seq)
{

    string input;
    int opcion;
    bool repite = true;
    do
    {
        cout << "\e[1;1H\e[2J";
        cout << "Se insertaron los datos existosamente" << endl;
        cout << endl;
        cout << "Deseas verlos?" << endl;
        cout << "-> Elige un numero" << endl;
        cout << endl;
        cout << endl;
        cout << "1. Si -> Mostrar datos" << endl;
        cout << endl;
        cout << "2. No -> Regresar al menu de inicio" << endl;
        cout << endl;
        cout << "3. Salir" << endl;
        cout << endl;

        getline(cin, input);
        if (esEntero_p(input))
        {
            repite = false;
        }
    } while (repite);

    opcion = atoi(input.c_str());

    switch (opcion)
    {
    case 1:
        seq.showRecords();
        break;
    case 2:
        return;
        break;
    case 3:
        exit(-1);
        break;
    default:
        post_insertar_aleatorio(seq);
        break;
    }
    dump();
}
void insertar_registro_secuencial(Sequential<Record<char[30]>, string> &seq)
{
    cout << "\n\n----------Insertar----------\n\n";
    string name;
    string team_name;
    string league;
    string nationality;
    string region;
    string foot;
    clock_t t;
    int shirt_number, height, weight, age;

    cout << "Ingrese el Nombre del jugador (30 carac. max): ";
    cin >> name;
    cout << "Ingrese el Nombre del equipo (20 carac. max): ";
    cin >> team_name;
    cout << "Ingrese la liga (30 carac. max): ";
    cin >> league;
    cout << "Ingrese la nacionalidad (20 carac. max): ";
    cin >> nationality;
    cout << "Ingrese la region (20 carac. max): ";
    cin >> region;
    cout << "Ingrese el pie (10 carac. max): ";
    cin >> foot;
    cout << "Ingrese el numero de camiseta: ";
    cin >> shirt_number;
    cout << "Ingrese la altura: ";
    cin >> height;
    cout << "Ingrese el peso: ";
    cin >> weight;
    cout << "Ingrese la edad: ";
    cin >> age;
    t = clock();
    Record<char[30]> rec(name, shirt_number, toLower(team_name), toLower(league),toLower(nationality), toLower(region), height, weight, age, toLower(foot));
    int accesos = 0;
    seq.insert(rec, accesos);

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    cout << endl;
    printf("El programa tomo %f segundos en insertar el registro", time_taken);
    printf("\nEl programa tomo %d accesos a memoria secundaria", accesos);

    dump();
}

void buscar_registro_secuencial(Sequential<Record<char[30]>, string> &seq)
{
    cout << "\n\n----------Busqueda----------\n\n";
    cout << "Ingrese nombre a buscar: ";
    string key;
    clock_t t;

    cin >> key;
    int accesos = 0;
    t = clock();
    auto result = seq.search(toLower(key), accesos);
    if (result)
    {
        (*result).showRecord(1);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the  elapsed time
        cout << endl;
        printf("El programa tomo %f segundos en buscar el registro", time_taken);
        printf("\nEl programa tomo %d accesos a memoria secundaria", accesos);
    }
    else
    {
        cout << "No se encontro " << key << "\n";
    }
    dump();
}
void buscar_rango_registro_secuencial(Sequential<Record<char[30]>, string> &seq)
{
    cout << "\n\n----------Busqueda por rango----------\n\n";
    string key1, key2;
    clock_t t;
    cout << "Inserte registro inicial: ";
    cin >> key1;
    cout << "Inserte registro final: ";
    cin >> key2;
    if (key1 > key2)
    {
        auto t = key1;
        key1 = key2;
        key2 = t;
    }

    t = clock();
    auto result = seq.search(toLower(key1), toLower(key2));
    cout << "Resultados: " << result.size() << "\n";
    int cont = 1;
    for (auto r : result)
    {
        r.showRecord(cont++);
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the  elapsed time
    cout << endl;
    printf("El programa tomo %f segundos en buscar el rango de registros", time_taken);
    dump();
}

void eliminar_registro_secuencial(Sequential<Record<char[30]>, string> &seq)
{
    cout << "\n\n----------Eliminar----------\n\n";
    cout << "Ingrese codigo a eliminar: ";
    string key;
    cin >> key;
    if (seq.erase(toLower(key)))
    {
        cout << "Registro eliminado\n";
    }
    else
    {
        cout << "No se elimino\n";
    }
    dump();
}

void showData(Sequential<Record<char[30]>, string> &seq)
{
    seq.showRecords();
    dump();
}

#endif
