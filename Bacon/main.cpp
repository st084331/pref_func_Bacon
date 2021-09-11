#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::string str;
    std::cin >> str;
    int length = str.length();
    std::vector<int> prefix(length + 1);
    int counter = 0;
    for (int i = 0; i < length; i++) {
        prefix[1] = 0;
        int current = 0;
        int max = 0;
        for (int j = 1; j < length; j++) {
            while (true) {
                if (str[j] == str[current]) {
                    current++;
                    break;
                }
                if (current == 0) {
                    break;
                }
                current = prefix[current];
            }
            prefix[j + 1] = current;
            max = std::max(max, current);
        }
        counter += str.length() - max;
        str.erase(str.begin());
    }
    printf("%d\n", counter);
    return 0;
}
