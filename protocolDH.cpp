#include "protocolDH.h"

ProtocolD_H::ProtocolD_H(Generation index) {

    p_public_index_a_   = new short[MAX_];
    p_private_index_b_  = new short[MAX_];
    p_public_index_mod_ = new short[MAX_];

    for (short b = 0; b < MAX_; ++b) p_private_index_b_[b] = generationRandomIndex(5);

    if (index == Generation::generationIndex) {

        for (int a = 0; a < MAX_; ++a) p_public_index_a_[a]   = generationRandomIndex(500);
        for (int c = 0; c < MAX_; ++c) p_public_index_mod_[c] = generationRandomIndex(31);

        this->calculationIndex();
    }
}

ProtocolD_H::~ProtocolD_H() {

    delete[] p_public_index_a_;
    delete[] p_private_index_b_;
    delete[] p_public_index_mod_;

    if (m_public_result_index_A_ != nullptr) delete[] m_public_result_index_A_;

    if (m_result_index_client_A_ != nullptr) delete[] m_result_index_client_A_;
}

std::string ProtocolD_H::getKey() {

    return this->m_key_256_;
}

std::string ProtocolD_H::getindexStartKey() {

    std::string temp_;
    for (short a = 0; a < MAX_; ++a) {

        temp_ += std::to_string(p_public_index_a_[a]);
        temp_ += '_';
    }

    temp_ += "//";

    for (int a = 0; a < MAX_; ++a) {

        temp_ += std::to_string(p_public_index_mod_[a]);
        temp_ += '_';
    }
    return temp_;
}

std::string ProtocolD_H::getindexResultKey() {

    if (this->m_public_result_index_A_ != nullptr) {

        std::string temp_;
        for (short a = 0; a < MAX_; ++a) {

            temp_ += std::to_string(m_public_result_index_A_[a]);
            temp_ += '_';
        }
        return temp_;
    }
    else return " ";
}

void ProtocolD_H::indexStartClient(std::string key_client) {

    std::string temp_;
    int b = 0;

    for (unsigned long long a = 0; a < key_client.size(); ++a) {

        if (key_client[a] != '_' && key_client[a] != '/') {

            temp_ += key_client[a];

        } else {

            if (!temp_.empty()) {

                if (b < 32) this->p_public_index_a_[b] = static_cast<short>(std::stoi(temp_));

                else p_public_index_mod_[b - 32] = static_cast<short>(std::stoi(temp_));

                temp_.clear();
                b++;

                continue;
            }
        }
    }
    this->calculationIndex();
}

void ProtocolD_H::indexResultClient(std::string key_client) {

    std::string temp_;

    m_result_index_client_A_ = new short[MAX_];

    int index_a_ = 0;

    for (unsigned long long a = 0; a < key_client.size(); ++a) {

        if (key_client[a] != '_') {

            temp_ += key_client[a];

        } else {

            this->m_result_index_client_A_[index_a_] = static_cast<short>(std::stoi(temp_));

            index_a_++;

            temp_.clear();
            continue;
        }
    }
}

void ProtocolD_H::generationKey() {

    short result_ = 0;
    for (int a = 0; a < 32; ++a) {

        result_ = ((quint64(std::pow(this->m_result_index_client_A_[a], this->p_private_index_b_[a])))
                   % this->m_table_prime_numbers_[p_public_index_mod_[a]]) + 50;

        while (result_ < 1)  result_++;
        while (result_ > 127) --result_;
        this->m_key_256_ += result_;
    }
}

short ProtocolD_H::generationRandomIndex(const short max_value) {

    unsigned long long result_rdrand32_step = QRandomGenerator::global()->generate();

    unsigned short random = __rdtsc();
    unsigned long long result_random_ = result_rdrand32_step /= random;

    while (result_random_ > max_value) result_random_ /= 2;

    return result_random_;
}

void ProtocolD_H::calculationIndex() {

    m_public_result_index_A_ = new short[MAX_];

    for (short a = 0; a < MAX_; ++a) m_public_result_index_A_[a] = ((quint64 (std::pow(this->p_public_index_a_[a], this->p_private_index_b_[a])))
                                       % this->m_table_prime_numbers_[p_public_index_mod_[a]]);
}
