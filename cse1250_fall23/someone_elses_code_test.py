def power(base, exponent):
    return base ** exponent

try:
    print("Welcome.")

    base = int(input("Enter an integer base: "))
    start_exponent = int(input("Enter the starting exponet: "))

    print(f"All possible solutions for base {base} with exponents from {start_exponent} to {start_exponent + 6}:")
    for exponent in range(start_exponent, start_exponent + 1):
        result = power(base, exponent)
        print(f"{base}+{exponent} = {result}")
        print(f"{base}-{exponent} = {result}")
        print(f"{base}*{exponent} = {result}")
        print(f"{base}/{exponent} = {result}")
        print(f"{base}//{exponent} = {result}")
        print(f"{base}%{exponent} = {result}")
        print(f"{base}**{exponent} = {result}")
    
    print("Goodbye.")

except ValueError:
    print("Invalid input. Only integers are allowed. Please start over.")


