#ifndef LOL_MENU_H
#define LOL_MENU_H

#include "../Techniques/DynamicHash/extendibleHash.h"
#define NOMBRE_ARCHIVO_LOL "Lol.csv"
#include <stdio.h>
#include <time.h>

bool esEntero_r(string linea)
{
    bool esEntero = true;
    int longitud = linea.size();

    if (longitud == 1)
    {
        esEntero = false;
    }
    else if (longitud == 2 && !isdigit(linea[0]))
    {
        esEntero = false;
    }
    else
    {
        int indice = 1;
        if (linea[1] == '+' || linea[0] == '-')
        {
            indice = 2;
        }
        else
        {
            indice = 1;
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
void post_insertar_aleatorio_hash(ExtendibleHash<int> &eh);

void insertar_hash(ExtendibleHash<int> &eh)
{

    ifstream archivo(NOMBRE_ARCHIVO_LOL);
    string linea;
    clock_t t;
    char delimitador = ';';
    // Leemos la primea linea para descartarla, pues es el encabezado
    getline(archivo, linea);
    vector<RecordHash<int>> records;
    // Leemos todos las linea
    while (getline(archivo, linea))
    {
        stringstream stream(linea); //Convertir la cadena a un stream
        string championCode, championName, championClass, championRole, championTier, championScore, winRate, rolRate, pickRate, banRate, championTrend, championKda;
        //Extraer todos los valores
        getline(stream, championCode, delimitador);
        getline(stream, championName, delimitador);
        getline(stream, championClass, delimitador);
        getline(stream, championRole, delimitador);
        getline(stream, championTier, delimitador);
        getline(stream, championScore, delimitador);
        getline(stream, winRate, delimitador);
        getline(stream, rolRate, delimitador);
        getline(stream, pickRate, delimitador);
        getline(stream, banRate, delimitador);
        getline(stream, championTrend, delimitador);
        getline(stream, championKda, delimitador);

        
        RecordHash<int> temp(stoi(championCode), championName, championClass, championRole, championTier, stof(championScore), winRate, rolRate, pickRate, banRate, stof(championTrend), stof(championKda));
        records.push_back(temp);
    }

    t = clock();
    int accesos = eh.insertAll(records);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    cout << endl;
    printf("El programa toma %f segundos en insertar los %zu registros", time_taken, records.size());
    printf("\nEl programa toma %d accesos a memoria secundaria", accesos);
    dump();
    post_insertar_aleatorio_hash(eh);
}

void post_insertar_aleatorio_hash(ExtendibleHash<int> &eh)
{
    int input;
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

        cin >> input;
        repite = false;
    } while (repite);

    switch (input)
    {
    case 1:
        eh.showRecords();
        break;
    case 2:
        return;
        break;
    case 3:
        exit(-1);
        break;
    default:
        post_insertar_aleatorio_hash(eh);
        break;
    }
    dump();
}

void insertar_registro_hash(ExtendibleHash<int> &eh)
{
    
    cout << "\n\n----------Insertar----------\n\n";
    int championCode;
    string championName, championClass, championRole, championTier, winRate, rolRate, pickRate, banRate;
    float championScore, championTrend, championKda;
    clock_t t;
    cout << "Ingrese el codigo del campeon: ";
    cin >> championCode;
    cout << "Ingrese el nombre del campeon[max 15 char]: ";
    cin >> championName;
    cout << "Ingrese la clase del campeon[max ]: ";
    cin >> championClass;
    cout << "Ingrese el rol del campeon[max ]: ";
    cin >> championRole;
    cout << "Ingrese el tier del campeon[1 char (A,B,C,D,S)]: ";
    cin >> championTier;
    cout << "Ingrese el win rate del campeon: ";
    cin >> winRate;
    cout << "Ingrese el rol rate del campeon: ";
    cin >> rolRate;
    cout << "Ingrese el pick rate del campeon: ";
    cin >> pickRate;
    cout << "Ingrese el ban rate del campeon: ";
    cin >> banRate;
    cout << "Ingrese el score del campeon: ";
    cin >> championScore;
    cout << "Ingrese el trend del campeon: ";
    cin >> championTrend;
    cout << "Ingrese el kda del campeon: ";
    cin >> championKda;
    RecordHash<int> temp(championCode, championName, championClass, championRole, championTier, championScore, winRate, rolRate, pickRate, banRate, championTrend, championKda);

    RecordHash<int> rec(championCode, championName, championClass, championRole, championTier, championScore, winRate, rolRate, pickRate, banRate, championTrend, championKda);
    int accesos = 1;
    t = clock();
    eh.insert(rec, accesos);
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    cout << endl;
    printf("El programa tomo %f segundos en insertar el registro", time_taken);
    printf("\nEl programa tomo %d accesos a memoria secundaria", accesos);
    dump();
}

void buscar_registro_hash(ExtendibleHash<int> &eh)
{
    cout << "\n\n----------Busqueda----------\n\n";
    cout << "Ingrese codigo a buscar: ";
    int key;
    clock_t t;
    cin >> key;
    int accesos = 1;
    t = clock();
    auto result = eh.search(key, accesos);
    if (result)
    {
        (*result).showRecord(2);
        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
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

void buscar_rango_registro_hash(ExtendibleHash<int> &eh)
{
    cout << "\n\n----------Busqueda por rango----------\n\n";
    int key1, key2;
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
    auto result = eh.searchRange(key1, key2);
    cout << "Resultado: " << result.size() << "\n";
    int cont = 1;
    for (auto r : result)
    {
        r.showRecord(cont++);
    }
    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    cout << endl;
    printf("El programa tomo %f segundos en buscar el rango de registros", time_taken);
    dump();
}

void eliminar_registro_hash(ExtendibleHash<int> &eh)
{
    cout << "\n\n----------Eliminar----------\n\n";
    cout << "Ingrese codigo a eliminar: ";
    int key;
    cin >> key;
    if (eh.erase(key))
    {
        cout << "Registro eliminado\n";
    }
    else
    {
        cout << "No se elimino\n";
    }

    dump();
}

#endif