#include <iostream>
#include <list>
#include <string>
using namespace std;

class Product
{
private:
	string First_Meal;
	string Second_Meal;
	string Desser;
public:
	void set_First_Meal(const string& s);
	void set_Second_Meal(const string& s);
	void set_Desser(const string& s);
	string get_First_Meal() { return First_Meal; }
	string get_Second_Meal() { return Second_Meal; }
	string get_Desser() { return Desser; }
	Product();
	~Product();
};

class Builder
{
public:
	virtual void Build_First_Meal() = 0;
	virtual void Build_Second_Meal() = 0;
	virtual void Build_Desser() = 0;
	virtual Product* GetProduct() = 0;
	Builder();
	virtual ~Builder();
};

class ConcreteBuilder1 :public Builder
{
public:
	ConcreteBuilder1();
	~ConcreteBuilder1();
	virtual void Build_First_Meal();
	virtual void Build_Second_Meal();
	virtual void Build_Desser();
	virtual Product* GetProduct();
private:
	Product* m_pProduct;
};

class ConcreteBuilder2 :public Builder
{
public:
	ConcreteBuilder2();
	~ConcreteBuilder2();
	virtual void Build_First_Meal();
	virtual void Build_Second_Meal();
	virtual void Build_Desser();
	virtual Product* GetProduct();
private:
	Product* m_pProduct;
};

class Director
{
public:
	Director(Builder* pBuilder);
	~Director();
	void Construct();
	Product getProduct();
private:
	Builder* m_pBuilder;
};

Product Director::getProduct() {
	return *m_pBuilder->GetProduct();
}

Product::~Product()
{
}

Product::Product()
{
}

void Product::set_First_Meal(const string& s)
{
	this->First_Meal = s;
}

void Product::set_Second_Meal(const string& s)
{
	this->Second_Meal = s;
}

void Product::set_Desser(const string& s)
{
	this->Desser = s;
}


Builder::Builder()
{
}

Builder::~Builder()
{
}

ConcreteBuilder1::ConcreteBuilder1()
{
	this->m_pProduct = new Product();
	cout << "Stworz nowy posilek! (Gosc1)" << endl;
}

void ConcreteBuilder1::Build_First_Meal()
{
	cout << "Wybierz Pierwsze Danie" << endl;
	cout << "1. Makaron" << endl;
	cout << "2. Rosol" << endl;
	cout << "0. Brak" << endl;

	int Choice = 0;
	cin >> Choice;
	switch (Choice)
	{
	case 1:
		this->m_pProduct->set_First_Meal("Makaron");
		break;
	case 2:
		this->m_pProduct->set_First_Meal("Rosol");
		break;
	case 0:
		this->m_pProduct->set_First_Meal(" ");
		break;
	}
}

void ConcreteBuilder1::Build_Second_Meal()
{
	cout << "Wybierz Drugie Danie" << endl;
	cout << "1. Ryz" << endl;
	cout << "2. Kotlet schabowy" << endl;
	cout << "3. Ogorek kiszony" << endl;
	cout << "0. Brak" << endl;

	int Choice = 0;
	cin >> Choice;
	switch (Choice)
	{
	case 1:
		this->m_pProduct->set_Second_Meal("Ryz");
		break;
	case 2:
		this->m_pProduct->set_Second_Meal("Kotlet schabowy");
		break;
	case 3:
		this->m_pProduct->set_Second_Meal("Ogorek kiszony");
		break;
	case 0:
		this->m_pProduct->set_Second_Meal(" ");
		break;
	}
}

void ConcreteBuilder1::Build_Desser()
{
	cout << "Wybierz Deser" << endl;
	cout << "1. Szarlotka" << endl;
	cout << "2. Kieliszek wina XXX" << endl;
	cout << "0. Brak" << endl;

	int Choice = 0;
	cin >> Choice;
	switch (Choice)
	{
	case 1:
		this->m_pProduct->set_Desser("Szarlotka");
		break;
	case 2:
		this->m_pProduct->set_Desser("Kieliszek wina XXX");
		break;
	case 0:
		this->m_pProduct->set_Desser(" ");
		break;
	}
}

Product* ConcreteBuilder1::GetProduct()
{
	return this->m_pProduct;
}

ConcreteBuilder1::~ConcreteBuilder1()
{
	delete this->m_pProduct;
	this->m_pProduct = NULL;
}

ConcreteBuilder2::ConcreteBuilder2()
{
	this->m_pProduct = new Product();
	cout << "Stworz nowy posilek! (Gosc2)" << endl;
}

void ConcreteBuilder2::Build_First_Meal()
{
	cout << "Wybierz Pierwsze Danie" << endl;
	cout << "1. Zupa szczawiowa" << endl;
	cout << "2. Grzanki" << endl;
	cout << "0. Brak" << endl;

	int Choice = 0;
	cin >> Choice;
	switch (Choice)
	{
	case 1:
		this->m_pProduct->set_First_Meal("Zupa szczawiowa");
		break;
	case 2:
		this->m_pProduct->set_First_Meal("Grzanki");
		break;
	case 0:
		this->m_pProduct->set_First_Meal(" ");
		break;
	}
}

void ConcreteBuilder2::Build_Second_Meal()
{
	cout << "Wybierz Drugie Danie" << endl;
	cout << "1. Kasza gryczana" << endl;
	cout << "2. Kotlet sojowy" << endl;
	cout << "3. Mizeria" << endl;
	cout << "0. Brak" << endl;

	int Choice = 0;
	cin >> Choice;
	switch (Choice)
	{
	case 1:
		this->m_pProduct->set_Second_Meal("Kasza gryczana");
		break;
	case 2:
		this->m_pProduct->set_Second_Meal("Kotlet sojowy");
		break;
	case 3:
		this->m_pProduct->set_Second_Meal("Mizeria");
		break;
	case 0:
		this->m_pProduct->set_First_Meal(" ");
		break;
	}
}

