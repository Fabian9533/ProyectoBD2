#ifndef RECORD_H
#define RECORD_H

#include "../lib.h"

using namespace std;

template <typename TKey>
class Record
{
    TKey key; //name[30]
    int shirt_number;
    char team_name[20];
    char league[30];
    char nationality[20];
    char region[20];
    int height;
    int weight;
    int age;
    char foot[10];

    long next = -1;
    char file = 'd';

public:
    Record()
    {
        string name = "No name";
        string team_name = "No team_name";
        string league = "No league";
        string nationality = "No nationality";
        string region = "No region";
        string foot = "No foot";
        
        strcpy(this->key, name.c_str());
        strcpy(this->team_name, team_name.c_str());
        strcpy(this->league, league.c_str());
        strcpy(this->nationality, nationality.c_str());
        strcpy(this->region, region.c_str());
        strcpy(this->foot, foot.c_str());
        this->shirt_number = 0;
        this->height = 0;
        this->weight = 0;
        this->age = 0;
        this->next = -1;
        char file = 'd';
    }
    Record(string name, int shirt_number, string team_name, string league, string nationality, string region, int height, int weight, int age, string foot)
    {
        strcpy(this->key, name.c_str());
        strcpy(this->team_name, team_name.c_str());
        strcpy(this->league, league.c_str());
        strcpy(this->nationality, nationality.c_str());
        strcpy(this->region, region.c_str());
        strcpy(this->foot, foot.c_str());
        this->shirt_number = shirt_number;
        this->height = height;
        this->weight = weight;
        this->age = age;
        this->next = -1;
        char file = 'd';
    }
    void setData(string name, int shirt_number, string team_name, string league, string nationality, string region, int height, int weight, int age, string foot)
    {
        strcpy(this->key, name.c_str());
        strcpy(this->team_name, team_name.c_str());
        strcpy(this->league, league.c_str());
        strcpy(this->nationality, nationality.c_str());
        strcpy(this->region, region.c_str());
        strcpy(this->foot, foot.c_str());
        this->shirt_number = shirt_number;
        this->height = height;
        this->weight = weight;
        this->age = age;
        this->next = -1;
        char file = 'd';
    }

    void showData()
    {
        cout << "Key: " << key << "\n";
        cout << "Shirt Number: " << shirt_number << "\n";
        cout << "Team Name: " << team_name << "\n";
        cout << "League: " << league << "\n";
        cout << "Nationality: " << nationality << "\n";
        cout << "Region: " << region << "\n";
        cout << "Height: " << height << "\n";
        cout << "Weight: " << weight << "\n";
        cout << "Age: " << age << "\n";
        cout << "Foot: " << foot << "\n";
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

        for (int i = 0; i < 20; i++)
            this->team_name[i] = a.team_name[i];
            
        for (int i = 0; i < 30; i++)
            this->league[i] = a.league[i];
        
        for (int i = 0; i < 20; i++)
            this->nationality[i] = a.nationality[i];
        
        for (int i = 0; i < 20; i++)
            this->region[i] = a.region[i];
        
        for (int i = 0; i < 10; i++)
            this->foot[i] = a.foot[i];

        this->shirt_number = a.shirt_number;
        this->height = a.height;
        this->weight = a.weight;
        this->age = a.age;
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
            cout << setw(5) << "N°" << setw(30) << "Key" << setw(10) << "Shirt Number" << setw(22) << "Team Name" << setw(33) << "League" << setw(22) << "Nationality" << setw(22) << "Region" << setw(10) << "Height" << setw(10) << "Weight" << setw(10) << "Age" << setw(12) << "Foot"
                 << "\n";
        }
        cout << setw(5) << cont << setw(30) << key <<setw(10) << shirt_number << setw(22) << team_name << setw(33) << league << setw(22) << nationality << setw(22) << region << setw(10) << height << setw(10) << weight << setw(10) << age << setw(12) << foot << "\n";
    }
};

#endif //RECORD.H
