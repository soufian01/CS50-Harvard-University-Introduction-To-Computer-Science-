from cs50 import get_float # importing the get_float function from the cs50 library.

change = get_float("Change owed: ") # Ask the user for the input.
count = 0
while change < 0:
    change = get_float("Change owed: ")
    change = round(change * 100)

change = round(change * 100)

while change >= 25:
    change -= 25
    count += 1

while change >= 10:
    change -= 10
    count += 1

while change >= 5:
    change -= 5
    count += 1

while change >= 1:
    change -= 1
    count += 1

print(count) # print the final result.
