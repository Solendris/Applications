#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <fstream>

using namespace std;

typedef int STATE;
STATE number;

class Observer;
int read_number = 0;
class Subject
{
public:
	Subject() : m_nSubjectState(-1) {}
	virtual ~Subject();

	void Notify();
	void Attach(Observer* pObserver);
	void Detach(Observer* pOberver);

	virtual void SetState(STATE nState);
	virtual STATE GetState();

protected:
	STATE m_nSubjectState;
	list<Observer*> m_ListObserver;
};

class Observer
{
public:
	Observer() : m_nObserverState(-1) {}
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
	ConcreateObserver() : Observer() {}
	virtual ~ConcreateObserver() {}
	virtual void Update(Subject* pSubject);


};

class ConcreateObserver2 : public Observer
{
public:
	ConcreateObserver2() : Observer() {}
	virtual ~ConcreateObserver2() {}
	virtual void Update(Subject* pSubject);
};

void Subject::Attach(Observer* pObserver)
{
	m_ListObserver.push_back(pObserver);
}

void Subject::Detach(Observer* pOberver)
{
	list<Observer*>::iterator iter;
	iter = find(m_ListObserver.begin(), m_ListObserver.end(), pOberver);
	if (m_ListObserver.end() != iter)
	{
		m_ListObserver.erase(iter);
	}
}

void Subject::Notify()
{
	list<Observer*>::iterator iter1, iter2;
	iter1 = m_ListObserver.begin();
	iter2 = m_ListObserver.end();
	for (; iter1 != iter2; ++iter1)
	{
		(*iter1)->Update(this);
	}
}

void Subject::SetState(STATE nState)
{
	m_nSubjectState = nState;

}

STATE Subject::GetState()
{
	return m_nSubjectState;
}

Subject::~Subject()
{
	list<Observer*>::iterator iter1, iter2, temp;
	iter1 = m_ListObserver.begin();
	iter2 = m_ListObserver.end();
	for (; iter1 != iter2;)
	{
		temp = iter1;
		++iter1;
		delete(*temp);
	}
	m_ListObserver.clear();
}

void ConcreateSubject::SetState(STATE nState)
{

	m_nSubjectState = nState;
	cout << "Ustaw numer uzytkownika\n";
	cin >> read_number;
	if (read_number > 0) {
		number = read_number;
	}
	else {
		cout << "Nieprawidlowy numer uzytkownika!\n";
		number = 0;
	}

}

STATE ConcreateSubject::GetState()
{
	return m_nSubjectState;
}

void ConcreateObserver::Update(Subject* pSubject)
{
	if (NULL == pSubject)
	{
		return;
	}
	m_nObserverState = pSubject->GetState();
}

void ConcreateObserver2::Update(Subject* pSubject)
{
	if (NULL == pSubject)
	{
		return;
	}
	m_nObserverState = pSubject->GetState();
	if (pSubject->GetState() == 0) {
		cout << "Uzytkownik o numerze "<<number<<" jest nieaktywny!" << endl;
	}
	else if (pSubject->GetState() == 1) {
		cout << "Uzytkownik o numerze " << number << " jest aktywny!" << endl;
	}
	else if (pSubject->GetState() == 2) {
		cout << "Uzytkownik o numerze " << number << " zaraz wraca!" << endl;
	}
	else {
		cout << "Podano zly stan!" << endl;
	}

}


int main()
{
	/* dziala dla wartosci wpisanych "z palca"
	 int tmpState = 0;
	Observer *p1 = new ConcreateObserver;
	Observer *p2 = new ConcreateObserver2;
	Subject* p = new ConcreateSubject;
	p->Attach(p1);
	p->Attach(p2);
	cout << "Ustaw stan konkretnego uzytkownika\n";
	cout << "Stan 0: jestem nieaktywny" << endl;
	cout << "Stan 1: jestem aktywny" << endl;
	cout << "Stan 2: zaraz wracam" << endl;
	cin >> tmpState;
	p->SetState(tmpState);
	p->Notify();
	p->Detach(p1);
	cout << "Ustaw stan konkretnego uzytkownika\n";
	cout << "Stan 0: jestem nieaktywny" << endl;
	cout << "Stan 1: jestem aktywny" << endl;
	cout << "Stan 2: zaraz wracam" << endl;
	cin >> tmpState;
	p->SetState(tmpState);
	p->Notify();
	delete p;
	*/

	//wersja "na sztywno" (by nie wpisywac wszystkiego recznie)
	Observer *p1 = new ConcreateObserver;
	Observer *p2 = new ConcreateObserver2;
	Subject* p = new ConcreateSubject;
	p->Attach(p1);
	p->Attach(p2);
	p->SetState(1);
	p->Notify();
	p->Detach(p1);
	p->SetState(2);
	p->Notify();
	delete p;

	return 0;
}
