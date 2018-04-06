#pragma once

class Earth
{
private:
    Kolo* kolos;
    KoloWoman* koloWomans;
    size_t kolosSize;
    size_t kolosCapacity;
    size_t kolosWomansSize;
    size_t kolosWomansCapacity;
public:
    Earth();
    Earth(const Earth& other);
    Earth& operator=(const Earth& other);
    ~Earth();
};
