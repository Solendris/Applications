#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

class Colleague;
class Mediator;
class ConcreteMediator;
class ConcreteColleague;

class Mediator
{
 public:
  virtual void Send(string message, Colleague* colleague) = 0;
};

class Colleague
{
 protected:
  Mediator *mediator;
  string name;
 public:
  Colleague(Mediator *mediator, string name)
  {
   this->mediator = mediator;
   this->name = name;
  }
  virtual void Notify(string message){}
};

class ConcreteColleague : public Colleague
{
 public:
  ConcreteColleague(Mediator *mediator, string name) : Colleague(mediator, name) {}
  void Send(string message)
  {
   mediator->Send(message, this);
  }
  void Notify(string message)
  {
   cout << name << " otrzymal wiadomosc: " << message << endl;
  }
};

class ConcreteMediator : public Mediator
{
 private:
  list<Colleague*> users;

 public:
  void addColleague(Colleague* coll){
     users.push_back(coll);
     }
  void deleteColleague(){
     users.clear();
     }

  virtual void Send(string message, Colleague* colleague)
  {
  list <Colleague*> :: iterator it;
   for (it = users.begin(); it != users.end(); it++){
    if (*it != colleague)
        (*it)->Notify(message);
   }
  }
};

int main()
{
 ConcreteMediator *m = new ConcreteMediator();
 ConcreteColleague *c1 = new ConcreteColleague(m, "Jan");
 ConcreteColleague *c2 = new ConcreteColleague(m, "Kamila");
 ConcreteColleague *c3 = new ConcreteColleague(m, "Sebastian");
 ConcreteColleague *c4 = new ConcreteColleague(m, "Olga");
 ConcreteColleague *c5 = new ConcreteColleague(m, "Kornel");

 m->addColleague(c1);
 m->addColleague(c2);
 m->addColleague(c3);
 m->addColleague(c4);
 m->addColleague(c5);
 c1->Send("Witaj od Jana");
 cout <<"\n";
 c2->Send("Witaj od Kamili");
 cout <<"\n";
 c3->Send("Witaj od Sebastiana");
 cout <<"\n";
 c4->Send("Witaj od Olgi");
 cout <<"\n";
 c5->Send("Witaj od Kornela");

 m->deleteColleague();

 delete m;
 return 0;
}
