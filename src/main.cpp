#include <iostream>
#include <random>
#include <climits>
#include "RNG.h"
#include <cstring>
#include <cstddef>
#include <vector>
#include <bitset>
#include "encoder.h"
using namespace std;

bool devidemessage2int32(std::vector<unsigned int> &devidedMessage, std::string &message,int k) {

    int pointerByte, pointerDevide;
    pointerDevide = 0;
    //边界条件：因为从0开始，第一次就会导致pointerByte++，所以从-1开始
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


int main()
{

    string a;
    int k;
    vector<unsigned int> test;
    bitset<6> bs;
    bitset<8> bc;
    cin >> a >> k;
    cout<<"origin data:"<<endl;
    for(int i = a.length() -1 ; i >= 0; i --)
    {
        bc = a[i];
        cout << bc;
    }
    cout<<endl;
    devidemessage2int32(test, a, k);
    cout<<"result:" <<endl;
    for(int i = test.size() - 1 ; i >= 0; i --)
    {
        bs = test[i];
        cout << bs;
    }
    return 0;
}