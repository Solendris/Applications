#include <iostream>
#include <fstream>
using namespace std;

class Iterator;
struct Object {
    string kod_miejscowosci;
    string miejscowosc;
};

class Aggregate
{
 public:
  virtual ~Aggregate();
  virtual Iterator* CreateIterator() = 0;
  virtual Object GetItem(int idx) = 0;
  virtual int GetSize() = 0;
 protected:
  Aggregate();
};

class ConcreteAggregate:public Aggregate
{

 public:
  int SIZE;
  ConcreteAggregate();
  ~ConcreteAggregate();
  Iterator* CreateIterator();
  Object GetItem(int idx);
  int GetSize();
 private:
  Object *_objs;
};

class Iterator
{
 public:
  virtual ~Iterator();
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual Object CurrentItem() = 0;
 protected:
  Iterator();
};

class ConcreteIterator:public Iterator
{
 public:
  ConcreteIterator(Aggregate* ag, int idx = 0);
  ~ConcreteIterator();
  void First();
  void Next();
  bool IsDone();
  Object CurrentItem();
 private:
  Aggregate* _ag;
  int _idx;
};

Aggregate::Aggregate()
{}

Aggregate::~Aggregate()
{}

ConcreteAggregate::ConcreteAggregate()
{
    ifstream p("kody_pocztowe.txt");
    p>>SIZE;
    cout <<"rozmiar: "<<SIZE<<endl;
    _objs = new Object();
    for (int i = 0; i < SIZE; i++){

        getline(p, _objs[i].kod_miejscowosci);

    }
    p.close();
}

ConcreteAggregate::~ConcreteAggregate()
{delete [] _objs;}

Iterator* ConcreteAggregate::CreateIterator()
{
 return new ConcreteIterator(this);
}


Object ConcreteAggregate::GetItem(int idx)
{
 if (idx < this->GetSize())
  return _objs[idx];
 else
  return _objs[idx];
}

int ConcreteAggregate::GetSize()
{
 return SIZE;
}

Iterator::Iterator()
{}

Iterator::~Iterator()
{}

ConcreteIterator::ConcreteIterator(Aggregate* ag, int idx)
{
 this->_ag = ag;
 this->_idx = idx;
}

ConcreteIterator::~ConcreteIterator()
{}

Object ConcreteIterator::CurrentItem()
{
 return _ag->GetItem(_idx);
}

void ConcreteIterator::First()
{
 _idx = 0;
}

void ConcreteIterator::Next()
{
 if (_idx < _ag->GetSize()) _idx++;
}

bool ConcreteIterator::IsDone()
{
 return (_idx == _ag->GetSize());
}

int main(int argc, char* argv[])
{

 Aggregate* ag = new ConcreteAggregate();
 Iterator* it = ag->CreateIterator();  // lub Iterator* it = new ConcreteIterator(ag);
 for (; !(it->IsDone()); it->Next())
 {
  cout << it->CurrentItem() << endl;
 }

 delete it;
 delete ag;
 return 0;
}

