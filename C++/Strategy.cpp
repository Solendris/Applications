#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Strategy
{
    public:
       virtual void AlgorithmInterface(list<string> dane, string plik) = 0;

};

class ConcreteStrategyA: public Strategy
{
    public:
        virtual void AlgorithmInterface(list<string> dane, string plik)
        {
            ofstream tytuly;
            tytuly.open(plik + ".html");
            std::list<string>::iterator iterator;
            tytuly << "<html>" << "\n";
            tytuly <<"<ul>" << "\n";
                for (iterator = dane.begin(); iterator != dane.end(); ++iterator) {
                    tytuly << "<li>" << *iterator << "</li>" << "\n";
                }
            tytuly <<"</ul>" << "\n";
            tytuly <<"</html>" << "\n";
            tytuly.close();
            cout << "Dodano dane w formacie HTML" << endl;

        }
};

class ConcreteStrategyB: public Strategy
{
    public:
        virtual void AlgorithmInterface(list<string> dane, string plik)
        {
            ofstream tytuly;
            tytuly.open(plik + ".txt");
            std::list<string>::iterator iterator;
                for (iterator = dane.begin(); iterator != dane.end(); ++iterator) {
                    tytuly << *iterator << "\n";
                }
            tytuly.close();
            cout << "Dodano dane w formacie TXT" << endl;
        }
};

class ConcreteStrategyC: public Strategy
{
    public:
        virtual void AlgorithmInterface(list<string> dane, string plik)
        {
            ofstream tytuly;
            tytuly.open(plik + ".xml");
            std::list<string>::iterator iterator;
            tytuly <<"<CAT>"<< "\n";
                for (iterator = dane.begin(); iterator != dane.end(); ++iterator) {
                    tytuly << "<NAME>" << *iterator << "</NAME>" << "\n";
                }
            tytuly <<"</CAT>"<< "\n";
            tytuly.close();
            cout << "Dodano dane w formacie XML" << endl;
        }
};

class Context
{
    private:
        Strategy *_strategy;
        list<string> dane;
        string nazwa;
    public:
        Context(string folder, string _nazwa,Strategy *strategy):_strategy(strategy)
        {
            string linia;
            nazwa = _nazwa;
            ifstream plik_wej(folder);

            if (plik_wej.is_open())
            {
                for (linia; getline(plik_wej, linia);/**/) {
                    dane.push_back(linia);
                }
                plik_wej.close();
            }
        }
        void set_strategy(Strategy *strategy)
        {
            _strategy = strategy;
        }

        void ContextInterface()
        {
            _strategy->AlgorithmInterface(dane, nazwa);
        }
};

int main(int argc, char *argv[])
{


    ConcreteStrategyA concreteStrategyA;
    ConcreteStrategyB concreteStrategyB;
    ConcreteStrategyC concreteStrategyC;

    Context contextX("dane.txt","nowe_dane", &concreteStrategyA);

    contextX.ContextInterface();

    contextX.set_strategy(&concreteStrategyB);
    contextX.ContextInterface();

    contextX.set_strategy(&concreteStrategyC);
    contextX.ContextInterface();

    return 0;
}
