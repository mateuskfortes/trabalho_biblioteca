#include "multa.hpp"
#include <vector>
#include "Usuario.hpp"
class Cliente:Usuario {
public:

private:
	std::vector <Multa> multa;
protected:
	void addDivida(int dias_atraso);
		void pagarDvivida(float valor);
		bool podeEmprestar();
};