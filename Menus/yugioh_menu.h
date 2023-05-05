#ifndef YUGIOH_MENU_H
#define YUGIOH_MENU_H

#include "../Techniques/Sequential/sequential.h"
#include <stdio.h>
#include <time.h>
#define NOMBRE_ARCHIVO_YUGIOH "Yu-Gi-Oh-Normal_Monsters.csv"

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

    ifstream archivo(NOMBRE_ARCHIVO_YUGIOH);
    string linea;
    char delimitador = ',';
    // Leemos la primea linea para descartarla, pues es el encabezado
    getline(archivo, linea);
    vector<Record<char[30]>> records;

    // Leemos todos las linea
    clock_t t;

    while (getline(archivo, linea))
    {
        int level = 0;
        int attack = 0;
        int defense = 0;

        stringstream stream(linea); //Convertir la cadena a un stream
        string Name, Attributes, SubType, Level, Attack, Defense;
        //Extraer todos los valores
        getline(stream, Name, delimitador);
        getline(stream, Attributes, delimitador);
        getline(stream, SubType, delimitador);
        getline(stream, Attack, delimitador);
        getline(stream, Defense, delimitador);

        stringstream _level(Level);
        stringstream _attack(Attack);
        stringstream _defense(Defense);

        _level >> level;
        _attack >> attack;
        _defense >> defense;

        Record<char[30]> temp(Name, Attributes, SubType, level, attack, defense);

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
    string nombre;
    string atributo;
    string subtipo;
    clock_t t;
    int nivel, ataque, defensa;

    cout << "Ingrese el Nombre (30 carac. max): ";
    cin >> nombre;
    cout << "Ingrese el tipo (8 carac. max): ";
    cin >> atributo;
    cout << "Ingrese el nivel: ";
    cin >> nivel;
    cout << "Ingrese la ataque: ";
    cin >> ataque;
    cout << "Ingrese la defensa: ";
    cin >> defensa;
    t = clock();
    Record<char[30]> rec(toLower(nombre), toLower(atributo),toLower(subtipo), nivel, ataque, defensa);
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

 
vector<string> split_query(const string& query) {
    vector<string> tokens;
    stringstream ss(query);
    string token;
    while (getline(ss, token, ' ')) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}


void insertar_parser_secuencial(Sequential<Record<char[30]>, string> &seq){
    string query;
    cout << "Ingrese la sentencia SQL: ";
    getline(cin, query);
    vector<string> tokens = split_query(query);
    if (tokens[0] == "select"){
        if (tokens[1] == "*" && tokens[2] == "from" && tokens[4] != "where"){
            seq.showRecords();
            dump();
        } else {
            string nombre;
            int accesos = 0;
            //encontrar el valor de nombre entre las comillas simple de la sentencia/query y pasarlo a la variable nombre
            for (int i = 0; i < query.size(); i++){
                if (query[i] == '\''){
                    for (int j = i+1; j < query.size(); j++){
                        if (query[j] == '\''){
                            nombre = query.substr(i+1, j-i-1);
                            break;
                        }
                    }
                    break;
                }
            }

            cout << "Nombre: " << nombre << "\n";

            auto result = seq.search(toLower(nombre), accesos);
            if (result)
            {
                (*result).showRecord(1);
                cout << "Accesos a memoria secundaria: " << accesos << endl;
            }
            else
            {
                cout << "No se encontro " << nombre << "\n";
            }
            dump();
        }
    } else if (tokens[0] == "select" && tokens[6] == "between"){
        string key1, key2;
        clock_t t;
        key1 = tokens[7];
        key2 = tokens[9];
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
    } else if (tokens[0] == "insert") {
        // Extraer los valores necesarios de la consulta
        size_t index1 = query.find("(");
        size_t index2 = query.find(")");
        string columns_str = query.substr(index1 + 1, index2 - index1 - 1);
        string values_str = query.substr(query.find("(", index2) + 1, query.find(")", index2) - query.find("(", index2) - 1);

        string subtipo;
        int nivel, ataque, defensa;

        vector<string> column_names;
        stringstream ss(columns_str);
        string column_name;
        while (getline(ss, column_name, ',')) {
            column_names.push_back(column_name);
        }

        vector<string> values;
        stringstream ss2(values_str);
        string value;
        while (getline(ss2, value, ',')) {
            values.push_back(value);
        }
        clock_t t;
        t = clock();
        nivel = stoi(values[2]);
        ataque = stoi(values[3]);
        defensa = stoi(values[4]);
        Record<char[30]> rec(toLower(values[0]), toLower(values[1]),toLower(subtipo), nivel, ataque, defensa);
        int accesos = 0;
        seq.insert(rec, accesos);

        t = clock() - t;
        double time_taken = ((double)t) / CLOCKS_PER_SEC; // calculate the elapsed time
        cout << endl;
        printf("El programa tomo %f segundos en insertar el registro", time_taken);
        printf("\nEl programa tomo %d accesos a memoria secundaria", accesos);

        dump();
    } else if (tokens[0] == "delete") {
        string nombre = tokens[2];
        int accesos = 0;
        seq.erase(toLower(nombre));
        dump();
    } else {
        cout << "Sentencia no reconocida\n";
        dump();
    }
}

#endif