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

Tarefa::Tarefa(): id(0),ci(0),pi(0),po(0),si(0){
}

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

void Tarefa::set_id(int idd)
{
  id = idd;
}

void Tarefa::set_tempocomp(int cii)
{
  ci = cii;
}

void Tarefa::set_chegada(int sii)
{
  si = sii;
}

void Tarefa::set_prioridade(int pii)
{
  pi = pii;
}

void Tarefa::set_politica(int poo)
{
  po = poo;
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
std::list<Tarefa> tarefas;   // cria uma lista de tarefas
std::list<Tarefa>::iterator t;  // cria um iterador
std::list<Tarefa *> tarefasptr;   // cria uma lista de pronto
std::list<Tarefa *>::iterator p;  // cria um iterador


  cin >> n;
  cout << endl;

Tarefa teste[n];
Tarefa tar;


//#############################################################
//#########  CRIA AS TAREFAS ##################################

for(aux=0;aux < n;aux++)
{
  // cin >> ci;
  // teste[aux].set_tempocomp(ci);
  // cin >> si;
  // teste[aux].set_chegada(si);
  // cin >> pi;
  // teste[aux].set_prioridade(pi);
  // cin >> po;
  // teste[aux].set_politica(po);
  // teste[aux].set_id(i);

 // cin >> ci >> si >> pi >> po;
 tar.set_tempocomp(ci);
 // cin >> si;
 tar.set_chegada(si);
 // cin >> pi;
 tar.set_prioridade(pi);
 // cin >> po;
 tar.set_politica(po);
 tar.set_id(i);

  cout << "antes" << endl;
  tarefas.push_back(tar);
  cout << "depois" << endl;
  cout << "size" << tarefas.size() << endl;

  i++;
  p++;
  cout << endl;
}
//#############################################################
cout << "depois do for" << endl;


//#############################################################
//########### IMPRIME #########################################
// for(aux=0;aux < n;aux++)
// {
//     teste[aux].imprime();
// }
//#############################################################
//#############################################################
  return 0;
}
