#include <iostream>
#include "Livros.hpp"

bool Livros::estaDisponivel() const {
	if (disponiveis > 0) {
		return true;
	}
	else {
		return false;
	}
};