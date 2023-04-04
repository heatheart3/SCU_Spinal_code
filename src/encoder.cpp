//
// Created by lenovo on 2023/3/16.
//
#include "encoder.h"
#include "source.h"
#include "spookyhash.h"
using namespace std;
Encoder::Encoder(int k, int v, int c, int l):k(k), v(v), c(c), l(l) {
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

void Encoder::encode(std::string &message, std::vector<unsigned int> &symbols) {
    vector<unsigned int> devidedMessage;
    vector<unsigned int> tempSymbols;

    devidemessage2int32(devidedMessage, message);
    generateSpinalsAndRNGS(devidedMessage);
    generateSymbols(tempSymbols);

}
// 将message分割为长度为K的多段信息，放入数组中保存

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

void Encoder::generateSpinalsAndRNGS(std::vector<unsigned int> &devidedMessage) {
    vector<unsigned int>spinalValues;
    unsigned char temp_bytes[8];
    SpookyHash s;
    RNG* temp_rng;
    unsigned int temp_spinal_value;

    temp_spinal_value = ORISPINAL;
    spinalValues.push_back(temp_spinal_value);
    for(int i = 0; i < devidedMessage.size(); i++)
    {
        TwoInt32ToBytes(spinalValues[i], devidedMessage[i], temp_bytes);
        temp_spinal_value = s.Hash32(temp_bytes, 8, 0) & this->v_mask;
        spinalValues.push_back(temp_spinal_value);
        temp_rng = new RNG(this->c, temp_spinal_value);
        (this->RNGlist).push_back(temp_rng);
    }

}
// 将两个32位整形拼成8个Bytes的数组，其中data1存于数组前4个元素，data2存于数组后4元素
void Encoder::TwoInt32ToBytes(unsigned int data1, unsigned int data2, unsigned char bytes[])
{
    for(int i = 0; i < 8; i++)
    {
        if(i < 4)
            bytes[i] = UINT8_MAX & (data1>>(8*i));
        else
            bytes[i] = UINT8_MAX & (data2 >> (8*(i - 4)));
    }
}

void Encoder::generateSymbols(std::vector<unsigned int> &symbols) {
    int temp_num = this->RNGlist.size();
    vector<unsigned int> tempSymbols;
    for (int i = 0; i < (this->l * (temp_num)); i++)
    {
        tempSymbols.push_back(this->RNGlist[i % temp_num]->RNGnext());
    }
    tempSymbolsToSymbols(tempSymbols,symbols);
}

void Encoder::tempSymbolsToSymbols(std::vector<unsigned int> &tempSymbols, std::vector<unsigned int> &symbols) {
    unsigned int temp_symbol, symbol = 0;
    unsigned int temp_symbols_pointer = 0, symbols_pointer = 0;
    for(int i = 0; i < (tempSymbols.size() * this->c) + 1; i++)
    {
        if(i != 0 && i % c == 0)
        {
            temp_symbols_pointer++;
        }
        if(i != 0 && i % (sizeof (unsigned int) * 8) == 0 )
        {
            symbols.push_back(symbol);
            symbol = 0;
        }
        //边界条件
        if(i == tempSymbols.size() * this->c)
        {
            symbols.push_back(symbol);
            symbol = 0;
            break;
        }
        if(tempSymbols[temp_symbols_pointer] & (1 << i % this->c))
        {
            symbol |= (1 << i % (sizeof(unsigned int) *8));
        }
        else
        {
            symbol |= 0;
        }

    }
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
