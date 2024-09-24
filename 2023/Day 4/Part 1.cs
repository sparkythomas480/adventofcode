namespace AdventOfCode.Y2023.Day4;

public interface IScratchCard
{
    uint NumWinners();
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

    uint IScratchCard.NumWinners()
    {
        return (uint)this.actualNumbers.Count(n => Array.BinarySearch(this.winningNumbers, n) >= 0);
    }
}

public interface IScratchCardScorer
{
    uint Score(IScratchCard scratchCard);
}

public sealed class ScratchCardScorer : IScratchCardScorer
{
    uint IScratchCardScorer.Score(IScratchCard scratchCard)
    {
        throw new NotImplementedException();
    }
}