#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <list>
#include "main.h"
using namespace std;

//(SCHED_FIFO correspondendo a 1 e SCHED_RR, a 2)
//A descrição de cada tarefa é composta por três valores que correspondem
//respectivamente a: tempo de computação da tarefa (Ci), tempo de chegada da tarefa (Si) e prioridade
//(pi) da tarefa

void Tarefa::inicializa(int id, int ci, int si, int pi, int po)
{
  id = id;
  ci = ci;
  si = si;
  pi = pi;
  po = po;
}

int Tarefa::get_id()
{
  return id;
}

int Tarefa::get_tempocomp()
{
  return ci;
}

int Tarefa::get_chegada()
{
  return si;
}

int Tarefa::get_prioridade()
{
  return pi;
}

int Tarefa::get_politica()
{
  return po;
}

void Tarefa::set_id(int id)
{
  id = id;
}

void Tarefa::set_tempocomp(int ci)
{
  ci = ci;
}

void Tarefa::set_chegada(int si)
{
  si = si;
}

void Tarefa::set_prioridade(int pi)
{
  pi = pi;
}

void Tarefa::set_politica(int po)
{
  po = po;
}

void Tarefa::imprime()
{
 cout << "Id: " << id << endl;
 cout << "Tempo Computação: " << ci << endl;
 cout << "Tempo de chegada: " << si << endl;
 cout << "Prioridade: " << pi << endl;
 cout << "Politica: " << po << endl;
}

int main()
{
//##############################################################
  int n=0; //numero de tarefas.
  int id=0; // id da tarefa
  int ci=0; //tempo de computação da tarefa (Ci)
  int si=0; //tempo de chegada da tarefa (Si)
  int pi=0; //prioridade (pi)
  int po=0; // politica (po)
  int aux=0,i=0;
//##############################################################
std::list<int> tarefas;   // cria uma lista de pronto
std::list<int>::iterator t;  // cria um iterador
std::list<int> pronto;   // cria uma lista de pronto
std::list<int>::iterator p;  // cria um iterador

  cin >> n;
  cout << endl;

Tarefa teste[n];

for(aux=0;aux < n;aux++)
{
  teste[aux].inicializa(id,ci,si,pi,po);
  teste[aux].imprime();
}

for(aux=0;aux < n;aux++)
{
  cin >> ci;
  teste[aux].set_tempocomp(ci);
  cin >> si;
  teste[aux].set_chegada(si);
  cin >> pi;
  teste[aux].set_prioridade(pi);
  cin >> po;
  teste[aux].set_politica(po);
  teste[aux].set_id(i);
  i++;

  cout << endl;
}
for(aux=0;aux < n;aux++)
{
    teste[aux].imprime();
}

  return 0;
}
