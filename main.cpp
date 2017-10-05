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
} TAREFA ;

bool comp(TAREFA const & a, TAREFA const & b)
{
	 return a.p < b.p;
}

#define MAX_TAREFAS 26
#define MAX_GRADE   8192
/* #define DEBUG */

int main() {
	TAREFA tarefas[MAX_TAREFAS];
  TAREFA aux;
  std::vector<TAREFA> prontos;
  std::vector<TAREFA> esperando;
  std::vector<TAREFA> fila;

	unsigned num_tarefas=0, num_esperando=0, num_fila=0;
	unsigned i=0,t=0,x=0,j=0;
	char     grade[MAX_GRADE+1];
  unsigned tempo = 0;

	/* Inicia leitura... */
	scanf("%u",&num_tarefas);
while(num_tarefas>0){
		/* LEITURA */
		for (i=0;i<num_tarefas;++i) {
			tarefas[i].id = 'A'+i;
			scanf("%u %u %u %u",&(tarefas[i].c), &(tarefas[i].s),
								&(tarefas[i].p), &(tarefas[i].sched));

		if(tarefas[i].s == 0)
		{
			esperando.push_back(tarefas[i]);
			num_esperando++;
			//cout << "esperando: " << esperando[i].id << endl;

		}else{
			fila.push_back(tarefas[i]);
			num_fila++;
			//cout << "fila: " << fila[i].id << endl;
		}

		}
		//cout << "sai do for"<< endl;
		// cout << "esperando: ";
		// for (i = 0; i< num_esperando; i++) {
		// 	cout << esperando[i].id;
		// }
		//  cout << endl;
		//  cout << "fila: ";
		// for (i = 0; i< num_fila; i++) {
		// 	cout << fila[i].id;
		// }
		// cout << endl;
		/* SIMULACAO */
		tempo = 0;
		while(num_tarefas>0){ // SAI DO LAÇO APENAS QUANDO ACABAR TODAS AS TAREFAS
			//cout << "while"<< endl;
		t=0;
//############################################################################
// INSERE AS TAREFAS EM ESPERANDO QUANDO S = TEMPO
//############################################################################
		for (i = 0; i < num_fila; i++) {
			if (fila[i].s == tempo) {
				esperando.push_back(fila[i]);
				//cout << "for denovo"<< endl;
				num_fila--;
				num_esperando++;
				//cout << esperando[i].id << endl;
			}
		}
//############################################################################
// ORDENAR ESPERANDO NA ORDEM DE PRIORIDADE
//############################################################################

	if (esperando.size()>0) {
		 std::sort(esperando.begin(), esperando.end(), comp);
	}
	// for (i = 0; i < esperando.size(); i++) {
	// 	for (j = i+1; j < esperando.size(); j++) {
	// 		if( esperando[i].p > esperando[j].p ){
  //                          aux = esperando[i];
  //                          esperando[i] = esperando[j];
  //                          esperando[j] = aux;
	// 											 }
	// 	}
	// }
//############################################################################
// TESTA O TIPO DE TAREFA QUE VAI PARA EXECUÇÃO
//############################################################################
		if(esperando.size() > 0)
		{
				//cout << "entrou if" << endl;
			if (esperando[t].sched == 1) { //TESTA SE A TAREFA QUE ESTA ESPERANDO É FIFO
				if (esperando[t].s <= tempo) { //TESTA SE JÁ ESTA NA HORA DE EXECUTAR
					grade[tempo] = esperando[t].id; //COLOCA PARA EXECUTAR
					esperando[t].c = esperando[t].c - 1;//DECREMENTA A COMPUTAÇÃO
					if (esperando[t].c == 0) {//VERIFICA SE TERMINOU A COMPUTAÇÃO
						esperando.erase(esperando.begin()+t);//RETIRA DA FILA ESPERANDO
						num_esperando = num_esperando -1;
						num_tarefas = num_tarefas -1;//DECREMENTA O NUMERO DE TAREFAS
					}
				}
			}else{													//A TAREFA QUE ESTA ESPERANDO É RR
				if (esperando[t].s <= tempo) {//TESTA SE JÁ ESTA NA HORA DE EXECUTAR
					grade[tempo] = esperando[t].id;//COLOCA PARA EXECUTAR
					esperando[t].c = esperando[t].c - 1;//DECREMENTA A COMPUTAÇÃO
					if (esperando[t].c == 0) {//VERIFICA SE TERMINOU A COMPUTAÇÃO
						esperando.erase(esperando.begin()+t);//RETIRA DA FILA ESPERANDO
						num_esperando = num_esperando -1;
						num_tarefas = num_tarefas -1;//DECREMENTA O NUMERO DE TAREFAS
					}else{
						esperando.push_back(tarefas[t]);//COMO É RR, COMPUTA 1UT E VAI PRO FINAL DA FILA
					}
				}
			}
		}else{
			grade[tempo] = '.';
			//tempo++;
		}
	///	cout << "Tempo: " << tempo << endl;
		//cout << "Grade: ";

		// for ( i = 0; i <= tempo; i++) {
		// 	cout << grade[i];
		//}
		//cout << endl;
		tempo++;

		//break;
	}

		/* SAIDA */
#ifdef DEBUG
		printf("Grade [%u]: ",tempo);
#endif
		printf("%s\n\n",grade);

		/* Inicia nova leitura... */
		scanf("%u",&num_tarefas);}

	return 0;
}
