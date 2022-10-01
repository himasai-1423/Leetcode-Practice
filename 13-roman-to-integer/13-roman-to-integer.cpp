class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        char previous = 0;
        for (auto iterator = s.begin(); iterator != s.end(); ++iterator) {
            switch(*iterator){
            case 'I':
                ++sum;
                break;
            case 'V':
                sum += 5;
                if (previous == 'I') sum -= 2;
                break;
            case 'X':
                sum += 10;
                if (previous == 'I') sum -= 2;
                break;
            case 'L':
                sum += 50;
                if (previous == 'X') sum -= 20;
                break;
            case 'C':
                sum += 100;
                if (previous == 'X') sum -= 20;
                break;
            case 'D':
                sum += 500;
                if (previous == 'C') sum -= 200;
                break;
            case 'M':
                sum += 1000;
                if (previous == 'C') sum -= 200;
                break;
            }
            previous = *iterator;
        }
        return sum;
    }
};