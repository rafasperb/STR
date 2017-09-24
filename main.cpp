#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

//(SCHED_FIFO correspondendo a 1 e SCHED_RR, a 2)
//A descrição de cada tarefa é composta por três valores que correspondem
//respectivamente a: tempo de computação da tarefa (Ci), tempo de chegada da tarefa (Si) e prioridade
//(pi) da tarefa
int main()
{
//##############################################################
  int n; //numero de tarefas.
  int ci; //tempo de computação da tarefa (Ci)
  int si; //tempo de chegada da tarefa (Si)
  int pi; //prioridade (pi)
//##############################################################

  cin >> n;
  cout << endl;
  cin >> ci;
  cin >> si;
  cin >> pi;
  cout << endl;
  cout << endl;
  cout << "N# tarefas:" << n <<"tempo computação: " <<ci <<"tempo chegada:" << si <<"prioridade:" << pi;
  cout << endl;

  return 0;
}
