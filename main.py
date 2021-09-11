def pref_func(str):
    p = [0] * len(str)
    for i in range(1, len(str)):
        j = p[i - 1]
        while j > 0 and str[i] != str[j]:
            j = p[j - 1]
        if str[i] == str[j]:
            j += 1
        p[i] = j
    return max(p)

str = input()
length = len(str)
sum = 0
for j in range(length):
    sum += len(str) - pref_func(str)
    str = str[1:]
print(sum)
