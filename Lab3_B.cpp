#include "Lab3_B.h"



namespace Lab3_B {

    // Выбор номера альтернативы
int dialog(const std::vector<std::string> msgs) {
        std::string errmsgs = "";
        int rc, i;
        do {
            std::cout << errmsgs;
            errmsgs = "Ошибка! Повторите ввод!";
            for (i = 0; i < msgs.size(); ++i)                    // Вывод списка альтернатив
                std::cout << (msgs[i]) << "\n";
            printf("Выберите: --> ");
            TernaryVectorClass::input_Type(rc, std::cin, std::cout);
        } while (rc >= msgs.size());
        return rc;
    }


    // Первая инициализация вектора
    TernaryVectorClass::TernaryVector Input() {
        std::cout << "1. Пустой вектор\n2. Вектор с n кол-вом неопределенных значений\n3. Ручное создание вектора (вектор вводится в виде строки)\n";
        int res;
        TernaryVectorClass::input_Type(res, std::cin, std::cout);
        while (res < 1 || res > 3) {
            std::cout << "Пожалуйста, выберите число от 1 до 3: ==> ";
            TernaryVectorClass::input_Type(res, std::cin, std::cout);
        }
        if (res == 1) {
            TernaryVectorClass::TernaryVector vector;
            std::cout << "Вектор успешно инициализирован.\n" << vector << '\n';
            return vector;
        }
        else if (res == 2) {
            while (true) {
                std::cout << "Пожалуйста, введите кол-во неопределенных значений в векторе: ==> ";
                int n;
                TernaryVectorClass::input_Type(n, std::cin, std::cout);
                try {
                    TernaryVectorClass::TernaryVector vector(n);
                    std::cout << "Вектор успешно инициализирован.\n" << vector << '\n';
                    return vector;
                }
                catch (const std::exception& ex) {
                    std::cout << ex.what() << std::endl;
                }
            }
        }
        else {
            while (true) {
                std::cout << "Пожалуйста, введите строку, представляющую собой троичный вектор.\n Правила \"Образования\":\n - Пробелы\\табуляция не считаются за элемент вектора;\n - Все остальные символы (за исключением 0 и 1) считаются за неопределенность;\n";
                std::string str;
                std::cin >> str;
                try {
                    TernaryVectorClass::TernaryVector vector(str);
                    std::cout << "Вектор успешно инициализирован.\n" << vector << '\n';
                    return vector;
                }
                catch (const std::exception& ex) {
                    std::cout << ex.what() << std::endl;
                }
            }
        }
    }

    // Переопределить вектор (с помощью перегруженного ">>")
    void SetVector(TernaryVectorClass::TernaryVector& vector, TernaryVectorClass::TernaryVector&) {
        std::cout << "Пожалуйста, введите строку, представляющую собой троичный вектор.\n Правила \"Образования\":\n - строкой считаются все символы до первой встречи пробела//табуляции;\n - Все остальные символы (за исключением 0 и 1) считаются за неопределенность;\n";
        TernaryVectorClass::input_Type(vector, std::cin, std::cout);
        std::cout << "Вектор успешно инициализирован.\n" << vector << '\n';
    }

    // Вывод текущего вектора
    void GetVector(TernaryVectorClass::TernaryVector& vector_1, TernaryVectorClass::TernaryVector&) {
        std::cout << vector_1;
    }

    // Дизъюнкция данного вектора со вторым вектором
    void Disjunction(TernaryVectorClass::TernaryVector& vector_1, TernaryVectorClass::TernaryVector& vector_2) {
        std::cout << "Произошла дизъюнкция:\n" << vector_1 << vector_2 << (vector_1 | vector_2);
    }

    // Конъюнкция первого вектора со вторым ветором
    void Conjunction(TernaryVectorClass::TernaryVector& vector_1, TernaryVectorClass::TernaryVector& vector_2) {
        std::cout << "Произошла конъюнкция:\n" << vector_1 << vector_2;
        std::cout << (vector_1 &= vector_2);
    }

    // Сравнить два вектора между собой
    void Comparation(TernaryVectorClass::TernaryVector& vector_1, TernaryVectorClass::TernaryVector& vector_2) {
        if (vector_1 == vector_2)
            std::cout << "Вектора полностью совпадают.\n";
        else
            std::cout << "Вектора не совпадают.\n";
    }

    //Инвертирование вектора (1 меняется на 0, 0 на 1)
    void Invertion(TernaryVectorClass::TernaryVector& vector, TernaryVectorClass::TernaryVector&) {
        ~vector;
        std::cout << "Вектор инвертирован:\n" << vector;
    }

    // Анализ определенности вектора
    void Analysis(TernaryVectorClass::TernaryVector& vector, TernaryVectorClass::TernaryVector&) {
        int rc = vector.Analysis();
        if (rc == -1)
            std::cout << "Вектор определен.\n";
        else
            std::cout << "Вектор не определен в индексе " << rc << '\n';
    }



}

