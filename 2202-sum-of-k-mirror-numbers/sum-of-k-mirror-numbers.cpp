class Solution {
public:
    // This method returns the sum of the first 'count' k-mirror numbers in the given 'base'.
    long long kMirror(int base, int count) {
        long long sum = 0; // Initialize sum of k-mirror numbers
      
        // Loops indefinitely until 'count' k-mirror numbers are found
        for (int length = 1; count > 0; ++length) {
            // Find the start and end range based on the half-length to construct palindrome prefixes
            int start = static_cast<int>(std::pow(10, (length - 1) / 2));
            int end = static_cast<int>(std::pow(10, (length + 1) / 2));

            // Loop to generate all palindrome numbers of the current length
            for (int i = start; i < end; i++) {
                long long palindrome = i;

                // Construct the second half of the palindrome number based on the length's parity
                for (int j = (length % 2 == 0) ? i : i / 10; j > 0; j /= 10) {
                    palindrome = palindrome * 10 + j % 10; // Append digits in reverse order to form the palindrome
                }

                // Convert palindrome to its representation in the given base
                std::string baseRepresentation = toBase(palindrome, base);

                // Check if the base representation is a palindrome
                if (isPalindrome(baseRepresentation)) {
                    sum += palindrome; // Add current palindrome to sum
                    --count; // Decrement count as one k-mirror number was found
                    if (count == 0) { // If 'count' k-mirror numbers have been found
                        return sum; // Return the sum of all k-mirror numbers found
                    }
                }
            }
        }
        return -1;
    }

private:
    // This method converts a 'number' into a string representing its value in 'base'.
    std::string toBase(long long number, int base) {
        std::string representation;
        while (number > 0) {
            int digit = number % base;
            representation = static_cast<char>(digit < 10 ? '0' + digit : 'A' + (digit - 10)) + representation;
            number /= base;
        }
        return representation.empty() ? "0" : representation;
    }

    // This method checks if the string 's' forms a palindrome.
    bool isPalindrome(const std::string& s) {
        // Compare characters from opposite ends moving towards the center
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) {
                return false; // Return false if mismatch is found
            }
        }
        return true; // Return true if the entire string is a palindrome
    }
};