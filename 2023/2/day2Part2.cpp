#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

int main()
{
    std::wifstream s("input.txt");
    std::wstring line;
    uint gamePowerSum = 0;
    while (std::getline(s, line))
    {
        std::wistringstream lineStream(line);
        std::wstring temp;
        std::getline(lineStream, temp, L':');

        uint maxRed = 0;
        uint maxBlue = 0;
        uint maxGreen = 0;
        while (std::getline(lineStream, temp, L';'))
        {
            std::wistringstream bagReachStream(temp);
            while (std::getline(bagReachStream, temp, L','))
            {
                std::wistringstream howManyColourStream(temp);
                uint count;
                std::wstring colour;
                howManyColourStream >> count >> colour;
                if (colour == L"red")
                    maxRed = std::max(maxRed, count);
                else if (colour == L"blue")
                    maxBlue = std::max(maxBlue, count);
                else
                    maxGreen = std::max(maxGreen, count);
            }
        }

        gamePowerSum += maxRed*maxBlue*maxGreen;
    }

    std::wcout << gamePowerSum;
}