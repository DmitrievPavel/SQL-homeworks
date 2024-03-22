#include <iostream>
#include <Windows.h>
#include "base.h"

constexpr char* settings = "host=localhost "
"port=5432 "
"dbname=homeworkbase "
"user=postgres "
"password=a1b2c3d4";

int main() {

	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	try {

		Database data(settings);
		//data.createTables();
		//data.addClient("Ivan", "Ivanov", "Ivanov@mail.ru");
		//data.addPhone(1, "88005553535");
		//data.addClient("Petr", "Petrov", "PPetrov@mail.ru");
		//data.updateClient(1, "Petr", "Ivanov", "IPmail@");
		//data.deletePhone(1);
		//data.deleteClient(1);
		data.findClient("Petr");
		std::cout << "Command complete";
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}