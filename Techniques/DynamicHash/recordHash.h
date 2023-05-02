#ifndef RECORD_HASH_H
#define RECORD_HASH_H

#include "../lib.h"

template <typename TKey>
class RecordHash
{
    TKey key;
    char gameName[60];
    char gamePlatform[20]; 
    char releaseDate[20];
    char gameDeveloper[50];
    char gameGenre[100];
    char gamePlayers[30];
    int gameScore;
    float userScore;
    int gameCritics;
    int gameUsers;

public:
    RecordHash()
    {
        this->key = 0;
        string gameName = "gameName";
        strcpy(this->gameName, gameName.c_str());
        string gamePlatform = "gamePlatform";
        strcpy(this->gamePlatform, gamePlatform.c_str());
        string releaseDate = "releaseDate";
        strcpy(this->releaseDate, releaseDate.c_str());
        string gameDeveloper = "gameDeveloper";
        strcpy(this->gameDeveloper, gameDeveloper.c_str());
        string gameGenre = "gameGenre";
        strcpy(this->gameGenre, gameGenre.c_str());
        string gamePlayers = "gamePlayers";
        strcpy(this->gamePlayers, gamePlayers.c_str());
        this->gameScore = 0;
        this->userScore = 0.0;
        this->gameCritics = 0;
        this->gameUsers = 0;
    }

    RecordHash(TKey key, string gameName, string gamePlatform, string releaseDate, string gameDeveloper,
                int gameScore, string gameGenre, string gamePlayers, float userScore, int gameCritics, int gameUsers)
    {
        this->key = key;
        strcpy(this->gameName, gameName.c_str());
        strcpy(this->gamePlatform, gamePlatform.c_str());
        strcpy(this->releaseDate, releaseDate.c_str());
        strcpy(this->gameDeveloper, gameDeveloper.c_str());
        strcpy(this->gameGenre, gameGenre.c_str());
        strcpy(this->gamePlayers, gamePlayers.c_str());
        this->gameScore = gameScore;
        this->userScore = userScore;
        this->gameCritics = gameCritics;
        this->gameUsers = gameUsers;
    }

    void setData(TKey key, string gameName, string gamePlatform, string releaseDate, string gameDeveloper, 
                 string gameGenre, string gamePlayers, int gameScore, float userScore, int gameCritics, int gameUsers)
    {
        this->key = key;
        strcpy(this->gameName, gameName.c_str());
        strcpy(this->gamePlatform, gamePlatform.c_str());
        strcpy(this->releaseDate, releaseDate.c_str());
        strcpy(this->gameDeveloper, gameDeveloper.c_str());
        strcpy(this->gameGenre, gameGenre.c_str());
        strcpy(this->gamePlayers, gamePlayers.c_str());
        this->gameScore = gameScore;
        this->userScore = userScore;
        this->gameCritics = gameCritics;
        this->gameUsers = gameUsers;
    }
    
    void setData(TKey key)
    {
        this->key = key;
        string gameName = "gameName", gamePlatform = "gamePlatform", releaseDate = "releaseDate",
               gameDeveloper = "gameDeveloper", gameGenre = "gameGenre", gamePlayers = "gamePlayers";
        strcpy(this->gameName, gameName.c_str());
        strcpy(this->gamePlatform, gamePlatform.c_str());
        strcpy(this->releaseDate, releaseDate.c_str());
        strcpy(this->gameDeveloper, gameDeveloper.c_str());
        strcpy(this->gameGenre, gameGenre.c_str());
        strcpy(this->gamePlayers, gamePlayers.c_str());
        this->gameScore = 0;
        this->userScore = 0.0;
        this->gameCritics = 0;
        this->gameUsers = 0;
    }

    void showData()
    {
        cout << "\tKey: " << key << "\n";
    }
    TKey getKey()
    {
        return key;
    }

    RecordHash &operator=(const RecordHash &a)
    {
        TKey key;
        char gameName[60];
        char gamePlatform[20]; 
        char releaseDate[20];
        char gameDeveloper[50];
        char gameGenre[100];
        char gamePlayers[30];
        int gameScore;
        float userScore;
        int gameCritics;
        int gameUsers;

        this->key = a.key;
        for (int i = 0; i < 60; i++)
            this->gameName[i] = a.gameName[i];
        for (int i = 0; i < 20; i++)
            this->gamePlatform[i] = a.gamePlatform[i];
        for (int i = 0; i < 20; i++)
            this->releaseDate[i] = a.releaseDate[i];
        for (int i = 0; i < 50; i++)
            this->gameDeveloper[i] = a.gameDeveloper[i];
        for (int i = 0; i < 100; i++)
            this->gameGenre[i] = a.gameGenre[i];
        for (int i = 0; i < 30; i++)
            this->gamePlayers[i] = a.gamePlayers[i];
        this->gameScore = a.gameScore;
        this->userScore = a.userScore;
        this->gameCritics = a.gameCritics;
        this->gameUsers = a.gameUsers;
        return *this;
    }
    bool operator<(const RecordHash &a) { return this->key < a.key; }
    bool operator>(const RecordHash &a) { return this->key > a.key; }
    bool operator<=(const RecordHash &a) { return this->key <= a.key; }
    bool operator>=(const RecordHash &a) { return this->key >= a.key; }
    bool operator==(const RecordHash &a) { return this->key == a.key; }
    bool operator!=(const RecordHash &a) { return this->key != a.key; }

    void showRecord(int cont)
    {
        cout << setw(5) << cont << setw(5) << key << setw(20) << gameName << setw(13) << gamePlatform << setw(15)
             << releaseDate << setw(6) << gameDeveloper << setw(7) << gameScore << setw(12) << gameGenre << setw(12)
             << gamePlayers << setw(7) << userScore << setw(7) << gameCritics << "\n";
    }
};

#endif //RECORD_HASH.H