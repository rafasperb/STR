#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

typedef struct {
	char	 id;
	unsigned c;
	unsigned s;
	unsigned p;
	unsigned sched;
}   TAREFA;

#define MAX_TAREFAS 26
#define MAX_GRADE   8192
/* #define DEBUG */

int main() {
	TAREFA tarefas[MAX_TAREFAS];
  TAREFA aux;
  std::vector<TAREFA> prontos;
  std::vector<TAREFA> esperando;
  std::vector<TAREFA> executando;

	unsigned num_tarefas;
	unsigned i,x,j=0;
	char     grade[MAX_GRADE+1];
    unsigned tempo = 0;

	/* Inicia leitura... */
	scanf("%u",&num_tarefas);
	while (num_tarefas > 0) {

		/* LEITURA */
		for (i=0;i<num_tarefas;++i) {
			tarefas[i].id = 'A'+i;
			scanf("%u %u %u %u",&(tarefas[i].c), &(tarefas[i].s),
								&(tarefas[i].p), &(tarefas[i].sched));
		}
		/* SIMULACAO */

    for(i=0; i<num_tarefas; i++) // coloca todas as tarefas na na fila de espera
    {
      esperando.push_back(tarefas[i]);
    }

    tempo = 0;

    for(i=0; i<num_tarefas; i++)
      {
        if (esperando[i].s == tempo) {
          executando.push_back(esperando[i]);
          esperando.erase(esperando.begin()+i);
          //num_tarefas--;
          i--;
        }
      }

    while (esperando.size() > 0)
    {

      for(i=0; i<num_tarefas; i++)
        {
          if (esperando[i].s == tempo) {
            executando.push_back(esperando[i]);
            esperando.erase(esperando.begin()+i);
            //num_tarefas--;
            i--;
          }
        }

    if(executando.size() == 0)
    {
      grade[tempo++] = '.';
      //tempo++;
    }

    while(executando.size() > 0)
    {
    x=0;
    grade[tempo++] = executando[x].id;
    executando[x].c = executando[x].c-1;

    if(executando[x].c == 0)
    {
      executando.erase(executando.begin()+x);
    }

    if(executando[x].sched == 2)
    {
      executando.push_back(executando[x]);
    }

    for(i=0; i<num_tarefas; i++)
      {
        if(esperando[i].s == tempo) {
          executando.push_back(esperando[i]);
          esperando.erase(esperando.begin()+i);
          //num_tarefas--;
          i--;
        }
      }
      tempo++;
    }

		/* provisorio... */
		//tempo = 0;
		//for (i=0;i<num_tarefas;++i)
		//	grade[tempo++] = tarefas[i].id;
		//grade[tempo] = '\0';

		/* SAIDA */
#ifdef DEBUG
		printf("Grade [%u]: ",tempo);
#endif
		printf("%s\n\n",grade);
  }
		/* Inicia nova leitura... */
		scanf("%u",&num_tarefas);
	}
	return 0;
}
