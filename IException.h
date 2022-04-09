#pragma once
#include <iostream>

using namespace std;

class IException{
public:
    virtual void show() = 0;
    virtual ~IException(){}
};

class IntEx: public IException{
    int a;
public:
    IntEx(int _a): a(_a){}
    void show() override;
    ~IntEx(){}
};