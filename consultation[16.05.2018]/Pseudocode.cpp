//Just examples

Base(virtual void print         {cout<<"base"<<endl;}) 
Child -> Base (void print         {cout<<"child"<<endl;})


List<Base*> l;
l.push(new Base());
l.push(new Child());
l[0].print();
(Child)l[1].printChild();

class Base
{
public:
    static int a;
    Base()
    {
        a++;
    }
    static int getNI(){
        return a;
    }
};

int NI = Base::getNI();

int Base::a = 0;

class Factory
{
private:
    Factory();
public:
    static Car* getCar(String carName)
    {
        if(carName == "Ferrari")
        {
            return new Ferrari();
        }else{
            return new Jaguar();
        }
    }
    static Jaguar  getJaguar();
};
Base b;



Factory f;

Ferrari f1 = (Ferrari)Factory::getCar("ferrari");

