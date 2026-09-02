# 1. Ask user for total count
n = int(input("Enter how many numbers you want to check: "))

# 2. Create an empty list
numbers = []

print("Enter the numbers:")
# Loop to take input n times
for i in range(n):
    val = int(input())
    numbers.append(val)

# 3. Logic to find Maximum
# Hum maan lete hain ki pehla number hi sabse bada hai
max_val = numbers[0]

# Ab baaki sab se compare karenge
for x in numbers:
    if x > max_val:
        max_val = x  # Agar bada number mila, toh update kar do

# 4. Print the result
print("The Maximum value is:", max_val)