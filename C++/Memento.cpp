#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#include <conio.h>
using namespace std;

class Board_rules {
public:
	string Board[3][3];
	string Player = "x";;
	Board_rules() {
		Board[0][0] = "00";
		Board[0][1] = "01";
		Board[0][2] = "02";

		Board[1][0] = "10";
		Board[1][1] = "11";
		Board[1][2] = "12";

		Board[2][0] = "20";
		Board[2][1] = "21";
		Board[2][2] = "22";


	}

	void changePlayer() {
		if (Player == "x"){
            Player = "o";
        }
        else if (Player == "o"){
            Player = "x";
        }
	}

	bool Avaliable(int x, int y) {
		if (x>=0 & x<=3){
            if (y>=0 & y<=3){
                if (Board[x][y] != "x" & Board[x][y] != "y"){
                    return true;
                }
                return false;
            }
            return false;
		}
		return false;
	}
};




typedef Board_rules State;

class Memento;

class Originator
{
 public:
  Originator(const State& rState);
  Originator();
  ~Originator() {}
  Memento* CreateMemento();
  void SetMemento(Memento* pMemento);
  State GetState();
  void SetState(const State& rState);
  void PrintState();
  void Play();
  int Check_conditions();
 private:
  State m_State;
};

class Memento
{
 private:
  friend class Originator;
  Memento(const State& rState);
  void SetState(const State& rState);
  State GetState();
  State m_State;
};

void Originator::Play(){
	int x;
	int y;
	cout << "Podaj wspolrzedna: x"<<endl;
	cin >> x;
	cout << "Podaj wspolrzedna: y"<<endl;
	cin >> y;
	if (m_State.Avaliable(x, y)) {
        if(m_State.Player == "x"){
            m_State.Board[x][y] = "x";
            m_State.Player = "o";
        }
        else if (m_State.Player == "o"){
            m_State.Board[x][y] = "o";
            m_State.Player = "x";
        }
	}
	else {
		cout << "Ruch niemozliwy " << endl;

	}
}
int Originator::Check_conditions(){
    int Winner = 0;
    if(m_State.Board[0][0] == "x" & m_State.Board[0][1] == "x" & m_State.Board[0][2] == "x"){
        Winner=1;
    }
    else if(m_State.Board[1][0] == "x" & m_State.Board[1][1] == "x" & m_State.Board[1][2] == "x"){
        Winner=1;
    }
    else if(m_State.Board[2][0] == "x" & m_State.Board[2][1] == "x" & m_State.Board[2][2] == "x"){
        Winner=1;
    }
    else if(m_State.Board[0][0] == "x" & m_State.Board[1][0] == "x" & m_State.Board[2][0] == "x"){
        Winner=1;
    }
    else if(m_State.Board[0][1] == "x" & m_State.Board[1][1] == "x" & m_State.Board[2][1] == "x"){
        Winner=1;
    }
    else if(m_State.Board[0][2] == "x" & m_State.Board[1][2] == "x" & m_State.Board[2][2] == "x"){
        Winner=1;
    }
    else if(m_State.Board[0][0] == "x" & m_State.Board[1][1] == "x" & m_State.Board[2][2] == "x"){
        Winner=1;
    }
    else if(m_State.Board[2][0] == "x" & m_State.Board[1][1] == "x" & m_State.Board[0][2] == "x"){
        Winner=1;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////
    if(m_State.Board[0][0] == "o" & m_State.Board[0][1] == "o" & m_State.Board[0][2] == "o"){
        Winner=-1;
    }
    else if(m_State.Board[1][0] == "o" & m_State.Board[1][1] == "o" & m_State.Board[1][2] == "o"){
        Winner=-1;
    }
    else if(m_State.Board[2][0] == "o" & m_State.Board[2][1] == "o" & m_State.Board[2][2] == "o"){
        Winner=-1;
    }
    else if(m_State.Board[0][0] == "o" & m_State.Board[1][0] == "o" & m_State.Board[2][0] == "o"){
        Winner=-1;
    }
    else if(m_State.Board[0][1] == "o" & m_State.Board[1][1] == "o" & m_State.Board[2][1] == "o"){
        Winner=-1;
    }
    else if(m_State.Board[0][2] == "o" & m_State.Board[1][2] == "o" & m_State.Board[2][2] == "o"){
        Winner=-1;
    }
    else if(m_State.Board[0][0] == "o" & m_State.Board[1][1] == "o" & m_State.Board[2][2] == "o"){
        Winner=-1;
    }
    else if(m_State.Board[2][0] == "o" & m_State.Board[1][1] == "o" & m_State.Board[0][2] == "o"){
        Winner=-1;
    }
    return Winner;
}
Originator::Originator()
{
}

Originator::Originator(const State& rState): m_State(rState)
{
}

State Originator::GetState()
{
 return m_State;
}

void Originator::SetState(const State& rState)
{
 m_State = rState;
}

Memento* Originator::CreateMemento()
{
 return new Memento(m_State);
}

void Originator::SetMemento(Memento* pMemento)
{
 if (NULL != pMemento)
 {
  m_State = pMemento->GetState();
 }
}

void Originator::PrintState()
{
 cout<< m_State.Board[0][0]<<" "<< m_State.Board[0][1] <<" "<< m_State.Board[0][2] << endl;
 cout << m_State.Board[1][0] <<" "<< m_State.Board[1][1] <<" "<< m_State.Board[1][2] << endl;
 cout << m_State.Board[2][0] <<" "<< m_State.Board[2][1] <<" "<< m_State.Board[2][2] << endl;
 cout << "Ruch wykonuje gracz: " << m_State.Player << endl;

}

Memento::Memento(const State& rState) : m_State(rState)
{
}

State Memento::GetState()
{
 return m_State;
}

void Memento::SetState(const State& rState)
{
 m_State = rState;
}


int main()
{
    unsigned char Sign;
    int Winner;
    bool End = false;
    stack<Memento> StackOfMemento;
 Originator* pOriginator = new Originator(Board_rules());
 Memento *pMemento = pOriginator->CreateMemento();
 for (int i=0;i<9;i++){

     pOriginator->PrintState();
     pOriginator->Play();
     pMemento = pOriginator->CreateMemento();
     StackOfMemento.push(*pMemento);
     if(i>=4)
     {
         Winner =  pOriginator->Check_conditions();
         if (Winner == 1){
            cout<<"Gracz z x wygrywa!" <<endl;
            break;
         }
         else if(Winner == -1){
            cout<<"Gracz z o wygrywa!" <<endl;
            break;
         }
         else if (i==9){
            cout<<"Remis!" <<endl;
         }
     }
     //cout <<"Rozmiar stosu: "<< StackOfMemento.size()<<endl;
     StackOfMemento.top();
 }
  cout<<"Nacisnij klawisz 'z' aby cofnac ruch. Nacisnij 'x' by zakonczyc program."<<endl;
 Sign = getch();
 while(End == false){
    if (Sign == 'z'){

        *pMemento=StackOfMemento.top();
        pOriginator->SetMemento(pMemento);
        pOriginator->PrintState();

        StackOfMemento.pop();
        Sign = getch();
        if(StackOfMemento.size()==0)
            {
                cout<<"Cofnales do poczatku gry!"<<endl;
                End = true;
            }
    }
    else if(Sign=='x'){
        End = true;
    }
 }


 delete pOriginator;
 delete pMemento;
 return 0;
}

