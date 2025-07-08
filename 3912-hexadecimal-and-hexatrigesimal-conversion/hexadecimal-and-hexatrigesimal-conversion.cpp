class Solution {
public:
    string convertToBase(int num, int base) {
        string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string result = "";
        if (num == 0) return "0";

        while (num > 0) {
            result += digits[num % base];
            num /= base;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string concatHex36(int n) {
        int n2 = n * n;
        int n3 = n2 * n;

        string hexStr = convertToBase(n2, 16);     // Hexadecimal (base-16)
        string base36Str = convertToBase(n3, 36);  // Hexatrigesimal (base-36)

        return hexStr + base36Str;
        }
};