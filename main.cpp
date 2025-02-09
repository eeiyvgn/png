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

DWORD Reverse_DWord(DWORD in)
{
   return ((in>>24)&0x000000FF) | ((in>>8)&0x0000FF00) | ((in<<8)&0x00FF0000) | ((in<<24)&0xFF000000);
}

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

        while (offset + 8 <= png_data.size())
        {
            Chunk* ch = reinterpret_cast<Chunk*>(&png_data[offset]);
            uint32_t Length = Reverse_DWord(ch->Length);

            string Type(ch->Type, 4);

            cout << "Chunk: " << Type << ", Size: " << Length << endl;

            offset += 12 + Length;
        }

        cout << "File size: " << fileSize << endl;
    }

    return 0;
}
