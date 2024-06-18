#include "multa.hpp"
#include <vector>
#include "Usuario.hpp"
class Cliente:Usuario {
public:
	void addDivida(int dias_atraso);
	void pagarDvivida(float valor);
	bool podeEmprestar();
private:
	std::vector <Multa> multa;
protected:

};