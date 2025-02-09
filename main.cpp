#include <iostream>
#include <fstream>
#include <vector>
#include <locale>
#include <windows.h>
#include <string>
#include <cstdint>

using namespace std;

#pragma pack(push, 1)

struct Chunk
{
    uint32_t Length;
    char Type[4];
    vector<char> Data;
    uint32_t CRC;
};

#pragma pack(pop)

int main()
{
    setlocale(LC_ALL, "Russian");

    return 0;
}
