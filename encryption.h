#pragma once

#ifndef ENCRYPTION_AES
#define ENCRYPTION_AES

#include "protocolDH.h"
#include <iostream>

class Encryption {
public:
    Encryption(ProtocolD_H* prot_d_h);
    ~Encryption();

    std::string encryptionData(std::string &data_); // Шифрование данных
    std::string decipherData(std::string &data_);   // Расшифровака данных

private:
    void keyGeneration();                                                                // Генерация ключа (словарь на 44 слова).
    void dictionaryGeneration();                                                         // Создание словаря (двумерный массив).
    char algorithmsForCreatingDictionaries(short index_switch_, const short index_key_); // Алгоритм генерации словаря.
    std::string roundData(std::string &data_);                                           // Раунд шифрования данных.
    std::string decipherRoundData(std::string &data_);                                   // Раунд расшифровки данных.
    void mixingIndex();                                                                  // Метод перемешивания index_array_mixing.

    ProtocolD_H* p_protocol_d_h_ = nullptr;
    std::string* p_dictionary_   = nullptr; // Двумерный массив (словаря).
    std::string m_key_1408_;                // Ключ на 44 слова.

    short index_array_mixing[11][8] {       // Индекса ключей для метода mixingIndex.

        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15,
        8,  9, 10, 11,12, 13, 14, 15
    };
};

#endif
