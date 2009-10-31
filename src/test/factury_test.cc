#include <iostream>

#include "../factury/factury.hh"

using namespace std;
using namespace ecpp;


class Base {
public:

  virtual int value() = 0;

};

class TestA : public Base {
public:
  TestA(int a, int b, float c)
    : d_a(a), d_b(b), d_c(c) {}
  virtual int value() { return 10*d_a*d_c*d_b; }
private:
  int d_a;
  int d_b;
  float d_c;
};


class TestB : public Base {
public:
  TestB(int a, int b, float c)
    : d_a(a), d_b(b), d_c(c) {}
  virtual int value() { return 100*d_a-d_c*d_b; }
private:
  int d_a;
  int d_b;
  float d_c;
};


class TestC : public Base {
public:
  TestC(int a, int b, float c)
    : d_a(a), d_b(b), d_c(c) {}
  virtual int value() { return 200*d_a*d_c/d_b; }
private:
  int d_a;
  int d_b;
  float d_c;
};


int main()
{
  Factury3<Base,int,int,float> *f0, *f1, *f2;

  f0 = Factury3<Base,int,int,float>::create<TestA>();
  f1 = Factury3<Base,int,int,float>::create<TestB>();
  f2 = Factury3<Base,int,int,float>::create<TestC>();

  Base *o0 = (*f0)(10,3,0.5);
  Base *o1 = (*f1)(10,3,0.5);
  Base *o2 = (*f2)(10,3,0.5);

  cout << "o0 -> " << o0->value() << endl;
  cout << "o1 -> " << o1->value() << endl;
  cout << "o2 -> " << o2->value() << endl;

  return 0;
}
