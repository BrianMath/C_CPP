#include <iostream>
#include <vector>

#define nn << '\n'
#define printn std::cout nn

int main() {
	// std::vector[] não checa pelos limites
	// É mais rápido que acessar por .at()
	std::vector<int> v{1, 2, 3, 4};

	for (std::size_t i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	printn nn;

	/*****************************/
	
	// std::vector.at() checa por limites e retorna uma exceção 'std::out_of_range' 
	// É mais lento que acessar por []

	std::vector<int> v1 = {4, 3, 2, 1};

	for (std::size_t i = 0; i < v.size(); i++) {
		std::cout << v1.at(i) << " ";
	}
	printn nn;

	/****************************/

	std::vector<int> v2;

	for (std::size_t i = 0; i < 5; i++) {
		v2.push_back(i);
		std::cout << v2.back() << " ";
	}
	printn nn;

	int total = 0;
	while (!v2.empty()) {
		total += v2.back();
		v2.pop_back();
	}
	std::cout << "Total do vetor v2: " << total;

	printn;
	
	return 0;
}