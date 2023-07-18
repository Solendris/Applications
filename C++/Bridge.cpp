#include <iostream>

using namespace std;

class Implementor;

class Abstraction
{
public:
	Abstraction(Implementor* pImplementor);
	virtual ~Abstraction();
	void Operation_WlaczWylacz();
	void Operation_ZmianaUrzadzenia(Implementor* pImplementor);
protected:
	Implementor* m_pImplementor;
};

class Implementor
{
public:
	Implementor() {}
	virtual ~Implementor() {}
	virtual void WlaczWylacz() = 0;
};

class ConcreteImplementor_Ekspres_do_kawy : public Implementor
{
public:
	int status;
	ConcreteImplementor_Ekspres_do_kawy() {}
	virtual ~ConcreteImplementor_Ekspres_do_kawy() {}
	virtual void WlaczWylacz();
};

class ConcreteImplementor_Klimatyzator : public Implementor
{
public:
    int status;
    ConcreteImplementor_Klimatyzator() {}
    virtual ~ConcreteImplementor_Klimatyzator() {}
    virtual void WlaczWylacz();
};

class ConcreteImplementor_Pralka : public Implementor
{
public:
    int status;
    ConcreteImplementor_Pralka() {}
    virtual ~ConcreteImplementor_Pralka() {}
    virtual void WlaczWylacz();
};


void ConcreteImplementor_Ekspres_do_kawy::WlaczWylacz()
{
    if (status == 0){
        cout << "Wlaczono ekspres\n";
        status = 1;
    }
    else {
        cout << "Wylaczono ekspres\n";
        status = 0;
    }

}

void ConcreteImplementor_Klimatyzator::WlaczWylacz()
{
    if (status == 0){
        cout << "Wlaczono klimatyzator\n";
        status = 1;
    }
    else {
        cout << "Wylaczono klimatyzator\n";
        status = 0;
    }

}

void ConcreteImplementor_Pralka::WlaczWylacz()
{
    if (status == 0){
        cout << "Wlaczono pralke\n";
        status = 1;
    }
    else {
        cout << "Wylaczono pralke\n";
        status = 0;
    }

}

Abstraction::Abstraction(Implementor* pImplementor) : m_pImplementor(pImplementor)
{
}

Abstraction::~Abstraction()
{
	delete m_pImplementor;
	m_pImplementor = NULL;
}

void Abstraction::Operation_WlaczWylacz()
{
	m_pImplementor->WlaczWylacz();
}

void Abstraction::Operation_ZmianaUrzadzenia(Implementor* pImplementor)
{
	pImplementor->WlaczWylacz();
}

int main()
{
    int tmp;
    int koniec = 0;
    Implementor *pEkspr = new ConcreteImplementor_Ekspres_do_kawy();
	Abstraction *pAbstraction1 = new Abstraction(pEkspr);

	Implementor *pKlima = new ConcreteImplementor_Klimatyzator();
	//Abstraction *pAbstraction2 = new Abstraction(pKlima);

	Implementor *pPralka = new ConcreteImplementor_Pralka();
	//Abstraction *pAbstraction3 = new Abstraction(pPralka);

	while (koniec != 1){
        cout <<"Ktore urzadzenie chcesz wlaczyc/wylaczyc?\n";
        cout <<"1. Ekspres do kawy\n";
        cout <<"2. Klimatyzator\n";
        cout <<"3. Pralka\n";
        cin >> tmp;

        if(tmp==1)
        {
            pAbstraction1->Operation_ZmianaUrzadzenia(pEkspr);
           // pAbstraction1->Operation_WlaczWylacz();
        }
        else if(tmp==2)
        {
            pAbstraction1->Operation_ZmianaUrzadzenia(pKlima);
            //pAbstraction2->Operation_WlaczWylacz();
        }
        else if(tmp==3)
        {
            pAbstraction1->Operation_ZmianaUrzadzenia(pPralka);
           // pAbstraction3->Operation_WlaczWylacz();
        }

        cin >> koniec;
        cout <<"\n";
	}


	delete pAbstraction1;
//	delete pAbstraction2;
	//delete pAbstraction3;

	return 0;
}

