#include <iostream>
#include "nlohmann/json.hpp"

int main() {
	using json = nlohmann::json;

	// json json1;
	// json1["pi"] = 3.1415;
	// json1["happy"] = true;
	// json1["name"] = "Brian";
	// json1["nothing"] = nullptr;
	// json1["answer"]["everything"] = 42;
	// json1["list"] = {1, 2, 3};
	// json1["money"] = { {"currency", "BRL"}, {"value", 5.50} };

	// json json2 = {
	// 	{"pi", 3.1415},
	// 	{"happy", true},
	// 	{"name", "Brian"},
	// 	{"nothing", nullptr},
	// 	{"answer", {
	// 		{"everything", 42}
	// 	}},
	// 	{"list", {1, 2, 3}},
	// 	{"money", {
	// 		{"currency", "BRL"},
	// 		{"value", 5.50}
	// 	}}
	// };

	// std::string name = json1.value("name", "erro");
	// std::string happy = json2.value("happy", 0) == 1 ? "true" : "false";
	// double pi = json1.value("pi", 0.0);

	// std::cout << name << '\n';
	// std::cout << happy << '\n';
	// std::cout << pi << '\n';

	/*********************************/

	json json3;

	char text[] = R"(
		{
			"pi": 3.1415,
			"happy": true,
			"name": "Brian",
			"nothing": null,
			"answer": {
				"everything": 42
			},
			"list": [1, 2, 3],
			"money": {
				"currency": "BRL",
				"value": 5.50
			}
		}
	)";

	json3 = json::parse(text);
	std::cout << std::setw(4) << json3 << '\n';

	return 0;
}