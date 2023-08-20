#include "encryption.h"

Encryption::Encryption(ProtocolD_H* prot_d_h) : p_protocol_d_h_(prot_d_h) {

    if (this->p_protocol_d_h_ != nullptr) {

        this->m_key_1408_ = this->p_protocol_d_h_->getKey(); // Запись ключа в m_key_1408_

        this->keyGeneration();                               // Генерация ключа на 44 слова.
        this->dictionaryGeneration();                        // Генерация словаря (127 х 127).
        this->mixingIndex();             // Метод перемешивания массива, на основе первого значения ключа.
    }
}

Encryption::~Encryption() { if (this->p_dictionary_ != nullptr) delete[] p_dictionary_; }

void Encryption::keyGeneration() {

    for (short x = 0; x < 144; ++x)
        m_key_1408_ += m_key_1408_[x + 1] ^ m_key_1408_[x + 1] ^ m_key_1408_[x + 16];
}

char Encryption::algorithmsForCreatingDictionaries(short index_switch_, const short index_key_) {

    char temp_;

    if (index_switch_ < 6) {

        switch (index_switch_) {

        case(1): { return temp_ = m_key_1408_[index_switch_] ^ m_key_1408_[index_key_]; }

        case(2): { return temp_ = m_key_1408_[index_switch_] & m_key_1408_[index_key_] | m_key_1408_[index_key_]; }

        case(3): { return temp_ = m_key_1408_[index_switch_] | m_key_1408_[index_key_]; }

        case(4): { return temp_ = m_key_1408_[index_switch_] & m_key_1408_[index_key_]; }

        case(5): { return temp_ = m_key_1408_[index_switch_] & m_key_1408_[index_key_] ^ m_key_1408_[index_key_]; }
        }

    } else return algorithmsForCreatingDictionaries(index_switch_--, index_key_);
}

void Encryption::dictionaryGeneration() {

    this->p_dictionary_ = new std::string[127];

    short index_key_1408_ = 0;

    auto lambda = [&index_key_1408_]() {

        if (index_key_1408_ < 176) index_key_1408_++;
        else index_key_1408_ = 0;
    };

    for (short x = 0; x < 127; ++x) {

        for (short a = 0; a < 127; ++a) {

            p_dictionary_[x] += algorithmsForCreatingDictionaries(static_cast<int>
                                                                      (this->m_key_1408_[index_key_1408_]) % 5, index_key_1408_);
            lambda();
        }
        lambda();
    }
}

std::string Encryption::encryptionData(std::string &data_) {

    short count_null = ((data_.size() / 16 + 1) * 16) - data_.size();
    for (short a = 0; a < count_null; ++a) data_ += "0";

    short count_data_ = 0;
    std::string temp_data_;
    std::string result_encryption_data_;

    for (long x = 0; x < data_.size(); ++x) {

        ++count_data_;
        temp_data_ += data_[x];

        if (count_data_ == 15) {

            result_encryption_data_ += roundData(temp_data_);

            count_data_ = 0;
            temp_data_.clear();
        }
    }
    return result_encryption_data_;
}

std::string Encryption::decipherData(std::string &data_) {

    short count_data_ = 0;
    std::string temp_data_;
    std::string result_decipher_data_;

    for (long x = 0; x < data_.size(); ++x) {

        if (data_[x] == '_') ++count_data_;

        temp_data_ += data_[x];

        if (count_data_ == 16) {

            result_decipher_data_ += decipherRoundData(temp_data_);

            count_data_ = 0;
            temp_data_.clear();
        }
    }
    return result_decipher_data_;
}

std::string Encryption::roundData(std::string &data_) {

    std::string encryption_data_;

    short line_;
    short column_;
    short number_round_ = 0;

    short array_result_[16];
    short array_data_[16];

    for (short a = 0; a < 16; ++a) array_data_[a] = static_cast<short>(data_[a]);

    for (short round_ = 0; round_ < 11; ++round_) {

        for (short x = 0; x < 16; ++x) {

            line_   = static_cast<short>(this->m_key_1408_[x + 15 * number_round_] ^ '7');
            column_ = static_cast<short>(this->m_key_1408_[x + 15 * number_round_]);

            while(line_ >= 127) line_ -= 2;
            while(column_ >= 127) column_ -= 2;

            if(number_round_ == 0) array_result_[x] = (array_data_[x] + static_cast<short>(this->p_dictionary_[line_][column_]));
            else array_result_[x] += static_cast<short>(this->p_dictionary_[line_][column_]);
        }

        for (short a = 0; a < 8; ++a) std::swap(array_result_[a], array_result_[this->index_array_mixing[round_][a]]);

        ++number_round_;
    }
    for (short a = 0; a < 16; ++a) {

        encryption_data_ += std::to_string(array_result_[a]);
        encryption_data_ += '_';
    }
    return encryption_data_;
}

std::string Encryption::decipherRoundData(std::string &data_) {

    short array_data_[16];
    std::string temp_data_;
    short index_array_ = 0;

    for (short x = 0; x < data_.size(); ++x) {

        if (data_[x] != '_') temp_data_ += data_[x];

        else {
            array_data_[index_array_] = std::stoi(temp_data_);
            index_array_++;
            temp_data_.clear();
        }
    }

    short line_;
    short column_;
    short number_round_ = 10;

    for (short round_ = 11; round_ > 0; --round_) {

        for (short a = 0; a < 8; ++a) std::swap(array_data_[a], array_data_[this->index_array_mixing[number_round_][a]]);

        for (short x = 0; x < 16; ++x) {

            line_   = static_cast<short>(this->m_key_1408_[x + 15 * number_round_] ^ '7');
            column_ = static_cast<short>(this->m_key_1408_[x + 15 * number_round_]);

            while(line_ >= 127) line_ -= 2;
            while(column_ >= 127) column_ -= 2;

            array_data_[x] = array_data_[x] - static_cast<short>(this->p_dictionary_[line_][column_]);
        }
        --number_round_;
    }
    temp_data_.clear();
    for (short x = 0; x < 16; ++x) temp_data_ += array_data_[x];
    return temp_data_;
}

void Encryption::mixingIndex() {

    for (short x = 0; x < 11; ++x) {

        short dictionary_start_ = this->m_key_1408_[x];

        while (dictionary_start_ > 6) dictionary_start_ /= 2;

        for (short a = 0; a < 8; ++a) {

            std::swap(index_array_mixing[x][dictionary_start_], index_array_mixing[x][a]);
            if (dictionary_start_ < 1) dictionary_start_++;
            else if (dictionary_start_ >= 6) dictionary_start_--;
            else if (dictionary_start_ == x) dictionary_start_ = 6;
        }
    }
}
