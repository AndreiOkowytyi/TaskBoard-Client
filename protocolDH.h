#pragma once

#ifndef PROTOCOLD_H
#define PROTOCOLD_H

#include <intrin.h>
#include <string>
#include <cmath>
#include <QRandomGenerator>

#define MAX_ 32

enum class Generation {

    noGenerationIndex,
    generationIndex
};

class ProtocolD_H {
public:
    ProtocolD_H(Generation index);
    ~ProtocolD_H();

    void indexStartClient (std::string key_client); // Метод принимает стартовые значения расчета ключа.
    void indexResultClient(std::string key_client); // Метод принимает результаты расчета через mod.

    std::string getindexStartKey();  // Возвращает стартовые публичные значения.
    std::string getindexResultKey(); // Возвращает результат расчетов через mod.

    std::string getKey(); // Возвращает ключ.
    void generationKey(); // Метод генерации ключа.

private:
    short generationRandomIndex(const short max_value); // Метод генерирует случайные стартовые значения.
    void calculationIndex();                            // Первый этап расчета ключа.

    std::string m_key_256_;

    short *p_public_index_a_   = nullptr; // Публичное значение что передаються, или же формируеться.
    short *p_public_index_mod_ = nullptr; // mod публичное значение что передаються, или же формируеться.
    short *p_private_index_b_  = nullptr; // Степень формулы являеться приватной.

    short* m_public_result_index_A_ = nullptr; // Результат первого этапа расчета .
    short* m_result_index_client_A_ = nullptr; // Результат первого этапа расчета что был сделанный клиентом, и передаеться getindexResultKey.

    short m_table_prime_numbers_[MAX_] { // Таблица простых чисел.

        2,   3,    5,   7,  11,  13,  17,  19,
        23,  29,  31,  37,  41,  43,  47,  53,
        59,  61,  67,  71,  73,  79,  83,  89,
        97, 101, 103, 107, 109, 113, 127, 131
    };
};

#endif
