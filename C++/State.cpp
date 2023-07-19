#include <iostream>
#include <conio.h>
using namespace std;

class State;

class Context
{
public:
	Context(State* pState);
	~Context();
	void Request();
	void ChangeState(State* pState);
private:
	State* m_pState;
};

class State
{
public:
	virtual ~State() {}
	virtual void Handle(Context* pContext) = 0;
};

class Samochod_Stoi : public State
{
public:
	void Handle(Context* pContext);
};

class Samochod_Jedzie : public State
{
public:
	void Handle(Context* pContext);
};

class Samochod_Cofa : public State
{
public:
	void Handle(Context* pContext);
};

Context::Context(State* pState) : m_pState(pState)
{
}

Context::~Context()
{
	delete m_pState;
	m_pState = NULL;
}

void Context::Request()
{
	if (NULL != m_pState)
	{
		m_pState->Handle(this);
	}
}

void Context::ChangeState(State* pState)
{
	if (NULL != m_pState)
	{
		delete m_pState;
		m_pState = NULL;
	}
	m_pState = pState;
}

void Samochod_Stoi::Handle(Context* pContext)
{
	cout << "Samochod stoi. Dostepne zmiany stanu:" << endl;
	cout << "R - wsteczny" << endl;
	cout << "1 - jazda do przodu" << endl;
}

void Samochod_Jedzie::Handle(Context* pContext)
{
	unsigned char Znak_Jazda;
	Znak_Jazda = '1';
	cout << "Samochod jedzie. Wbity bieg 1. Dostepne zmiany stanu:" << endl;
	cout << "0 - Samochod stoi" << endl;
	cout << "2 - Wbity bieg 2" << endl;

	while (Znak_Jazda == '1' or Znak_Jazda == '2' or Znak_Jazda == '3' or Znak_Jazda == '4' or Znak_Jazda == '5') {
		Znak_Jazda = getch();
		cin >> Znak_Jazda;
		if (Znak_Jazda == '1') {

			cout << "Dostepne zmiany stanu:" << endl;
			cout << "0 - Samochod stoi" << endl;
			cout << "2 - Wbity bieg 2" << endl;

		}
		if (Znak_Jazda == '2') {
			cout << "Dostepne zmiany stanu:" << endl;
			cout << "2 - Wbity bieg 1" << endl;
			cout << "3 - Wbity bieg 3" << endl;

		}
		if (Znak_Jazda == '3') {
			cout << "Dostepne zmiany stanu:" << endl;
			cout << "2 - Wbity bieg 2" << endl;
			cout << "4 - Wbity bieg 4" << endl;
		}
		if (Znak_Jazda == '4') {
			cout << "Dostepne zmiany stanu:" << endl;
			cout << "3 - Wbity bieg 3" << endl;
			cout << "5 - Wbity bieg 5" << endl;
		}
		if (Znak_Jazda == '5') {

			cout << "Dostepne zmiany stanu:" << endl;
			cout << "4 - Wbity bieg 4" << endl;

		}
		if (Znak_Jazda == '0') {
			cout << "Zatrzymales samochod!" << endl;
			cout << "Dostepne zmiany stanu:" << endl;
			cout << "R - wsteczny" << endl;
			cout << "1 - jazda do przodu" << endl;
			break;
		}
		if (Znak_Jazda == 'x' or Znak_Jazda == 'X') {
			break;
		}
		cout << "Samochod jedzie. Wbity bieg " << Znak_Jazda << endl;
	}
}

void Samochod_Cofa::Handle(Context* pContext)
{
	cout << "Samochod cofa. Dostepne zmiany stanu:" << endl;
	cout << "0 - postoj" << endl;

}

int main()
{
	unsigned char Znak;
	bool End = false;

	State *Postoj = new Samochod_Stoi();
	State *Jazda_Wprzod = new Samochod_Jedzie();
	State *Jazda_Wstecz = new Samochod_Cofa();
	Context *pContext = new Context(Postoj);
	pContext->Request();

	while (End == false) {

		Znak = getch();
		cin >> Znak;

		if (Znak == 'R' or Znak == 'r') {
			pContext->ChangeState(Jazda_Wstecz);
			pContext->Request();
		}
		if (Znak == '0') {
			pContext->ChangeState(Postoj);
			pContext->Request();
			cout << "koniec";
		}
		else if (Znak == '1') {
			pContext->ChangeState(Jazda_Wprzod);
			pContext->Request();
		}
		else if (Znak == 'x' or Znak == 'X') {
			End = true;
		}
	}
	cout << "koniec";

	delete pContext;

	return 0;
}
