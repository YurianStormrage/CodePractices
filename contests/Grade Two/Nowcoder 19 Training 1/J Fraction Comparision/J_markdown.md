# J. 

## 题目描述
Bobo has two fractions <font size=5>$\frac{x}{a}$</font> and <font size=5>$\frac{y}{b}$</font> . He wants to compare them. Find the result.

## 题解
签到题。唯一的难点是爆long long ~~会python~~。

## 代码
```python
while True:
    try:
        arr = input().split(' ')
        x = int(arr[0])
        a = int(arr[1])
        y = int(arr[2])
        b = int(arr[3])
        if x * b > y * a :
            print('>')
        elif x * b == y * a :
            print('=')
        else :
            print('<')
    except EOFError:
        break
```