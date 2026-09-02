# --- PART 1: DICTIONARY (Sorting) ---
print("--- DICTIONARY OPERATIONS ---")

# Ek dictionary banayi: Subject (Key) aur Marks (Value)
marks = {
    "Maths": 85,
    "English": 78,
    "Science": 92,
    "History": 65
}

print("Original Dictionary:", marks)

# 1. Sorting by Keys (Subject Name A-Z)
# sorted() function sirf keys ki list deta hai sort karke
print("\nSorted by Subject (Keys):")
for subject in sorted(marks):
    print(f"{subject}: {marks[subject]}")

# 2. Sorting by Values (Marks Low to High)
# Note: Iske liye hum ek simple trick use karte hain (Lambda function)
# x[1] ka matlab hai hum value (marks) ke hisaab se sort kar rahe hain
sorted_by_marks = sorted(marks.items(), key=lambda x: x[1])

print("\nSorted by Marks (Values):")
for item in sorted_by_marks:
    print(f"{item[0]}: {item[1]}")


# --- PART 2: SETS (Operations) ---
print("\n\n--- SET OPERATIONS ---")

# Do Sets banaye (A aur B)
set_A = {1, 2, 3, 4, 5}
set_B = {4, 5, 6, 7, 8}

print(f"Set A: {set_A}")
print(f"Set B: {set_B}")

# 1. Union (Sab kuch mila ke, bina repeat kiye) | symbol use hota hai
print("\n1. Union (A | B):", set_A | set_B)

# 2. Intersection (Jo dono mein common hai) & symbol use hota hai
print("2. Intersection (A & B):", set_A & set_B)

# 3. Difference (Jo A mein hai par B mein nahi) - symbol use hota hai
print("3. Difference (A - B):", set_A - set_B)