# 1. User se pucho list mein kitne numbers hain
n = int(input("Enter total numbers in list: "))

# 2. List banao aur input lo
numbers = []
print(f"Enter {n} numbers:")

for i in range(n):
    val = int(input())
    numbers.append(val)

# 3. User se pucho kya dhoondna hai
target = int(input("Enter number to search: "))

# 4. Search Logic (Linear Search)
found = False  # Ek jhanda (flag) maante hain ki abhi nahi mila

for i in range(n):
    # Check karo kya current number target ke barabar hai?
    if numbers[i] == target:
        print(f"Success! {target} found at Index {i} (Position {i+1})")
        found = True  # Jhanda upar karo (mil gaya)
        break         # Mil gaya toh aage dhundne ki zaroorat nahi

# 5. Agar loop khatam hone ke baad bhi nahi mila
if found == False:
    print("Not Found! Number list mein nahi hai.")