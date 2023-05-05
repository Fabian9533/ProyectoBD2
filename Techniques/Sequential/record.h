#ifndef RECORD_H
#define RECORD_H

#include "../lib.h"

using namespace std;

template <typename TKey>
class Record
{
    TKey key; 
    char player_name[30];
    int kills;
    int deaths;
    int wins;
    int losses;
    int xp;
    int headshots;
    int melee_kills;
    int games_played;

    long next = -1;
    char file = 'd';

public:
    Record()
    {
        string player_name = "No name";
        
        strcpy(this->player_name, player_name.c_str());
        this->key = 0;
        this->kills = 0;
        this->deaths = 0;
        this->wins = 0;
        this->losses = 0;
        this->xp = 0;
        this->headshots = 0;
        this->melee_kills = 0;
        this->games_played = 0;
        this->next = -1;
        char file = 'd';
    }
    Record(int key, string player_name, int kills, int deaths, int wins, int losses, int xp, int headshots, int melee_kills, int games_played)
    {
        this->key = key;
        strcpy(this->player_name, player_name.c_str());
        this->kills = kills;
        this->deaths = deaths;
        this->wins = wins;
        this->losses = losses;
        this->xp = xp;
        this->headshots = headshots;
        this->melee_kills = melee_kills;
        this->games_played = games_played;
        this->next = -1;
        char file = 'd';
    }
    void setData(int key, string player_name, int kills, int deaths, int wins, int losses, int xp, int headshots, int melee_kills, int games_played)
    {
        this->key = key;
        strcpy(this->player_name, player_name.c_str());
        this->kills = kills;
        this->deaths = deaths;
        this->wins = wins;
        this->losses = losses;
        this->xp = xp;
        this->headshots = headshots;
        this->melee_kills = melee_kills;
        this->games_played = games_played;
        this->next = -1;
        char file = 'd';
    }

    void showData()
    {
        cout << "Key: " << key << "\n";
        cout << "Player Name: " << player_name << "\n";
        cout << "Kills: " << kills << "\n";
        cout << "Deaths: " << deaths << "\n";
        cout << "Wins: " << wins << "\n";
        cout << "Losses: " << losses << "\n";
        cout << "XP: " << xp << "\n";
        cout << "Headshots: " << headshots << "\n";
        cout << "Melee Skills: " << melee_kills << "\n";
        cout << "Games Played: " << games_played << "\n";
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
        this->key = a.key;

        for (int i = 0; i < 30; i++)
            this->player_name[i] = a.player_name[i];
            
        this->kills = a.kills;
        this->deaths = a.deaths;
        this->wins = a.wins;
        this->losses = a.losses;
        this->xp = a.xp;
        this->headshots = a.headshots;
        this->melee_kills = a.melee_kills;
        this->games_played = a.games_played;
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
            cout << setw(5) << "N°" << setw(5) << "Key" << setw(30) << "Player Name" << setw(6) << "Kills" << setw(6) << "Deaths" << setw(6) << "Wins" << setw(6) << "Losses" << setw(10) << "XP" << setw(6) << "Headshots" << setw(6) << "Melee Kills" << setw(6) << "Games Played"
                 << "\n";
        }
        cout << setw(5) << cont << setw(5) << key <<setw(30) << player_name << setw(6) << kills << setw(6) << deaths << setw(6) << wins << setw(6) << losses << setw(10) << xp << setw(6) << headshots << setw(6) << melee_kills << setw(6) << games_played << "\n";
    }
};

#endif //RECORD.H
