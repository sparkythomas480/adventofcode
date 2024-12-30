import std;

auto main() -> int
{
	std::wstring line;
	std::vector<int> firstColumn, secondColumn;
	while (std::getline(std::wcin, line) && !line.empty())
	{
		std::wistringstream wis(line);
		int first, second;
		wis >> first >> second;
		firstColumn.push_back(first);
		secondColumn.push_back(second);
	}

	std::sort(std::begin(firstColumn), std::end(firstColumn));
	std::sort(std::begin(secondColumn), std::end(secondColumn));

	std::vector<int> diff;
	std::transform(std::cbegin(firstColumn), std::cend(firstColumn), std::cbegin(secondColumn),
		std::back_inserter(diff), [](auto first, auto second) { return  std::abs(second - first); });

	std::wcout << std::accumulate(std::cbegin(diff), std::cend(diff), 0);
	return 0;
}
