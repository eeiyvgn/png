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
    uint32_t CRC;
};

#pragma pack(pop)

int main()
{
    setlocale(LC_ALL, "Russian");

    ifstream png_file("Opera-wide.png", ios::binary);

    if (png_file.is_open())
    {
        png_file.seekg(0, ios::end);
        int fileSize = png_file.tellg();
        png_file.seekg(0, ios::beg);

        vector<char> png_data(fileSize, 0);
        png_file.read(png_data.data(), fileSize);

        size_t offset = 8;
    }

    return 0;
}
