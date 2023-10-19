#include <iostream>
#include <array>
#include <string>

#define nn std::cout << '\n'

void func(int* firstEl, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << *firstEl << ' ';
		firstEl++;
	}
	
	nn;
};

void print(std::string name, std::array<int, 3> arr) {
	std::cout << name << ": ";

	for (unsigned long i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << ' ';
	}
	
	nn;
};

struct Arrays {
	int values[3];
};

void print2(std::string name, std::array<Arrays, 2> arr) {
	std::cout << name << ": ";
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << arr[i].values[j] << ' ';
		}
	}

	nn;
};


int main() {
	/* Arrays são contêineres com tamanho fixo */

	/* Três formas de inicializar um array */
	std::cout << "=== Formas de inicializar um array ===\n\n";
	
	// 1) Usando inicialização de um aggregate (array ou classe especial, como struct ou union)
	// https://en.cppreference.com/w/cpp/language/aggregate_initialization
	std::cout << "1) Usando inicialização de um aggregate:\n";
	std::array<int, 3> arr1{0, 1, 2};
	std::array<int, 3> arr1_1 = {0, 1, 2};

	print("arr1", arr1);
	print("arr1_1", arr1_1);
	nn;

	// 2) Usando o construtor de cópia
	std::cout << "2) Usando o construtor de cópia:\n";
	std::array<int, 3> arr2(arr1);
	std::array<int, 3> arr2_2 = arr1;

	print("arr2", arr2);
	print("arr2_2", arr2_2);
	nn;

	// 3) Usando o construtor de movimentação
	std::cout << "3) Usando o construtor de movimentação:\n";
	std::array<int, 3> arr3 = std::array<int, 3>{0, 1, 2};

	print("arr3", arr3);
	nn;

	// Exemplo com um aggregate
	std::array<Arrays, 2> arr4 = {0, 1, 2, 3, 4, 5};
	std::array<Arrays, 2> arr4_4 = {Arrays{0, 1, 2}, Arrays{3, 4, 5}};

	print2("arr4", arr4);
	print2("arr4_4", arr4_4);
	nn; nn;



	/* Formas de acesso a elementos de um array */
	std::cout << "=== Formas de acesso a elementos de um array ===\n\n";
	std::array<int, 3> arr5 {0, 0, 0};
	print("arr5", arr5);
	nn;
	
	// 1) Usando arr.at(pos)
	// Ele checa pelos limites do array e retorna uma exceção 'std::out_of_range'
	std::cout << "1) Usando arr.at(pos):\n";
	arr5.at(0) = 1; // {1, 0, 0}
	int a = arr1.at(1); // a == 1

	print("arr5", arr5);
	std::cout << "a: " << a << '\n';
	nn;

	// 2) Usando arr[pos]
	// É mais eficiente que .at(pos), mas não checa os limites
	std::cout << "2) Usando arr[pos]:\n";
	arr5[2] = 3; // {1, 0, 3}
	int b = arr5[2]; // b == 3

	print("arr5", arr5);
	std::cout << "b: " << b << '\n';
	nn;

	// 3) Usando std::get<pos>(arr)
	// Não checa os limites, mas acessa a constante de tempo de compilação 'pos'
	std::cout << "3) Usando std::get<pos>(arr):\n";
	std::get<1>(arr5) = 4; // {1, 4, 3}
	int c = std::get<1>(arr5); // c == 4

	print("arr5", arr5);
	std::cout << "c: " << c << '\n';
	nn;

	// 4) Usando arr.front()
	// Retorna o 1º elemento. É equivalente a *arr.begin()
	std::cout << "4) Usando arr.front():\n";
	int front = arr5.front(); // front == 1
	int ffront = *arr5.begin(); // ffront == 1

	print("arr5", arr5);
	std::cout << "front: " << front << '\n';
	std::cout << "ffront: " << ffront << '\n';
	nn;

	// 5) Usando arr.back()
	// Retorna o último elemento
	std::cout << "5) Usando arr.back():\n";
	int back = arr5.back(); // back == 3

	print("arr5", arr5);
	std::cout << "back: " << back << '\n';
	nn;

	// 6) Usando arr.data()
	// Retorna um ponteiro para o 1º elemento do array
	// Pode ser usado como argumento de uma função, por exemplo
	std::cout << "6) Usando arr.data():\n";
	std::array<int, 3> arr6 {9, 8, 7};

	print("arr6", arr6);
	func(arr6.data(), arr6.size());
	nn; nn;



	/* Iterar por um array */
	std::cout << "=== Iterar por um array ===\n\n";
	std::array<int, 3> arr7 {11, 12, 13};
	print("arr7", arr7);

	// 1)
	for (unsigned long i = 0; i < arr7.size(); i++) {
		std::cout << arr7[i] << ' ';
	}
	nn;

	// 2)
	for (auto el : arr7) {
		std::cout << el << ' ';
	}
	nn; nn; nn;



	/* Mais funções de arrays */
	std::cout << "=== Mais funções de arrays ===\n\n";
	std::array<int, 3> arr8 {9, 99, 999};
	print("arr8", arr8);

	// arr.fill(val)
	// Preencher um array com algum valor após a inicialização
	arr8.fill(0);
	print("arr8.fill(0)", arr8);

	return 0;
}