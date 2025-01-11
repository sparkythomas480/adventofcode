import std;

auto main() -> int
{
	std::wstring line;
	int numSafe = 0;
	while (std::getline(std::wcin, line))
	{
		std::wistringstream wis(line);
		int previousValue;
		wis >> previousValue;
		if (wis.fail())
			break;

		int currentValue;
		wis >> currentValue;
		if (wis.fail())
			break;

		bool increasing = currentValue > previousValue;
		bool safe = true;
		while (!wis.fail())
		{
			auto difference = currentValue - previousValue;
			if (increasing && difference < 0 || !increasing && difference > 0)
			{
				safe = false;
				break;
			}

			difference = std::abs(difference);
			if (difference < 1 || difference > 3)
			{
				safe = false;
				break;
			}

			previousValue = currentValue;
			wis >> currentValue;
		}

		if (safe)
			++numSafe;
	}

	std::wcout << numSafe;
	return 0;
}
