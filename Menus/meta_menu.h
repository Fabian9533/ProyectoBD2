#ifndef META_MENU_H
#define META_MENU_H

#include "../Techniques/DynamicHash/extendibleHash.h"
#define NOMBRE_ARCHIVO_META "VideojuegosMetacritic.csv"
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

    ifstream archivo(NOMBRE_ARCHIVO_META);
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
        string gameName, gamePlatform, releaseDate, gameDeveloper, gameGenre, gamePlayers, gameScore, userScore, gameCritics, gameUsers;
        //Extraer todos los valores

        getline(stream, gameName, delimitador);
        getline(stream, gamePlatform, delimitador);
        getline(stream, releaseDate, delimitador);
        getline(stream, gameDeveloper, delimitador);
        getline(stream, gameGenre, delimitador);
        getline(stream, gamePlayers, delimitador);
        getline(stream, gameScore, delimitador);
        getline(stream, userScore, delimitador);
        getline(stream, gameCritics, delimitador);
        getline(stream, gameUsers, delimitador);
       
        RecordHash<int> temp(gameName, gamePlatform, releaseDate, gameDeveloper, gameGenre, gamePlayers, stoi(gameScore), stof(userScore), stoi(gameCritics), stoi(gameUsers));
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
        cout << "Se insertaron los datos exitosamente" << endl;
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
    int gameScore, gameCritics, gameUsers;
    string gameName, gamePlatform, releaseDate, gameDeveloper, gameGenre, gamePlayers;
    float userScore;
    clock_t t;
    cout << "Ingrese el nombre: ";
    cin >> gameName;
    cout << "Ingrese la plataforma: ";
    cin >> gamePlatform;
    cout << "Ingrese el dia de lanzamiento: ";
    cin >> releaseDate;
    cout << "Ingrese el desarrollador: ";
    cin >> gameDeveloper;
    cout << "Ingrese el genero del juego: ";
    cin >> gameGenre;
    cout << "Ingrese el estilo de juego(multiplcayer o no/ 1 o dos jugadores): ";
    cin >> gamePlayers;
    cout << "Ingrese el puntaje del juego: ";
    cin >> gameScore;
    cout << "Ingrese el numero de criticas: ";
    cin >> gameCritics;
    cout << "Ingrese el numero de usuarios: ";
    cin >> gameUsers;
    cout << "Ingrese el score del campeon: ";
    cin >> userScore;
    cout << "Ingrese el numero de usuarios: ";

    RecordHash<int> temp(gameName, gamePlatform, releaseDate, gameDeveloper, gameGenre, gamePlayers, gameScore, userScore, gameCritics, gameUsers);

    RecordHash<int> rec(gameName, gamePlatform, releaseDate, gameDeveloper, gameGenre, gamePlayers, gameScore, userScore, gameCritics, gameUsers);
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