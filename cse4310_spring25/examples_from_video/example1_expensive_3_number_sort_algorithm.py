def three_in_order():
    x = int(input("First number: "))
    y = int(input("Second number: "))
    z = int(input("Third number: "))
    three_in_order_go(x, y, z)
    return

def three_in_order_go(x, y, z):
    if x <= y and x <= z:
        print(f"{x} ", end="")
        if y <= z:
            print(f"{y} {z}")
        else:
            print(f"{z} {y}")
    elif y <= x and y <= z:
        print(f"{y} ", end="")
        if x <= z:
            print(f"{x} {z}")
        else:
            print(f"{z} {x}")
    else:
        print(f"{z} ", end="")
        if x <= y:
            print(f"{x} {y}")
        else:
            print(f"{y} {x}")
    return

three_in_order()