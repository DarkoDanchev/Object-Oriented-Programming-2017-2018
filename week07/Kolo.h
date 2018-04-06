#pragma once

class Kolo
{
private:
    char* spell;
    int age;
    double height;
    int level;
    void copy(const Kolo& other)
    {
        this->spell = new char[strlen(other.spell)+1];
        strcpy(this->spell,other.spell);
        this->age = other.age;
        this->height = other.height;
        this->level = other.level;

    }
    void erase()
    {
        delete[] this->spell;
    }
public:
    Kolo()
    {
        this->spell = new char[5];
        strcpy(this->spell,"love");
        this->age = 18;
        this->height = 1.80;
        this->level = 100000;
    }
    Kolo(const Kolo& other)
    {
        this->copy(other);
    }
    Kolo& operator=(const Kolo& other)
    {
        if(this != &other)
        {
            this->erase();
            this->copy(other);
        }

        return *this;
    }

    bool seduce(KoloWoman koloWoman)
    {
        /*
            if(this->level > koloWoman.getLevel())
                return true;
            else
                return false;
        */
        return this->level > koloWoman.getLevel();
    }
    ~Kolo()
    {
        this->erase();
    }
};
