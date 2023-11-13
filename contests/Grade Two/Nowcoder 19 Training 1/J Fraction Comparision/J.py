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