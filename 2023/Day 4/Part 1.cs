namespace AdventOfCode.Y2023.Day4;

public interface IScratchCard
{
    int NumWinners();
}

public sealed class ScratchCard : IScratchCard
{
    private readonly int[] winningNumbers;
    private readonly int[] actualNumbers;

    public ScratchCard(IEnumerable<int> winningNumbers, IEnumerable<int> actualNumbers)
    {
        this.winningNumbers = winningNumbers.ToArray();
        Array.Sort(this.winningNumbers);
        this.actualNumbers = actualNumbers.ToArray();
    }

    int IScratchCard.NumWinners()
    {
        return this.actualNumbers.Count(n => Array.BinarySearch(this.winningNumbers, n) >= 0);
    }
}
