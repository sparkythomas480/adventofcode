using AdventOfCode.Y2023.Day4;

namespace AdventOfCode.Y2023.Day4Test;

[TestClass]
public class Part1Test
{
    [TestMethod]
    public void TestAddMethod()
    {
        var part1 = new Part1();
        Assert.AreEqual(8, part1.Add(5, 3));
    }
}