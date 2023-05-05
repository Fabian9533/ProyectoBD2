#ifndef RS6_MENU_H
#define RS6_MENU_H

#include "../Techniques/Sequential/sequential.h"
#include <stdio.h>
#include <time.h>
#define NOMBRE_ARCHIVO_RS6 "rs6_clean.csv"

using namespace std;

void post_insertar_aleatorio(Sequential<Record<int>, string> &seq);

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

void insertar_secuencial(Sequential<Record<int>, string> &seq)
{

    ifstream archivo(NOMBRE_ARCHIVO_RS6);
    string linea;
    char delimitador = ',';
    // Leemos la primea linea para descartarla, pues es el encabezado
    getline(archivo, linea);
    vector<Record<int>> records;

    // Leemos todos las linea
    clock_t t;

    while (getline(archivo, linea))
    {
        int id = 0;
        int kills = 0;
        int deaths = 0;
        int wins = 0;
        int losses = 0;
        int xp = 0;
        int headshots = 0;
        int melee_kills = 0;
        int games_played = 0;

        stringstream stream(linea); //Convertir la cadena a un stream
        string Id, Player_name, Kills, Deaths, Wins, Losses, Xp, Headshots, Melee_kills, Games_played;
        //Extraer todos los valores

        getline(stream, Id, delimitador);

        getline(stream, Player_name, delimitador);
        getline(stream, Kills, delimitador);
        getline(stream, Deaths, delimitador);
        getline(stream, Wins, delimitador);
        getline(stream, Losses, delimitador);
        getline(stream, Xp, delimitador);
        getline(stream, Headshots, delimitador);
        getline(stream, Melee_kills, delimitador);
        getline(stream, Games_played, delimitador);

        stringstream _id(Id);
        stringstream _kills(Kills);
        stringstream _deaths(Deaths);
        stringstream _wins(Wins);
        stringstream _losses(Losses);
        stringstream _xp(Xp);
        stringstream _heahshots(Headshots);
        stringstream _meleekills(Melee_kills);
        stringstream _gamesplayed(Games_played);

        _id >> Id;
        _kills >> Kills;
        _deaths >> Deaths;
        _wins >> Wins;
        _losses >> Losses;
        _xp >> Xp;
        _heahshots >> Headshots;
        _meleekills >> Melee_kills;
        _gamesplayed >> Games_played;
        

        Record<int> temp(id, Player_name, kills, deaths, wins, losses, xp , headshots, melee_kills, games_played);
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

void post_insertar_aleatorio(Sequential<Record<int>, string> &seq)
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
void insertar_registro_secuencial(Sequential<Record<int>, string> &seq)
{
    cout << "\n\n----------Insertar----------\n\n";
    string player_name;
    clock_t t;
    int Id, Kills, Deaths, Wins, Losses, Xp, Headshots, Melee_kills, Games_played;


    cout << "Ingrese el id: ";
    cin >> Id;
    cout << "Ingrese el Nombre del jugador (30 carac. max): ";
    cin >> player_name;
    cout << "Ingrese el numero de asesinatos: ";
    cin >> Kills;
    cout << "Ingrese el numero de muertes: ";
    cin >> Deaths;
    cout << "Ingrese el numero de partidas ganadas: ";
    cin >> Wins;
    cout << "Ingrese el numero de partidas perdidas: ";
    cin >> Losses;
    cout << "Ingrese la experiencia: ";
    cin >> Xp;
    cout << "Ingrese el numero de muertes a melee: ";
    cin >> Melee_kills;
    cout << "Ingrese el numero de partidas jugadas: ";
    cin >> Games_played;
   
    t = clock();
    Record<int> rec(Id, toLower(player_name),Kills, Deaths, Wins, Losses, Xp, Headshots, Melee_kills, Games_played);
    int accesos = 0;
    seq.insert(rec, accesos);

    t = clock() - t;
    double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
    cout << endl;
    printf("El programa tomo %f segundos en insertar el registro", time_taken);
    printf("\nEl programa tomo %d accesos a memoria secundaria", accesos);

    dump();
}

void buscar_registro_secuencial(Sequential<Record<int>, string> &seq)
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
void buscar_rango_registro_secuencial(Sequential<Record<int>, string> &seq)
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

void eliminar_registro_secuencial(Sequential<Record<int>, string> &seq)
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

void showData(Sequential<Record<int>, string> &seq)
{
    seq.showRecords();
    dump();
}

#endif
