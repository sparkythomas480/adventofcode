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
        if (winningNumbers is null)
            throw new ArgumentNullException(nameof(winningNumbers), "The winning numbers parameter must be non null.");

        if (actualNumbers is null)
            throw new ArgumentNullException(nameof(actualNumbers), "The actual numbers parameter must be non null.");

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
        if (scratchCard is null)
            throw new ArgumentNullException(nameof(scratchCard), "The scratch card parameter must be non null.");

        var numWinners = scratchCard.NumWinners();
        return numWinners == 0u ? 0u : (1u << (int)numWinners - 1);
    }
}

public static class ScratchCardSerializer
{
    public static IScratchCard? ReadObject(TextReader textReader)
    {
        if (textReader is null)
            throw new ArgumentNullException(nameof(textReader), "The text reader parameter must be non null.");

        var line = textReader.ReadLine();
        if (line is null)
            return null;

        var splitLine = line.Split(new char[] {':', '|'}, StringSplitOptions.TrimEntries); // Brittle
        if (splitLine.Length != 3)
            throw new ArgumentException("The line is a valid serialized object: {splitLine}", nameof(textReader));

        throw new NotImplementedException();
    }
}