void ConcreteBuilder2::Build_Desser()
{
	cout << "Wybierz Deser" << endl;
	cout << "1. Szklanka piwa XXX" << endl;
	cout << "0. Brak" << endl;

	int Choice = 0;
	cin >> Choice;
	switch (Choice)
	{
	case 1:
		this->m_pProduct->set_Desser("Szklanka piwa XXX");
		break;
	case 0:
		this->m_pProduct->set_Desser(" ");
		break;
	}
}

Product* ConcreteBuilder2::GetProduct()
{
	return this->m_pProduct;
}

ConcreteBuilder2::~ConcreteBuilder2()
{
	delete this->m_pProduct;
	this->m_pProduct = NULL;
}

Director::Director(Builder* pBuilder)
{
	this->m_pBuilder = pBuilder;
}

void Director::Construct()
{
	this->m_pBuilder->Build_First_Meal();
	this->m_pBuilder->Build_Second_Meal();
	this->m_pBuilder->Build_Desser();
}

Director::~Director()
{
	delete this->m_pBuilder;
	this->m_pBuilder = NULL;
}

class Component
{
private:
	string First_Meal;

public:
	string get_First_Meal() { return First_Meal; }
	virtual void Operation() = 0;
	virtual void Operation2() = 0;
};

class ConcreteComponent : public Component
{
public:
	void Operation()
	{
		cout << "ConcreteComponent" << endl;
	}
	void Operation2()
	{
		cout << "ConcreteComponent2" << endl;
	}

};

class Decorator : public Component
{
public:
	Decorator(Component *pComponent) : m_pComponentObj(pComponent) {}
	void Operation()
	{
		if (m_pComponentObj != NULL)
		{
			m_pComponentObj->Operation();
		}
	}
	void Operation2()
	{
		if (m_pComponentObj != NULL)
		{
			m_pComponentObj->Operation2();
		}
	}
protected:
	Component *m_pComponentObj;
};

class ConcreteDecoratorA : public Decorator
{
public:
	ConcreteDecoratorA(Component *pDecorator) : Decorator(pDecorator)
	{
		AddedState = "Kluski z serem";
	}
	void Operation()
	{
		cout << "Added state: " << AddedState << endl;
		Decorator::Operation();
	}
	void Operation2()
	{
		cout << "Dodano " << AddedState << endl;
		Decorator::Operation2();
	}
private:
	string AddedState;
};

class ConcreteDecoratorB : public Decorator
{
public:
	ConcreteDecoratorB(Component *pDecorator) : Decorator(pDecorator) {}
	void Operation()
	{
		AddedBehavior();
		Decorator::Operation();
	}
	void  AddedBehavior()
	{
		cout << "Added behavior B" << endl;
	}
};

int main()
{
	//list <Component*> List_of_Dishes2;
	//Component *pComponentObj = new ConcreteComponent();
	//pComponentObj->Operation();

	/*cout << "-------" << endl;
	Decorator *pDecoratorAObj = new ConcreteDecoratorA(pComponentObj);
	pDecoratorAObj->Operation();

	cout << "-------" << endl;
	Decorator *pDecoratorBObj = new ConcreteDecoratorB(pComponentObj);
	pDecoratorBObj->Operation();

	cout << "-------" << endl;
	Decorator *pDecoratorBAObj = new ConcreteDecoratorB(pDecoratorAObj);
	pDecoratorBAObj->Operation();

	delete pDecoratorBAObj;
	pDecoratorBAObj = NULL;
	delete pDecoratorBObj;
	pDecoratorBObj = NULL;
	delete pDecoratorAObj;
	pDecoratorAObj = NULL;
	delete pComponentObj;
	pComponentObj = NULL;*/

	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<koniec dekoratora>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;

	list<Product> List_of_Dishes;
	int Choice = 0;
	bool Ordering = true;
	while (Ordering == true) {
		cout << "1. Dodaj zamowienie" << endl;
		cout << "2. Pokaz zamowienie" << endl;
		cin >> Choice;

		if (Choice == 1) {
			int Order_type = 0;
			cout << "1. Gosc1" << endl;
			cout << "2. Gosc2" << endl;
			cin >> Order_type;
			if (Order_type == 1) {
				Director* pDirector1 = new Director(new ConcreteBuilder1());
				pDirector1->Construct();
				List_of_Dishes.push_back(pDirector1->getProduct());
			}
			else if (Order_type == 2) {
				Director* pDirector2 = new Director(new ConcreteBuilder2());
				pDirector2->Construct();
				List_of_Dishes.push_back(pDirector2->getProduct());
			}
			else {
				break;
			}

		}
		else if (Choice == 2) {
			Ordering = false;
			for (auto &i : List_of_Dishes) {
				cout << "Zamowienie: " << endl;
				cout << "Pierwsze danie: " << i.get_First_Meal() << endl;
				cout << "Drugie danie: " << i.get_Second_Meal() << endl;
				cout << "Deser: " << i.get_Desser() << endl;
				Component *tmp = new ConcreteComponent();  //tworzy komponent
				tmp->get_First_Meal();     //przekazuje dane do komponentu
				Decorator *pDecoratorTMP = new ConcreteDecoratorA(tmp);    //wyswietla i modyfikuje komponent
				pDecoratorTMP->Operation2();   //dopisuje do istniejacego komponentu
			}
		}
	}

}

