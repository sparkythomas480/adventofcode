using AdventOfCode.Y2023.Day4;

namespace AdventOfCode.Y2023.Day4Test;

[TestClass]
public class ScratchCardTests
{
    [TestMethod]
    [ExpectedException(typeof(ArgumentNullException))]
    public void TestConstructorThrowsArgumentNullExceptionWhenWinningNumbersNull()
    {
        var scratchCard = new ScratchCard(null!, Array.Empty<int>());
    }

    [TestMethod]
    [ExpectedException(typeof(ArgumentNullException))]
    public void TestConstructorThrowsArgumentNullExceptionWhenActualNumbersNull()
    {
        var scratchCard = new ScratchCard(Array.Empty<int>(), null!);
    }

    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenBothWinningNumbersAndActualNumbersEmpty()
    {
        var scratchCard = (IScratchCard)new ScratchCard(Array.Empty<int>(), Array.Empty<int>());
        Assert.AreEqual(0u, scratchCard.NumWinners());
    }

    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenOnlyWinningNumbersEmpty()
    {
        var scratchCard = (IScratchCard)new ScratchCard(Array.Empty<int>(), new int[] { 1, 3, 5 });
        Assert.AreEqual(0u, scratchCard.NumWinners());
    }

    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenOnlyActualNumbersEmpty()
    {
        var scratchCard = (IScratchCard)new ScratchCard(Array.Empty<int>(), new int[] { 1, 3, 5 });
        Assert.AreEqual(0u, scratchCard.NumWinners());
    }

    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenActualNumbersNotInWinningNumbers()
    {
        var scratchCard = (IScratchCard)new ScratchCard(new int[] { 10, 5, 30 }, new int[] { 25, 26 });
        Assert.AreEqual(0u, scratchCard.NumWinners());
    }

    [TestMethod]
    public void TestNumWinnersReturnsCorrectCountWhenActualNumbersInWinningNumbers()
    {
        var scratchCard = (IScratchCard)new ScratchCard(new int[] { 10, 5, 30, 26, 25, 29, 106 }, new int[] { 25, 26, 106, 95, 66 });
        Assert.AreEqual(3u, scratchCard.NumWinners());
    }
}


[TestClass]
public class ScratchCardScorerTests
{
    [TestMethod]
    [ExpectedException(typeof(ArgumentNullException))]
    public void TestScoreThrowsArgumentNullExceptionWhenArgumentIsNull()
    {
        var scratchCardScorer = (IScratchCardScorer)new ScratchCardScorer();
        Assert.AreEqual(0u, scratchCardScorer.Score(null!));
    }

    [TestMethod]
    public void TestScoreReturnsCorrectValueWhenNoWinners()
    {
        var scratchCardScorer = (IScratchCardScorer)new ScratchCardScorer();
        var mock = new Moq.Mock<IScratchCard>();
        mock.Setup(scratchCard => scratchCard.NumWinners()).Returns(0);
        Assert.AreEqual(0u, scratchCardScorer.Score(mock.Object));
    }

    [TestMethod]
    public void TestScoreReturnsCorrectValueWhenOneWinner()
    {
        var scratchCardScorer = (IScratchCardScorer)new ScratchCardScorer();
        var mock = new Moq.Mock<IScratchCard>();
        mock.Setup(scratchCard => scratchCard.NumWinners()).Returns(1);
        Assert.AreEqual(1u, scratchCardScorer.Score(mock.Object));
    }

    [TestMethod]
    public void TestScoreReturnsCorrectValueWhenFiveWinners()
    {
        var scratchCardScorer = (IScratchCardScorer)new ScratchCardScorer();
        var mock = new Moq.Mock<IScratchCard>();
        mock.Setup(scratchCard => scratchCard.NumWinners()).Returns(5);
        Assert.AreEqual(16u, scratchCardScorer.Score(mock.Object));
    }
}

[TestClass]
public class ScratchCardSerializerTests
{
    [TestMethod]
    [ExpectedException(typeof(ArgumentNullException))]
    public void TestReadObjectReturnsThrowsArgumentNullExceptionWhenArgumentNull()
    {
        ScratchCardSerializer.ReadObject(null!);
    }

    [TestMethod]
    public void TestReadObjectReturnsNullWhenTextReaderHasReadAllCharacters()
    {
        Assert.IsNull(ScratchCardSerializer.ReadObject(new StringReader(string.Empty)));
    }
}