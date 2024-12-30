import std;

auto main() -> int
{
	std::wstring line;
	std::vector<int> firstColumn;
	std::unordered_multiset<int> secondColumn;
	while (std::getline(std::wcin, line) && !line.empty())
	{
		std::wistringstream wis(line);
		int first, second;
		wis >> first >> second;
		firstColumn.push_back(first);
		secondColumn.insert(second);
	}

	std::wcout << std::accumulate(std::cbegin(firstColumn), std::cend(firstColumn), 0,
		[&secondColumn](const int aggregate, const int element)
		{
			return aggregate + element * static_cast<int>(secondColumn.count(element));
		});

	return 0;
}
