#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

int main()
{
    std::wifstream s("input.txt");
    std::wstring line;
    uint gameNumberSum = 0;
    while (std::getline(s, line))
    {
        std::wistringstream lineStream(line);
        std::wstring temp;
        std::getline(lineStream, temp, L':');
        std::wistringstream gameNumberStream(temp);
        uint gameNumber;
        gameNumberStream >> temp >> gameNumber;

        bool gameValid = true;
        while (std::getline(lineStream, temp, L';') && gameValid)
        {
            std::wistringstream bagReachStream(temp);
            while (std::getline(bagReachStream, temp, L',') && gameValid)
            {
                std::wistringstream howManyColourStream(temp);
                uint count;
                std::wstring colour;
                howManyColourStream >> count >> colour;
                if (colour == L"red")
                {
                    if (count <= 12)
                        continue;
                }
                else if (colour == L"blue")
                {
                    if (count <= 14)
                        continue;
                }
                else
                {
                    if (count <= 13)
                        continue;
                }

                gameValid = false;
            }
        }

        if (!gameValid)
            continue;

        gameNumberSum += gameNumber;
    }

    std::wcout << gameNumberSum;
}