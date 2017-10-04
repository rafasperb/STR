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
  std::vector<TAREFA> fila;

	unsigned num_tarefas;
	unsigned i=0,t=0,x=0,j=0;
	char     grade[MAX_GRADE+1];
    unsigned tempo = 0;

	/* Inicia leitura... */
	scanf("%u",&num_tarefas);

		/* LEITURA */
		for (i=0;i<num_tarefas;++i) {
			tarefas[i].id = 'A'+i;
			scanf("%u %u %u %u",&(tarefas[i].c), &(tarefas[i].s),
								&(tarefas[i].p), &(tarefas[i].sched));

		if(tarefas[i].s == 0)
		{
			esperando.push_back(tarefas[i]);

		}else{
			fila.push_back(tarefas[i]);
		}

		}
		/* SIMULACAO */
		tempo = 0;
		while(num_tarefas>0){ // SAI DO LAÇO APENAS QUANDO ACABAR TODAS AS TAREFAS
		t=0;
//############################################################################
// INSERE AS TAREFAS EM ESPERANDO QUANDO S = TEMPO
//############################################################################
	for (i = 0; i < num_tarefas; i++) {
		if (fila[i].s == tempo) {
			esperando.push_back(fila[i]);
		}
	}
//############################################################################
// ORDENAR ESPERANDO NA ORDEM DE PRIORIDADE
//############################################################################
		if(esperando.size() > 0)
		{
//############################################################################
// TESTA O TIPO DE TAREFA QUE VAI PARA EXECUÇÃO
//############################################################################
			if (esperando[t].sched == 1) { //TESTA SE A TAREFA QUE ESTA ESPERANDO É FIFO
				if (esperando[t].s <= tempo) { //TESTA SE JÁ ESTA NA HORA DE EXECUTAR
					grade[tempo++] = esperando[i].id; //COLOCA PARA EXECUTAR
					esperando[i].c = esperando[i].c - 1;//DECREMENTA A COMPUTAÇÃO
					if (esperando[i].c == 0) {//VERIFICA SE TERMINOU A COMPUTAÇÃO
						esperando.erase(esperando.begin()+t);//RETIRA DA FILA ESPERANDO
						num_tarefas = num_tarefas -1;//DECREMENTA O NUMERO DE TAREFAS
					}
				}
			}else{													//A TAREFA QUE ESTA ESPERANDO É RR
				if (esperando[t].s <= tempo) {//TESTA SE JÁ ESTA NA HORA DE EXECUTAR
					grade[tempo++] = esperando[i].id;//COLOCA PARA EXECUTAR
					esperando[i].c = esperando[i].c - 1;//DECREMENTA A COMPUTAÇÃO
					if (esperando[t].c == 0) {//VERIFICA SE TERMINOU A COMPUTAÇÃO
						esperando.erase(esperando.begin()+t);//RETIRA DA FILA ESPERANDO
						num_tarefas = num_tarefas -1;//DECREMENTA O NUMERO DE TAREFAS
					}else{
						esperando.push_back(tarefas[t]);//COMO É RR, COMPUTA 1UT E VAI PRO FINAL DA FILA
					}
				}
			}
		}else{
			grade[tempo++] = '.';
		}
		tempo++;
	}

//###########################################################################

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

		/* Inicia nova leitura... */
		scanf("%u",&num_tarefas);

	return 0;
}
