public class Solution {
  public int CountDigitOne(int n) {
    int count = 0;
    int factor = 1; // Initialize the factor to 1

    while (factor <= n) {
      int divider = factor * 10;
      count += (n / divider) * factor + Math.Min(Math.Max(n % divider - factor + 1, 0), factor);
      factor *= 10;
    }

    return count;
  }
}