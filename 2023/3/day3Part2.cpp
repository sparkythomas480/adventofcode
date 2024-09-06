#include <fstream>
#include <vector>
#include <iostream>
#include <cwctype>
#include <string_view>
#include <iterator>
#include <sstream>

uint ProcessGearRatio(const std::vector<wchar_t> &pre, const std::vector<wchar_t> &current, const std::vector<wchar_t> &post, const uint index)
{
    const uint startIndex = index > 0 ? index - 1 : 0;
    const uint endIndex = index + 1;
    uint separateDigitsInSearchArea = 0;
    bool prevIsDigit = false;
    for (int i = startIndex; i <= endIndex; ++i)
    {
        const auto currentChar = pre[i];
        if (currentChar == 0)
            break;

        const auto currentIsDigit = std::iswdigit(currentChar);
        if (currentIsDigit && currentIsDigit != prevIsDigit)
            ++separateDigitsInSearchArea;

        prevIsDigit = currentIsDigit;
    }

    prevIsDigit = false;
    for (int i = startIndex; i <= endIndex; ++i)
    {
        const auto currentChar = current[i];
        if (currentChar == 0)
            break;

        const auto currentIsDigit = std::iswdigit(currentChar);
        if (currentIsDigit && currentIsDigit != prevIsDigit)
            ++separateDigitsInSearchArea;

        prevIsDigit = currentIsDigit;
    }

    prevIsDigit = false;
    for (int i = startIndex; i <= endIndex; ++i)
    {
        const auto currentChar = post[i];
        if (currentChar == 0)
            break;

        const auto currentIsDigit = std::iswdigit(currentChar);
        if (currentIsDigit && currentIsDigit != prevIsDigit)
            ++separateDigitsInSearchArea;

        prevIsDigit = currentIsDigit;
    }

    if (separateDigitsInSearchArea != 2)
        return 0;

    bool foundFirstInt = false;
    uint firstGear;

    uint startIndexPre = startIndex;
    auto currentChar = pre[startIndexPre];
    if (std::iswdigit(currentChar))
    {
        int i = startIndexPre - 1;
        for (; i >= 0 && std::iswdigit(pre[i]); --i)
            ;

        startIndexPre = i + 1;
    }

    for (uint i = startIndexPre; i <= endIndex; ++i)
    {
        currentChar = pre[i];
        if (currentChar == 0)
            break;

        if (!std::iswdigit(currentChar))
            continue;

        for (uint j = i + 1; ; ++j)
        {
            currentChar = pre[j];
            if (std::iswdigit(currentChar))
                continue;

            auto startIt = pre.begin();
            auto endIt = pre.begin();
            std::advance(startIt, i);
            std::advance(endIt, j);
            i = j;
            const std::wstring view(startIt, endIt);
            std::wistringstream s(view);
            if (!foundFirstInt)
            {
                foundFirstInt = true;
                s >> firstGear;
                break;
            }
            else
            {
                uint secondGear;
                s >> secondGear;
                return firstGear * secondGear;
            }
        }
    }

    uint startIndexCurrent = startIndex;
    currentChar = current[startIndexCurrent];
    if (std::iswdigit(currentChar))
    {
        int i = startIndexCurrent - 1;
        for (; i >= 0 && std::iswdigit(current[i]); --i)
            ;

        startIndexCurrent = i + 1;
    }

    for (uint i = startIndexCurrent; i <= endIndex; ++i)
    {
        currentChar = current[i];
        if (currentChar == 0)
            break;

        if (!std::iswdigit(currentChar))
            continue;

        for (uint j = i + 1; ; ++j)
        {
            currentChar = current[j];
            if (std::iswdigit(currentChar))
                continue;

            auto startIt = current.begin();
            auto endIt = current.begin();
            std::advance(startIt, i);
            std::advance(endIt, j);
            i = j;
            const std::wstring view(startIt, endIt);
            std::wistringstream s(view);
            if (!foundFirstInt)
            {
                foundFirstInt = true;
                s >> firstGear;
                break;
            }
            else
            {
                uint secondGear;
                s >> secondGear;
                return firstGear * secondGear;
            }
        }
    }

    uint startIndexPost = startIndex;
    currentChar = post[startIndexPost];
    if (std::iswdigit(currentChar))
    {
        int i = startIndexPost - 1;
        for (; i >= 0 && std::iswdigit(post[i]); --i)
            ;

        startIndexPost = i + 1;
    }

    for (uint i = startIndexPost; i <= endIndex; ++i)
    {
        currentChar = post[i];
        if (currentChar == 0)
            break;

        if (!std::iswdigit(currentChar))
            continue;

        for (uint j = i + 1; ; ++j)
        {
            currentChar = post[j];
            if (std::iswdigit(currentChar))
                continue;

            auto startIt = post.begin();
            auto endIt = post.begin();
            std::advance(startIt, i);
            std::advance(endIt, j);
            i = j;
            const std::wstring view(startIt, endIt);
            std::wistringstream s(view);
            if (!foundFirstInt)
            {
                foundFirstInt = true;
                s >> firstGear;
                break;
            }
            else
            {
                uint secondGear;
                s >> secondGear;
                return firstGear * secondGear;
            }
        }
    }

    return 0;
}

uint Process(const std::vector<wchar_t> &pre, const std::vector<wchar_t> &current, const std::vector<wchar_t> &post)
{
    const auto size = current.size();
    uint lineGearRatioSum = 0;
    for (uint i = 0; i < size; ++i)
    {
        auto currentCharacter = current[i];
        if (currentCharacter == 0)
            break;

        if (currentCharacter != L'*')
            continue;

        lineGearRatioSum += ProcessGearRatio(pre, current, post, i);
    }

    return lineGearRatioSum;
}

int main()
{
    std::wifstream s("input.txt");
    std::vector<wchar_t> pre(256, L'.');
    std::vector<wchar_t> current = pre;
    std::vector<wchar_t> post = pre;

    if (!s.getline(&*current.begin(), current.size()))
        return 0;

    uint totalGearRatioSum = 0;
    while (s.getline(&*post.begin(), post.size()))
    {
        totalGearRatioSum += Process(pre, current, post);
        pre.swap(current);
        current.swap(post);
    }

    post.assign(256, L'.');
    totalGearRatioSum += Process(pre, current, post);
    std::wcout << L"Total sum is: " << totalGearRatioSum << std::endl;
}