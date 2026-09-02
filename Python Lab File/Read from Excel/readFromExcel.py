import pandas as pd

print("--- STEP 1: EXCEL FILE BANANA (Creation) ---")

# Hum ek nakli data bana rahe hain test karne ke liye
data = {
    'Roll No': [101, 102, 103, 104],
    'Name': ['Anmol', 'Rahul', 'Priya', 'Sneha'],
    'Marks': [85, 90, 78, 92],
    'City': ['Delhi', 'Mumbai', 'Jaipur', 'Pune']
}

# Data ko Table (DataFrame) mein badla
df_create = pd.DataFrame(data)

# Ab isse Excel file mein save kar rahe hain
# 'index=False' ka matlab hai ki 0,1,2,3... numbering mat likho file mein
df_create.to_excel("student_data.xlsx", index=False)
print("Excel file 'student_data.xlsx' ban gayi hai.")


print("\n--- STEP 2: AUTOMATIC READING (Main Aim) ---")

# Yahan hum us file ko automatically read kar rahe hain
# pd.read_excel() function Excel file ko khol ke data nikaal leta hai
df_read = pd.read_excel("student_data.xlsx")

# Data ko screen par dikhana
print("File ka content ye raha:")
print(df_read)

# Hum specific column bhi padh sakte hain
print("\nSirf 'Name' wala column:")
print(df_read['Name'])