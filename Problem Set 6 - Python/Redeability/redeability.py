from cs50 import get_string

text = get_string("Text: ")

while len(text) <= 0:
    text = get_string("Text: ")

L = 0
S = 1
P = 0

for i in text:
    if i.isalpha():
         L += 1
    elif i == " ":
        S += 1
    elif i == "." or i == "!" or i == "?":
        P += 1

AvL = (L * 100) / S
AvS = (P * 100) / S

grade = round(0.0588 * AvL - 0.296 * AvS -15.8)

if grade >= 16:
    print("Grade 16+")
elif grade <= 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")
