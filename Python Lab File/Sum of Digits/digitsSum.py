# 1. User se number input lo (String format mein hi rehne do)
num_str = input("Enter a multi-digit number: ")

# 2. Sum store karne ke liye variable banao
total_sum = 0

# 3. Loop chalao har digit ke liye
# Agar input "123" hai, toh loop '1', phir '2', phir '3' ke liye chalega
for digit in num_str:
    # Digit abhi text hai, usse integer (number) bana ke add karo
    total_sum = total_sum + int(digit)

# 4. Result print karo
print("The sum of digits is:", total_sum)