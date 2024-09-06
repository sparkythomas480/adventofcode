#include <fstream>
#include <vector>
#include <iostream>
#include <cwctype>
#include <string_view>
#include <iterator>
#include <sstream>

bool IsSurroundedBySymbolChar(const std::vector<wchar_t> &pre, const std::vector<wchar_t> &current, const std::vector<wchar_t> &post, uint startIndex, uint endIndex)
{
    if (startIndex > 0)
    {
        --startIndex;
        const auto currentChar = current[startIndex];
        if (currentChar != L'.')
            return true;
    }

    const auto currentChar = current[endIndex];
    if (currentChar != L'.' && currentChar != 0)
        return true;

    for (int i = startIndex; i <= endIndex; ++i)
    {
        const auto currentCharPre = pre[i];
        if (currentCharPre == 0)
            break;

        if (!std::iswdigit(currentCharPre) && currentCharPre != L'.')
            return true;

        const auto currentCharPost = post[i];
        if (!std::iswdigit(currentCharPost) && currentCharPost != L'.')
            return true;
    }

    return false;
}

uint Process(const std::vector<wchar_t> &pre, const std::vector<wchar_t> &current, const std::vector<wchar_t> &post)
{
    uint lineTotal = 0;
    const auto size = current.size();
    for (uint i = 0; i < size; ++i)
    {
        auto currentCharacter = current[i];
        if (currentCharacter == 0)
            break;

        if (!std::iswdigit(currentCharacter))
            continue;

        uint j = i + 1;
        for (; j < size; ++j)
        {
            currentCharacter = current[j];
            if (std::iswdigit(currentCharacter))
                continue;

            break;
        }

        const auto startIndex = i;
        i = j - 1;
        if (!IsSurroundedBySymbolChar(pre, current, post, startIndex, j))
            continue;

        auto startIt = current.begin();
        auto endIt = current.begin();
        std::advance(startIt, startIndex);
        std::advance(endIt, j);
        const std::wstring view(startIt, endIt);
        std::wistringstream s(view);
        s >> j;
        lineTotal += j;
    }

    return lineTotal;
}

int main()
{
    std::wifstream s("input.txt");
    std::vector<wchar_t> pre(256, L'.');
    std::vector<wchar_t> current = pre;
    std::vector<wchar_t> post = pre;

    if (!s.getline(&*current.begin(), current.size()))
        return 0;

    uint totalSum = 0;
    while (s.getline(&*post.begin(), post.size()))
    {
        totalSum += Process(pre, current, post);
        pre.swap(current);
        current.swap(post);
    }

    post.assign(256, L'.');
    totalSum += Process(pre, current, post);
    std::wcout << L"Total sum is: " << totalSum << std::endl;
}