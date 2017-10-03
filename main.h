#include <iostream>
using namespace std;

class Tarefa
{

  int id;
  int ci; //tempo de computação da tarefa (Ci)
  int si; //tempo de chegada da tarefa (Si)
  int pi; //prioridade (pi)
  int po; //politica

public:

  void inicializa(int id, int ci, int si, int pi, int po);
  int get_id();
  int get_tempocomp();
  int get_chegada();
  int get_prioridade();
  int get_politica();
  void set_id(int id);
  void set_tempocomp(int ci);
  void set_chegada(int si);
  void set_prioridade(int pi);
  void set_politica(int po);
  void imprime();
};
