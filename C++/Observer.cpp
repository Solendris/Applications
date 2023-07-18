#include <iostream>
#include <list>
#include <algorithm>
#include <fstream>

typedef std::string STATE;

class Observer;

class Subject
{
 public:
  Subject() : m_nSubjectState("") {}
  virtual ~Subject();

  void Notify();
  void Attach(Observer* pOberver);
  void Detach(Observer* pOberver);

  virtual void SetState(STATE nState);
  virtual STATE GetState();

 protected:
  STATE m_nSubjectState;
  std::list<Observer*> m_ListObserver;
};

class Observer
{
 public:
  Observer() : m_nObserverState("") {}
  virtual ~Observer() {}
  virtual void Update(Subject* pSubject) = 0;

 protected:
  STATE m_nObserverState;
};

class ConcreateSubject : public Subject
{
 public:
  ConcreateSubject() : Subject() {}
  virtual ~ConcreateSubject() {}

  virtual void SetState(STATE nState);
  virtual STATE GetState();
  void Update(Subject* pSubject);
};

class ConcreateObserver : public Observer
{
 public:
  //ConcreateObserver() : Observer() {nick = "nick"; status = "empty";}
  ConcreateObserver(std::string name,std::string status_) : Observer() {nick = name;status = status_;

  //const char * filename = nick;
  //strcat(nick,".txt");
  file.open((nick+".txt").c_str());
  };
  virtual ~ConcreateObserver() {file.close();}
  virtual void Update(Subject* pSubject);
  std::string nick;
  std::string status;
  std::ofstream file;
};



void Subject::Attach(Observer* pObserver)
{
 std::cout << "Attach an Observer\n";
 m_ListObserver.push_back(pObserver);
}

void Subject::Detach(Observer* pOberver)
{
 std::list<Observer*>::iterator iter;
 iter = std::find(m_ListObserver.begin(),m_ListObserver.end(),pOberver);
 if (m_ListObserver.end() != iter)
 {
  m_ListObserver.erase(iter);
 }
 std::cout << "Detach an Observer\n";
}

void Subject::Notify()
{
 std::cout << "Notify Observer's State\n";
 std::list<Observer*>::iterator iter1,iter2;
 iter1 = m_ListObserver.begin();
 iter2 = m_ListObserver.end();
 for (;iter1 != iter2; ++iter1)
 {
  (*iter1)->Update(this);
 }
}

void Subject::SetState(STATE nState)
{
 std::cout << "SetState By Subject\n";
 m_nSubjectState = nState;
}

STATE Subject::GetState()
{
 std::cout << "GetState By Subject\n";
 return m_nSubjectState;
}

Subject::~Subject()
{
 std::list<Observer*>::iterator iter1,iter2,temp;
 iter1 = m_ListObserver.begin();
 iter2 = m_ListObserver.end();
 for (;iter1 != iter2;)
 {
  temp = iter1;
  ++iter1;
  delete(*temp);
 }
 m_ListObserver.clear();
}

void ConcreateSubject::SetState(STATE nState)
{
 std::cout << "SetState By ConcreateSubject\n";
 m_nSubjectState = nState;
}

STATE ConcreateSubject::GetState()
{
 std::cout << "GetState By ConcreateSubject\n";
 return m_nSubjectState;
}

void ConcreateObserver::Update(Subject* pSubject)
{

 if (NULL == pSubject)
 {
  return;
 }
 m_nObserverState = pSubject->GetState();
 file << "The ObserverState is " << m_nObserverState << std::endl;
 //file << std::endl << nick << " status update - " << status << std::endl;
}

int main()
{
    /*
 Observer *p1 = new ConcreateObserver;
 Observer *p2 = new ConcreateObserver;
 Observer *p3 = new ConcreateObserver("fas");
 Subject* p = new ConcreateSubject;
 p -> Attach(p3);
 p->Attach(p1);
 p->Attach(p2);
 p->SetState(4);
 p->Notify();
 p->Detach(p1);
 p->SetState(10);
*/

Observer *Tomek = new ConcreateObserver("Tomek","dostepny");
Observer *Ania = new ConcreateObserver("Ania","zaraz wracam");
Observer *Kasia = new ConcreateObserver("Kasia","niedostepny");

 Subject* p = new ConcreateSubject;
 p -> Attach(Tomek);
 p -> Attach(Ania);
 p->SetState("niedostepny");
 p->Notify();
 p->Detach(Ania);
 p->Notify();
 p ->Attach(Ania);
 p-> Attach (Kasia);
 p->SetState("dostepny");
 p -> Notify();
 delete p;
 return 0;
}
