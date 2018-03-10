#include <iostream>
#include <cstring>

using namespace std;

class Weapon
{
private:
    char weaponName[100];
    //int x;
public:
    Weapon()
    {
        strcpy(this->weaponName,"");
    }
    Weapon(const char* _weaponName)
    {
        strcpy(weaponName,_weaponName);
        //setWeaponName(_weaponName)
    }
    //w1.setWeaponName("blablabla");
    void setWeaponName(const char* weaponName)
    {
        strcpy(this->weaponName,weaponName);
    }
    const char* getWeaponName() const
    {
        return this->weaponName;
    }

    Weapon dummy()
    {
        return *this;
    }
    /*int getX() const
    {
        return x;
    }
    void setX(int _x);
    {
        x = _x;
    }

    void print() const
    {
        cout<<x<<endl;
    }*/
};
class Player
{
private:
    char name[30];
    Weapon weapon;
    int health;
public:
    Player()
    {
        strcpy(name,"");
        weapon = Weapon(); //this is called by default and is not needed.
        //weapon.setWeaponName("");
        health = 100;
    }
    Player(const char* _name,Weapon _weapon, int _health)
    {
        strcpy(name,_name);
        weapon = _weapon;
        health = _health;
    }

    const char* getName() const
    {
        return name;
    }
    int getHealth() const
    {
        return health;
    }
    Weapon getWeapon() const
    {
        return weapon;
    }

    void setName(const char* _name)
    {
        strcpy(name,_name);
    }
    void setWeapon(Weapon _w)
    {
        weapon = _w;
    }
    void setHealth(int _h)
    {
        health = _h;
    }
};

class Enemy
{
private:
    char name[30];
    Weapon weapon;
    int health;
public:
    Enemy()
    {
        strcpy(name,"");
        weapon = Weapon(); //this is called by default and is not needed.
        //weapon.setWeaponName("");
        health = 100;
    }
    Enemy(const char* _name,Weapon _weapon, int _health)
    {
        strcpy(name,_name);
        weapon = _weapon;
        health = _health;
    }

    const char* getName() const
    {
        return name;
    }
    int getHealth() const
    {
        return health;
    }
    Weapon getWeapon() const
    {
        return weapon;
    }

    void setName(const char* _name)
    {
        strcpy(name,_name);
    }
    void setWeapon(Weapon _w)
    {
        weapon = _w;
    }
    void setHealth(int _h)
    {
        health = _h;
    }

    void printWeapon() const
    {
        cout<<weapon.getWeaponName()<<endl;
    }

    void attack(Player& player) const
    {
        player.setHealth(player.getHealth() - 10);
    }

    void die()
    {
        health = 0;
    }
};

class GameScreen
{
private:
    int w;
    int h;
    Player player;
    Enemy enemy;
public:
    //Napravete konstruktori(default i s promenlivi,getteri,setteri,funkciq koqto ubiva enemy,funkciq koqto napada player dokato health > 0)
    /*
        while(player.getHealth() > 0)
        {
            enemy.attack(player);
        }
    */
};

int main()
{
    Weapon w1;
    Weapon w2 = w1.dummy();
    Player p1;
    Enemy e1;

    e1.setWeapon(Weapon("default"));

    e1.printWeapon();

    e1.attack(p1);

    cout<<p1.getHealth()<<endl;

    e1.setWeapon(w2);

    return 0;
}
