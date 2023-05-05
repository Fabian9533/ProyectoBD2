#ifndef RECORD_HASH_H
#define RECORD_HASH_H

#include "../lib.h"

template <typename TKey>
class RecordHash
{
    TKey key; //Rank
    char gameName[80];
    char gamePlatform[20]; 
    char gameGenre[30];
    char gamePublisher[30];
    int gameYear;
    float naSales;
    float euSales;
    float jpSales;
    float otherSales;
    float globalSales;

public:
    RecordHash()
    {
        this->key = 0;
        string gameName = "gameName";
        strcpy(this->gameName, gameName.c_str());
        string gamePlatform = "gamePlatform";
        strcpy(this->gamePlatform, gamePlatform.c_str());
        string gameGenre = "gameGenre";
        strcpy(this->gameGenre, gameGenre.c_str());
        string gamePublisher = "gamePublisher";
        this->gameYear = 0;
        this->naSales = 0.0;
        this->euSales = 0.0;
        this->jpSales = 0.0;
        this->otherSales = 0.0;
        this->globalSales = 0.0;
    }

    RecordHash(TKey key, string gameName, string gamePlatform, string gameGenre, string gamePublisher, int gameYear,
                float naSales, float euSales, float jpSales, float otherSales, float globalSales)
    {
        this->key = key;
        strcpy(this->gameName, gameName.c_str());
        strcpy(this->gamePlatform, gamePlatform.c_str());
        strcpy(this->gameGenre, gameGenre.c_str());
        strcpy(this->gamePublisher, gamePublisher.c_str());
        this->gameYear = gameYear;
        this->naSales = naSales;
        this->euSales = euSales;
        this->jpSales = jpSales;
        this->otherSales = otherSales;
        this->globalSales = globalSales;
    }

    void setData(TKey key, string gameName, string gamePlatform, string gameGenre, string gamePublisher, int gameYear,
                float naSales, float euSales, float jpSales, float otherSales, float globalSales)
    {
        this->key = key;
        strcpy(this->gameName, gameName.c_str());
        strcpy(this->gamePlatform, gamePlatform.c_str());
        strcpy(this->gameGenre, gameGenre.c_str());
        strcpy(this->gamePublisher, gamePublisher.c_str());
        this->gameYear = gameYear;
        this->naSales = naSales;
        this->euSales = euSales;
        this->jpSales = jpSales;
        this->otherSales = otherSales;
        this->globalSales = globalSales;
    }
    
    void setData(TKey key)
    {
        this->key = key;
        string gameName = "gameName", gamePlatform = "gamePlatform", gameGenre = "gameGenre", gamePublisher = "gamePublisher";
        strcpy(this->gameName, gameName.c_str());
        strcpy(this->gamePlatform, gamePlatform.c_str());
        strcpy(this->gameGenre, gameGenre.c_str());
        strcpy(this->gamePublisher, gamePublisher.c_str());
        this->gameYear = 0.0;
        this->naSales = 0.0;
        this->euSales = 0.0;
        this->jpSales = 0.0;
        this->otherSales = 0.0;
        this->globalSales = 0.0;
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
        char gameName[80];
        char gamePlatform[20]; 
        char gameGenre[30];
        char gamePublisher[30];
        int gameYear;
        float naSales;
        float euSales;
        float jpSales;
        float otherSales;
        float globalSales;

        this->key = a.key;
        for (int i = 0; i < 15; i++)
            this->gameName[i] = a.gameName[i];
        for (int i = 0; i < 8; i++)
            this->gamePlatform[i] = a.gamePlatform[i];
        for (int i = 0; i < 10; i++)
            this->gameGenre[i] = a.gameGenre[i];
        for (int i = 0; i < 1; i++)
            this->gamePublisher[i] = a.gamePublisher[i];
        this->gameYear = a.gameYear;
        this->naSales = a.naSales;
        this->euSales = a.euSales;
        this->jpSales = a.jpSales;
        this->otherSales = a.otherSales;
        this->globalSales = a.globalSales;
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
            << gameGenre << setw(6) << gamePublisher << setw(7) << gameYear << setw(7) << naSales << setw(7)
            << euSales << setw(7) << jpSales << setw(7) << otherSales << setw(7) << globalSales << "\n";
    }
};

#endif //RECORD_HASH.H
