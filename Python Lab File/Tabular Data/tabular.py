import pandas as pd

print("--- STEP 1: LOADING DATA ---")

# Hum ek simple data bana rahe hain (Dictionary se)
data = {
    'Name': ['Amit', 'Priya', 'Rahul', 'Neha', 'Suresh'],
    'Age': [20, 22, 19, 21, 23],
    'City': ['Delhi', 'Mumbai', 'Delhi', 'Pune', 'Mumbai'],
    'Marks': [85, 90, 78, 92, 60]
}

# Dictionary ko Table (DataFrame) mein load kar rahe hain
df = pd.DataFrame(data)

print("Data successfully loaded into DataFrame.")


print("\n--- STEP 2: DISPLAYING DATA ---")

# Poora table print karo
print("Full Table:")
print(df)

# Sirf upar ki 2 rows dekhne ke liye .head() use karte hain
print("\nFirst 2 Rows (Head):")
print(df.head(2))


print("\n--- STEP 3: FILTERING DATA (Chhaantna) ---")

# Condition: Humein sirf wo log chahiye jo 'Delhi' se hain
# Logic: df[ df['Column'] == 'Value' ]
delhi_students = df[df['City'] == 'Delhi']

print("Students from Delhi:")
print(delhi_students)

# Condition: Jinke marks 80 se zyada hain
toppers = df[df['Marks'] > 80]
print("\nStudents with Marks > 80:")
print(toppers)


print("\n--- STEP 4: SUMMARISING DATA (Nichod) ---")

# .describe() function automatically saara hisaab-kitaab de deta hai (Count, Mean, Min, Max)
print("Statistical Summary (Min, Max, Mean):")
print(df.describe())

# Specific cheez nikalna (Jaise Average Marks)
avg_marks = df['Marks'].mean()
print(f"\nClass Average Marks: {avg_marks}")