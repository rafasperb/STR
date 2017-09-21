#include <iostream>
using namespace std;

class Tarefa
{

  char id;
  int ci; //tempo de computação da tarefa (Ci)
  int si; //tempo de chegada da tarefa (Si)
  int pi; //prioridade (pi)

public:

  void inicializa(string n, float s);
  void deposita(float valor);
  void consulta();
  int saque(float valor);
};
