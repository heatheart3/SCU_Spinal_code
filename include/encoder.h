//
// Created by lenovo on 2023/3/14.
//

#ifndef SPINAL_CODE_ENCODER_H
#define SPINAL_CODE_ENCODER_H
#include "RNG.h"
#include <vector>
#include <cstring>
class Encoder
{
    private:
    // k：每段message长度， v:hash后生成脊髓值长度， c生成的随机数长度， l：一共要发送的轮数
    int k, v, c,l;
    //v_mask：取位器
    int v_mask = 0;
    //RNGlist：存储M/k个随机数生成器
    std::vector<RNG *> RNGlist;
    //symbols:编码结果
    std::vector<uint8_t> symbols;

    public:
    Encoder();

    Encoder(int k, int v, int c, int l);

    void encode(std::string & message, std::vector<unsigned int> &symbols);

    bool devidemessage2int32(std::vector<unsigned int> &devidedMessage, std::string& message);

    void generateSpinalsAndRNGS(std::vector<unsigned int>& devidedMessage);

    void TwoInt32ToBytes(unsigned int data1, unsigned int data2 ,unsigned char bytes[]);

    void generateSymbols(std::vector<unsigned int> &symbols);

    void tempSymbolsToSymbols(std::vector<unsigned int> &tempSymbols, std::vector<unsigned int> &symbols);

    std::vector<uint8_t>& getSymbols();

    int getK() const;

    int getV() const;

    int getC() const;

    int getL() const;

    void setK(int k);

    void setV(int v);

    void setC(int c);

    void setL(int l);


};

#endif //SPINAL_CODE_ENCODER_H
