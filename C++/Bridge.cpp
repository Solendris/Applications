// This code is an implementation of the Bridge design pattern in C++. 
// The Bridge pattern separates the abstraction hierarchy from its implementation, allowing them to vary independently or be extended without affecting each other.

#include <iostream>
using namespace std;

// Implementor class - declares the WlaczWylacz (TurnOn/TurnOff) operation
class Implementor
{
public:
	Implementor() {}  // Constructor
	virtual ~Implementor() {}  // Destructor
	virtual void WlaczWylacz() = 0; // Method for turning on/off the device (pure virtual)
};

// Abstraction class - an abstract class that uses Implementor
class Abstraction
{
public:
	Abstraction(Implementor* pImplementor); // Constructor, takes a pointer to Implementor
	virtual ~Abstraction(); // Destructor
	void Operation_WlaczWylacz(); // Method for performing the TurnOn/TurnOff operation
	void Operation_ZmianaUrzadzenia(Implementor* pImplementor); // Method for changing the device
protected:
	Implementor* m_pImplementor; // Pointer to Implementor
};

// ConcreteImplementor_XXX classes - concrete classes for different Implementor implementations
// Each class defines the WlaczWylacz method for a different device
class ConcreteImplementor_Ekspres_do_kawy : public Implementor
{
public:
	int status; // Status variable (0 - off, 1 - on)

	ConcreteImplementor_Ekspres_do_kawy() {} // Constructor
	virtual ~ConcreteImplementor_Ekspres_do_kawy() {} // Destructor
	virtual void WlaczWylacz(); // Implementation of the WlaczWylacz method for the coffee machine
};

class ConcreteImplementor_Klimatyzator : public Implementor
{
public:
	int status; // Status variable (0 - off, 1 - on)

	ConcreteImplementor_Klimatyzator() {} // Constructor
	virtual ~ConcreteImplementor_Klimatyzator() {} // Destructor
	virtual void WlaczWylacz(); // Implementation of the WlaczWylacz method for the air conditioner
};

class ConcreteImplementor_Pralka : public Implementor
{
public:
	int status; // Status variable (0 - off, 1 - on)

	ConcreteImplementor_Pralka() {} // Constructor
	virtual ~ConcreteImplementor_Pralka() {} // Destructor
	virtual void WlaczWylacz(); // Implementation of the WlaczWylacz method for the washing machine
};

// Implementation of the WlaczWylacz method for ConcreteImplementor_Ekspres_do_kawy
void ConcreteImplementor_Ekspres_do_kawy::WlaczWylacz()
{
	if (status == 0)
	{
		cout << "Wlaczono ekspres\n";
		status = 1;
	}
	else
	{
		cout << "Wylaczono ekspres\n";
		status = 0;
	}
}

// Implementation of the WlaczWylacz method for ConcreteImplementor_Klimatyzator
void ConcreteImplementor_Klimatyzator::WlaczWylacz()
{
	if (status == 0)
	{
		cout << "Wlaczono klimatyzator\n";
		status = 1;
	}
	else
	{
		cout << "Wylaczono klimatyzator\n";
		status = 0;
	}
}

// Implementation of the WlaczWylacz method for ConcreteImplementor_Pralka
void ConcreteImplementor_Pralka::WlaczWylacz()
{
	if (status == 0)
	{
		cout << "Wlaczono pralke\n";
		status = 1;
	}
	else
	{
		cout << "Wylaczono pralke\n";
		status = 0;
	}
}

// Implementation of the constructor of the Abstraction class
Abstraction::Abstraction(Implementor* pImplementor) : m_pImplementor(pImplementor)
{
}

// Implementation of the destructor of the Abstraction class
Abstraction::~Abstraction()
{
	delete m_pImplementor;
	m_pImplementor = NULL;
}

// Implementation of the Operation_WlaczWylacz method - invokes the TurnOn/TurnOff operation on the Implementor
void Abstraction::Operation_WlaczWylacz()
{
	m_pImplementor->WlaczWylacz();
}

// Implementation of the Operation_ZmianaUrzadzenia method - changes the Implementor object
void Abstraction::Operation_ZmianaUrzadzenia(Implementor* pImplementor)
{
	pImplementor->WlaczWylacz();
}

int main()
{
	int tmp = 0;

	// Creating Implementor and Abstraction objects
	Implementor* pEkspr = new ConcreteImplementor_Ekspres_do_kawy();
	Implementor* pKlima = new ConcreteImplementor_Klimatyzator();
	Implementor* pPralka = new ConcreteImplementor_Pralka();

    Abstraction* pAbstraction = new Abstraction(pEkspr);


	while (tmp != 4)
	{
		cout << "Ktore urzadzenie chcesz wlaczyc/wylaczyc?\n";
		cout << "1. Ekspres do kawy\n";
		cout << "2. Klimatyzator\n";
		cout << "3. Pralka\n";
		cout << "4. Zamknij\n";
		cin >> tmp;

		if (tmp == 1)
		{
			pAbstraction->Operation_ZmianaUrzadzenia(pEkspr);
		}
		else if (tmp == 2)
		{
			pAbstraction->Operation_ZmianaUrzadzenia(pKlima);
		}
		else if (tmp == 3)
		{
			pAbstraction->Operation_ZmianaUrzadzenia(pPralka);
		}

		cout << "\n";
	}

	// Freeing memory
	delete pAbstraction;

	return 0;
}
