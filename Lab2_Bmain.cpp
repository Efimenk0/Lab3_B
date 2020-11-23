#include "Lab2_B.h"

extern const char* msgs[];

void (*fptr[])(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&) = { Lab2_A::SetVector, Lab2_A::GetVector, Lab2_A::Disjunction, Lab2_A::Conjunction, Lab2_A::Comparation, Lab2_A::Invertion, Lab2_A::Analysis };

int main() {
	setlocale(0, "");
	std::cout << "Пожалуйста, выберите способ инициализации 1-ого вектора:\n";
	TernaryVectorClass::TernaryVector vector_1 = Lab2_A::Input();
	std::cout << "Пожалуйста, выберите способ инициализации 2-ого вектора:\n";
	TernaryVectorClass::TernaryVector vector_2 = Lab2_A::Input();
	TernaryVectorClass::TernaryVector vectors[2] = { vector_1, vector_2 };
	int choose;
	while (true) {
		std::cout << "Пожалуйста, выберите вектор, с которым хотите работать:\n 1 - первый вектор;\n 2 - второй ветор;\n --> ";
		TernaryVectorClass::input_Type(choose, std::cin, std::cout);
		while (choose < 1 || choose > 2) {
			std::cout << "Пожалуйста, выберите число от 1 до 2: ==> ";
			TernaryVectorClass::input_Type(choose, std::cin, std::cout);
		}
		std::cout << "Вы выбрали " << choose << " вектор;\n";
		int rc;
		rc = Lab2_A::dialog(msgs, NMsgs);
		if (!rc)
			break;
		fptr[rc - 1](vectors[choose - 1], vectors[choose % 2]);
	}
	return 0;
}