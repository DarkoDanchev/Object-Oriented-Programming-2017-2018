#include <iostream>
#include <cstring>

using namespace std;

class Car
{
private:
    char* carName;
public:
    Car();
    Car(char* carName)
    {
        this->carName = new char[strlen(carName) + 1];
        strcpy(this->carName,carName);
    }
    Car(const Car& other);
    const Car& operator=(const Car& other);
    ~Car()
    {
        delete [] this->carName;
    }

    virtual void print() const
    {
        cout<<this->carName<<endl;
    }
};

class SportCar : public Car
{
private:
    size_t maxSpeed;
public:
    SportCar(char* carName,size_t maxSpeed) : Car(carName)
    {
        this->maxSpeed = maxSpeed;
    }

    void print() const
    {
        Car::print();
        cout<<maxSpeed<<endl;
    }
};

int main()
{
    Car c1("Car1");
    SportCar c2("SportCar1",1000);

    c1.print();
    c2.print();

    Car** cars = new Car*[2]; //List<Car*>
    cars[0] =  new Car("Car1");
    cars[1] = new SportCar("SportCar1",1000);

    cars[1]->print();

    /*List<Car*> cars;
    //list<list<int>> a;
    cars.push_back(new Car("Car1"));
    cars.push_back(new SportCar("SportCar1",1000));
    cars.get(0)->print();
    */
    return 0;
}
