//
// Created by lenovo on 2023/3/16.
//
#include "encoder.h"
#include "source.h"
using namespace std;
Encoder::Encoder(int k, int v, int c, int l, int vMask):k(k), v(v), c(c), l(l) {
    if(v >= 32)
    {
        v_mask = UINT32_MAX;
    }
    else
    {
        v_mask = (1 << v) - 1;
    }
}

Encoder::Encoder() {
    k = v = c = l = 0;
    v_mask = 0;
}

void Encoder::encode(std::string &message) {
    vector<unsigned int> devidedMessage;
    devidemessage2int32(devidedMessage, message);
    vector<unsigned long long> longIntsForHash;
    generateSpinalsAndRNGS(longIntsForHash);

}

bool Encoder::devidemessage2int32(std::vector<unsigned int> &devidedMessage, std::string &message) {
    unsigned int temp;
    for (int i = 0; i < message.length(); i++)
    {
        temp = UINT32_MAX;
        temp &= int(message[i]);
        devidedMessage.push_back(temp);
    }
    return true;
}

void Encoder::generateSpinalsAndRNGS(std::vector<unsigned long long> &longIntsForHash) {
    
}



vector<uint8_t>& Encoder::getSymbols() {
    return symbols;
}

int Encoder::getK() const {
    return k;
}

int Encoder::getV() const {
    return v;
}

int Encoder::getC() const {
    return c;
}

int Encoder::getL() const {
    return l;
}

void Encoder::setK(int k) {
    Encoder::k = k;
}

void Encoder::setV(int v) {
    Encoder::v = v;
}

void Encoder::setC(int c) {
    Encoder::c = c;
}

void Encoder::setL(int l) {
    Encoder::l = l;
}
