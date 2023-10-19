#include <iostream>
// #include <vector>
// #include <string>
// ...
// #include <bits/stdc++.h>

// using namespace std;

int main() {
	// Desativa a sincronização dos fluxos padrões C e C++
	std::ios::sync_with_stdio(false);
	// Esvazia o std::cout antes que std::cin aceite uma entrada
	std::cin.tie(NULL);

	// cout << std::endl; == cout << '\n' << std::flush;
	// std::endl descarrega o buffer, então é mais lento que '\n'
	std::cout << "Olá, mundo!" << '\n';

	return 0;
}