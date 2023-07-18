// Ten kod to implementacja wzorca projektowego Most (Bridge) w języku C++.
// Wzorzec Most oddziela hierarchie klas abstrakcyjnych od implementacji, co pozwala na zmianę lub rozwijanie ich niezależnie.
// This code is an implementation of the Bridge design pattern in C++. 
// The Bridge pattern separates the abstraction hierarchy from its implementation, allowing them to vary independently or be extended without affecting each other.

#include <iostream>
using namespace std;

// Klasa Implementor - klasa, która deklaruje operację Włącz/Wyłącz
// Implementor class - declares the WlaczWylacz (TurnOn/TurnOff) operation
class Implementor
{
public:
	Implementor() {} // Konstruktor // Constructor
	virtual ~Implementor() {} // Destruktor // Destructor
	virtual void WlaczWylacz() = 0; // Metoda do włączania/wyłączania urządzenia (czysta wirtualna) // Method for turning on/off the device (pure virtual)
};

// Klasa Abstraction - klasa abstrakcyjna, która korzysta z Implementora
// Abstraction class - an abstract class that uses Implementor
class Abstraction
{
public:
	Abstraction(Implementor* pImplementor); // Konstruktor, przekazuje wskaźnik do Implementora // Constructor, takes a pointer to Implementor
	virtual ~Abstraction(); // Destruktor // Destructor
	void Operation_WlaczWylacz(); // Metoda operacji Włącz/Wyłącz // Method for performing the TurnOn/TurnOff operation
	void Operation_ZmianaUrzadzenia(Implementor* pImplementor); // Metoda do zmiany urządzenia
protected:
	Implementor* m_pImplementor; // Wskaźnik do Implementora // Pointer to Implementor
};

// Klasy ConcreteImplementor_XXX - klasy konkretnych implementacji Implementora
// W każdej z nich zdefiniowano metody WlaczWylacz dla różnych urządzeń
// ConcreteImplementor_XXX classes - concrete classes for different Implementor implementations
// Each class defines the WlaczWylacz method for a different device
class ConcreteImplementor_Ekspres_do_kawy : public Implementor
{
public:
	int status; // Zmienna statusu (0 - wyłączony, 1 - włączony) // Status variable (0 - off, 1 - on)

	ConcreteImplementor_Ekspres_do_kawy() {} // Konstruktor // Constructor
	virtual ~ConcreteImplementor_Ekspres_do_kawy() {} // Destruktor // Destructor
	virtual void WlaczWylacz(); // Implementacja metody WlaczWylacz dla ekspresu do kawy // Implementation of the WlaczWylacz method for the coffee machine
};

class ConcreteImplementor_Klimatyzator : public Implementor
{
public:
	int status; // Zmienna statusu (0 - wyłączony, 1 - włączony) // Status variable (0 - off, 1 - on)

	ConcreteImplementor_Klimatyzator() {} // Konstruktor // Constructor
	virtual ~ConcreteImplementor_Klimatyzator() {} // Destruktor // Destructor
	virtual void WlaczWylacz(); // Implementacja metody WlaczWylacz dla klimatyzatora // Implementation of the WlaczWylacz method for the air conditioner
};

class ConcreteImplementor_Pralka : public Implementor
{
public:
	int status; // Zmienna statusu (0 - wyłączony, 1 - włączony) // Status variable (0 - off, 1 - on)

	ConcreteImplementor_Pralka() {} // Konstruktor // Constructor
	virtual ~ConcreteImplementor_Pralka() {} // Destruktor // Destructor
	virtual void WlaczWylacz(); // Implementacja metody WlaczWylacz dla pralki // Implementation of the WlaczWylacz method for the washing machine
};

// Implementacja metody WlaczWylacz dla ConcreteImplementor_Ekspres_do_kawy
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

// Implementacja metody WlaczWylacz dla ConcreteImplementor_Klimatyzator
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

// Implementacja metody WlaczWylacz dla ConcreteImplementor_Pralka
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

// Implementacja konstruktora klasy Abstraction
// Implementation of the constructor of the Abstraction class
Abstraction::Abstraction(Implementor* pImplementor) : m_pImplementor(pImplementor)
{
}

// Implementacja destruktora klasy Abstraction
// Implementation of the destructor of the Abstraction class
Abstraction::~Abstraction()
{
	delete m_pImplementor;
	m_pImplementor = NULL;
}

// Implementacja metody Operation_WlaczWylacz - wywołuje operację Włącz/Wyłącz na Implementorze
// Implementation of the Operation_WlaczWylacz method - invokes the TurnOn/TurnOff operation on the Implementor
void Abstraction::Operation_WlaczWylacz()
{
	m_pImplementor->WlaczWylacz();
}

// Implementacja metody Operation_ZmianaUrzadzenia - zmienia obiekt Implementora
// Implementation of the Operation_ZmianaUrzadzenia method - changes the Implementor object
void Abstraction::Operation_ZmianaUrzadzenia(Implementor* pImplementor)
{
	pImplementor->WlaczWylacz();
}

int main()
{
	int tmp = 0;

	// Tworzenie obiektów Implementorów i Abstraction
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

	// Zwalnianie pamięci
	// Freeing memory
	delete pAbstraction;

	return 0;
}
