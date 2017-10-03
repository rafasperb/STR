#include <stdio.h>

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
	unsigned num_tarefas;
	unsigned i;
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

    

		/* provisorio... */
		tempo = 0;
		for (i=0;i<num_tarefas;++i)
			grade[tempo++] = tarefas[i].id;
		grade[tempo] = '\0';

		/* SAIDA */
#ifdef DEBUG
		printf("Grade [%u]: ",tempo);
#endif
		printf("%s\n\n",grade);

		/* Inicia nova leitura... */
		scanf("%u",&num_tarefas);
	}
	return 0;
}
