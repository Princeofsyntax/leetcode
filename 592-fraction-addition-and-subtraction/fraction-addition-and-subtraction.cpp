class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    string fractionAddition(std::string expression) {
        int numerator = 0;
        int commonDenominator = 6 * 7 * 8 * 9 * 10;
      
        if (isdigit(expression[0])) {
            expression = "+" + expression;
        }
      
        size_t i = 0;
        size_t lengthOfExpression = expression.size();
      
        while (i < lengthOfExpression) {
            int sign = expression[i] == '-' ? -1 : 1;
            i++; 
          
            size_t j = i;
            while (j < lengthOfExpression && expression[j] != '+' && expression[j] != '-') {
                j++;
            }
          
            string fraction = expression.substr(i, j - i);
            size_t slashPosition = fraction.find('/');
            int currentNumerator = stoi(fraction.substr(0, slashPosition));
            int currentDenominator = stoi(fraction.substr(slashPosition + 1));
          
         numerator += sign * currentNumerator * commonDenominator / currentDenominator;
          
            
            i = j;
        }
      
        
        int greatestCommonDivisor = gcd(abs(numerator), commonDenominator);
        numerator /= greatestCommonDivisor;
        commonDenominator /= greatestCommonDivisor;
      
        return std::to_string(numerator) + "/" + std::to_string(commonDenominator);
    }

};