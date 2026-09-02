print("--- LIST OPERATIONS (Mutable - Change ho sakti hai) ---")

# 1. List banayi
numbers = [45, 12, 89, 33, 10]
print("Original List:", numbers)

# 2. Sorting (List ko sort karna)
# .sort() function original list ko hi badal deta hai
numbers.sort()
print("Sorted List (Ascending):", numbers)

# 3. Slicing (Tukda nikalna)
# Syntax: [start : end] -> Start included, End excluded
# Humein index 1 se index 3 tak chahiye (Index 4 count nahi hoga)
# Sorted list hai: [10, 12, 33, 45, 89]
# Index 1 (12), Index 2 (33), Index 3 (45)
subset = numbers[1:4]
print("Sliced List (Index 1 to 3):", subset)


print("\n\n--- TUPLE OPERATIONS (Immutable - Change nahi hoti) ---")

# 1. Tuple banayi
fruits = ("Banana", "Apple", "Cherry", "Mango", "Papaya")
print("Original Tuple:", fruits)

# 2. Sorting Tuple
# Note: Tuple ke paas .sort() nahi hota kyunki wo change nahi ho sakti.
# Humein sorted() function use karna padta hai jo ek nayi LIST bana deta hai.
sorted_fruits = sorted(fruits)
print("Sorted Tuple (returns a List):", sorted_fruits)

# 3. Slicing Tuple
# Logic bilkul list jaisa hai. Pehle 3 fruits chahiye.
# 0 se shuru karo, 3 pe ruk jao (0, 1, 2 milenge)
first_three = fruits[0:3]
print("Sliced Tuple (First 3 items):", first_three)