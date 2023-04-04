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
    int pointerByte, pointerDevide;
    pointerDevide = 0;
    pointerByte = 0;
    unsigned int extraction = 1;
    unsigned int temp_unit = 0;
    unsigned int temp;
    for(int i = 0; i <= message.length()*8; i++)
    {
        if(i % 8 == 0 && i != 0)
        {
            pointerByte++;
        }
        if(i % k == 0 && i != 0)
        {
            devidedMessage.push_back(temp_unit);
            temp_unit = 0;
            if(i == message.length()*8)
            {
                break;
            }
        }
        temp = 1 << (i % 8);
        if((message[pointerByte] & temp) == (temp))
        {
            extraction = (1 << (i % k));
        }
        else
        {
            extraction = 0;
        }

        temp_unit |= extraction;
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
