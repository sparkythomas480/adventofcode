#include <fstream>
#include <string>
#include <string_view>
#include <iostream>

int main()
{
    constexpr std::wstring_view digits{L"0123456789"};
    std::wifstream s("input.txt");
    std::wstring line;
    uint total = 0;
    while (std::getline(s, line))
    {
        const auto firstDigitPos = line.find_first_of(digits);
        total += (line[firstDigitPos] - L'0') * 10;
        const auto lastDigitPos = line.find_last_of(digits);
        total += line[lastDigitPos] - L'0';
    }

    std::wcout << total;
}
