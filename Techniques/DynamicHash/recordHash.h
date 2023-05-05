#ifndef RECORD_HASH_H
#define RECORD_HASH_H

#include "../lib.h"

template <typename TKey>
class RecordHash
{
    TKey key;
    char championName[15];
    char championClass[8]; 
    char championRole[10];
    char championTier[1];
    char championwinRate[7];
    char championrolRate[7];
    char championpickRate[7];
    char championbanRate[7];
    float championScore;
    float championTrend;
    float championKda;

public:
    RecordHash()
    {
        this->key = 0;
        string championName = "championName";
        strcpy(this->championName, championName.c_str());
        string championClass = "championClass";
        strcpy(this->championClass, championClass.c_str());
        string championRole = "championRole";
        strcpy(this->championRole, championRole.c_str());
        string championTier = "championTier";
        strcpy(this->championTier, championTier.c_str());
        string championwinRate = "championwinRate";
        strcpy(this->championwinRate, championwinRate.c_str());
        string championrolRate = "championrolRate";
        strcpy(this->championrolRate, championrolRate.c_str());
        string championpickRate = "championpickRate";
        strcpy(this->championpickRate, championpickRate.c_str());
        string championbanRate = "championbanRate";
        strcpy(this->championbanRate, championbanRate.c_str());
        this->championScore = 0.0;
        this->championTrend = 0.0;
        this->championKda = 0.0;
    }

    RecordHash(TKey key, string championName, string championClass, string championRole, string championTier, float championScore, string championwinRate, string championrolRate, string championpickRate, string championbanRate, float championTrend, float championKda)
    {
        this->key = key;
        strcpy(this->championName, championName.c_str());
        strcpy(this->championClass, championClass.c_str());
        strcpy(this->championRole, championRole.c_str());
        strcpy(this->championTier, championTier.c_str());
        strcpy(this->championwinRate, championwinRate.c_str());
        strcpy(this->championrolRate, championrolRate.c_str());
        strcpy(this->championpickRate, championpickRate.c_str());
        strcpy(this->championbanRate, championbanRate.c_str());
        this->championScore = championScore;
        this->championTrend = championTrend;
        this->championKda = championKda;
    }

    void setData(TKey key, string championName, string championClass, string championRole, string championTier, string championwinRate, string championrolRate, string championpickRate, string championbanRate, float championScore, float championTrend, float championKda)
    {
        this->key = key;
        strcpy(this->championName, championName.c_str());
        strcpy(this->championClass, championClass.c_str());
        strcpy(this->championRole, championRole.c_str());
        strcpy(this->championTier, championTier.c_str());
        strcpy(this->championwinRate, championwinRate.c_str());
        strcpy(this->championrolRate, championrolRate.c_str());
        strcpy(this->championpickRate, championpickRate.c_str());
        strcpy(this->championbanRate, championbanRate.c_str());
        this->championScore = championScore;
        this->championTrend = championTrend;
        this->championKda = championKda;
    }
    
    void setData(TKey key)
    {
        this->key = key;
        string championName = "championName", championClass = "championClass", championRole = "championRole", championTier = "championTier", championwinRate = "championwinRate", championrolRate = "championrolRate", championpickRate = "championpickRate", championbanRate = "championbanRate";
        strcpy(this->championName, championName.c_str());
        strcpy(this->championClass, championClass.c_str());
        strcpy(this->championRole, championRole.c_str());
        strcpy(this->championTier, championTier.c_str());
        strcpy(this->championwinRate, championwinRate.c_str());
        strcpy(this->championrolRate, championrolRate.c_str());
        strcpy(this->championpickRate, championpickRate.c_str());
        strcpy(this->championbanRate, championbanRate.c_str());
        this->championScore = 0.0;
        this->championTrend = 0.0;
        this->championKda = 0.0;
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
        char championName[15];
        char championClass[8];
        char championRole[10];
        char championTier[1];
        char championwinRate[7];
        char championrolRate[7];
        char championpickRate[7];
        char championbanRate[7];
        float championScore;
        float championTrend;
        float championKda;

        this->key = a.key;
        for (int i = 0; i < 15; i++)
            this->championName[i] = a.championName[i];
        for (int i = 0; i < 8; i++)
            this->championClass[i] = a.championClass[i];
        for (int i = 0; i < 10; i++)
            this->championRole[i] = a.championRole[i];
        for (int i = 0; i < 1; i++)
            this->championTier[i] = a.championTier[i];
        for (int i = 0; i < 7; i++)
            this->championwinRate[i] = a.championwinRate[i];
        for (int i = 0; i < 7; i++)
            this->championrolRate[i] = a.championrolRate[i];
        for (int i = 0; i < 7; i++)
            this->championpickRate[i] = a.championpickRate[i];
        for (int i = 0; i < 7; i++)
            this->championbanRate[i] = a.championbanRate[i];
        this->championScore = a.championScore;
        this->championTrend = a.championTrend;
        this->championKda = a.championKda;
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
        cout << setw(5) << cont << setw(5) << key << setw(20) << championName << setw(13) << championClass << setw(15) << championRole << setw(6) << championTier << setw(7) << championScore << setw(12) << championwinRate << setw(12) << championrolRate << setw(12) << championpickRate << setw(12) << championbanRate << setw(7) << championTrend << setw(7) << championKda << "\n";
    }
};

#endif //RECORD_HASH.H
