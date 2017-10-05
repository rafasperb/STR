#include <iostream>
using namespace std;

class Tarefa
{
private:
  int id;
  int ci; //tempo de computação da tarefa (Ci)
  int si; //tempo de chegada da tarefa (Si)
  int pi; //prioridade (pi)
  int po; //politica

public:

  Tarefa();
  void inicializa(int id, int ci, int si, int pi, int po);
  int get_id();
  int get_tempocomp();
  int get_chegada();
  int get_prioridade();
  int get_politica();
  void set_id(int idd);
  void set_tempocomp(int cii);
  void set_chegada(int sii);
  void set_prioridade(int pii);
  void set_politica(int poo);
  void imprime();
};
