#ifndef RECORD_H
#define RECORD_H

#include "../lib.h"

using namespace std;

template <typename TKey>
class Record
{
    TKey key; //name[30]
    char attributes[6];
    char subtype[12];
    int level;
    int attack;
    int defense;

    long next = -1;
    char file = 'd';

public:
    Record()
    {
        string name = "No name";
        string attributes = "No attributes";
        string subtype = "No subtype";
        
        strcpy(this->key, name.c_str());
        strcpy(this->attributes, attributes.c_str());
        strcpy(this->subtype, subtype.c_str());
        this->level = 0;
        this->attack = 0;
        this->defense = 0;
        this->next = -1;
        char file = 'd';
    }
    Record(string name, string attributes, string subtype, int level, int attack, int defense)
    {
        strcpy(this->key, name.c_str());
        strcpy(this->attributes, attributes.c_str());
        strcpy(this->subtype, subtype.c_str());
        this->level = level;
        this->attack = attack;
        this->defense = defense;
        this->next = -1;
        char file = 'd';
    }
    void setData(string name, string attributes, string subtype, int level, int attack, bool defense)
    {
        strcpy(this->key, name.c_str());
        strcpy(this->attributes, attributes.c_str());
        strcpy(this->subtype, subtype.c_str());
        this->level = level;
        this->attack = attack;
        this->defense = defense;
        this->next = -1;
        char file = 'd';
    }

    void showData()
    {
        cout << "Key: " << key << "\n";
        cout << "Atributos: " << attributes << "\n";
        cout << "Sub-Tipo: " << subtype << "\n";
        cout << "Level: " << level << "\n";
        cout << "Puntos de Ataque: " << attack << "\n";
        cout << "Puntos de Defensa: " << defense << "\n";
        cout << "Next : " << next << "\n";
        cout << "NextFile : " << file << "\n\n";
    }
    void setNext(long _next, char _file)
    {
        next = _next;
        file = _file;
    }
    long getNext()
    {
        return next;
    }
    char getFile()
    {
        return file;
    }
    string getKey()
    {
        return string(key);
    }
    Record &operator=(const Record &a)
    {
        for (int i = 0; i < 30; i++)
            this->key[i] = a.key[i];

        for (int i = 0; i < 6; i++)
            this->attributes[i] = a.attributes[i];
            
        for (int i = 0; i < 12; i++)
            this->subtype[i] = a.subtype[i];

        this->level = a.level;
        this->attack = a.attack;
        this->defense = a.defense;
        this->next = a.next;
        this->file = a.file;
        return *this;
    }
    bool operator<(const Record &a) { return string(this->key) < string(a.key); }
    bool operator>(const Record &a) { return string(this->key) > string(a.key); }
    bool operator<=(const Record &a) { return string(this->key) <= string(a.key); }
    bool operator>=(const Record &a) { return string(this->key) >= string(a.key); }
    bool operator==(const Record &a) { return string(this->key) == string(a.key); }
    bool operator!=(const Record &a) { return string(this->key) != string(a.key); }

    void showRecord(int cont)
    {
        if (cont == 1)
        {
            cout << setw(5) << "N°" << setw(30) << "Key" << setw(8) << "Attributes" << setw(13) << "SubType" << setw(10) << "Level" << setw(10) << "Attack" << setw(10) << "Defense"
                 << "\n";
        }
        cout << setw(5) << cont << setw(30) << key <<setw(8) << attributes << setw(13) << subtype << setw(10) << level << setw(10) << attack << setw(10) << defense << "\n";
    }
};

#endif //RECORD.H