using AdventOfCode.Y2023.Day4;

namespace AdventOfCode.Y2023.Day4Test;

[TestClass]
public class ScratchCardTests
{
    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenBothWinningNumbersAndActualNumbersEmpty()
    {
        var scratchCard = (IScratchCard)new ScratchCard(Array.Empty<int>(), Array.Empty<int>());
        Assert.AreEqual(0, scratchCard.NumWinners());
    }

    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenOnlyWinningNumbersEmpty()
    {
        var scratchCard = (IScratchCard)new ScratchCard(Array.Empty<int>(), new int[] {1, 3, 5} );
        Assert.AreEqual(0, scratchCard.NumWinners());
    }

    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenOnlyActualNumbersEmpty()
    {
        var scratchCard = (IScratchCard)new ScratchCard(Array.Empty<int>(), new int[] {1, 3, 5} );
        Assert.AreEqual(0, scratchCard.NumWinners());
    }

    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenActualNumbersNotInWinningNumbers()
    {
        var scratchCard = (IScratchCard)new ScratchCard(new int[] {10, 5, 30} , new int[] {25, 26} );
        Assert.AreEqual(0, scratchCard.NumWinners());
    }

    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenActualNumbersInWinningNumbers()
    {
        var scratchCard = (IScratchCard)new ScratchCard(new int[] {10, 5, 30, 26, 25, 29, 106} , new int[] {25, 26, 106, 95, 66} );
        Assert.AreEqual(0, scratchCard.NumWinners());
    }
}