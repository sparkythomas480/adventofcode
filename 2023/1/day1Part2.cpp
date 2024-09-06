#include <fstream>
#include <string>
#include <string_view>
#include <iostream>
#include <array>
#include <algorithm>

int main()
{
    constexpr std::wstring_view digits{L"123456789"};
    std::wifstream s("input.txt");
    std::wstring line;
    static const std::array<const std::wstring, 9> numbers{L"one", L"two", L"three", L"four", L"five", L"six", L"seven", L"eight", L"nine"};
    uint total = 0;
    while (std::getline(s, line))
    {
        auto firstDigitPos = line.find_first_of(digits);
        uint firstDigit = line[firstDigitPos] - L'0';
        const auto beforeFirstDigit = line.substr(0, firstDigitPos);
        firstDigitPos = std::wstring::npos;
        for (uint i = 0; i < numbers.size(); ++i)
        {
            const auto pos = beforeFirstDigit.find(numbers[i]);
            if (pos == std::wstring::npos)
                continue;

            if (firstDigitPos != std::wstring::npos && firstDigitPos < pos)
                continue;

            firstDigitPos = pos;
            firstDigit = i + 1;
        }

        auto lastDigitPos = line.find_last_of(digits);
        uint lastDigit = line[lastDigitPos] - L'0';
        const auto afterLastDigit = line.substr(lastDigitPos + 1);
        lastDigitPos = std::wstring::npos;
        for (uint i = 0; i < numbers.size(); ++i)
        {
            const auto pos = afterLastDigit.rfind(numbers[i]);
            if (pos == std::wstring::npos)
                continue;

            if (lastDigitPos != std::wstring::npos && lastDigitPos > pos)
                continue;

            lastDigitPos = pos;
            lastDigit = i + 1;
        }

        total += firstDigit * 10 + lastDigit;
    }

    std::wcout << total;
}
