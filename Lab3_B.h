#ifndef LAB3_B_H
#define LAB3_B_H


#include <vector>
#include <string>

#include "TernaryVectorClass.h"



namespace Lab3_B {

    // Выбор номера альтернативы
int dialog(const std::vector<std::string> msgs);

    // Первая инициализация вектора
    TernaryVectorClass::TernaryVector Input();


    // Переопределить вектор (с помощью перегруженного ">>")
    void SetVector(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

    // Вывод текущего вектора
    void GetVector(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

    // Дизъюнкция данного вектора со вторым вектором
    void Disjunction(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

    // Конъюнкция первого вектора со вторым ветором
    void Conjunction(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

    // Сравнить два вектора между собой
    void Comparation(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

    //Инвертирование вектора (1 меняется на 0, 0 на 1)
    void Invertion(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

    // Анализ определенности вектора
    void Analysis(TernaryVectorClass::TernaryVector&, TernaryVectorClass::TernaryVector&);

}

#endif // !LAB3_B_H

