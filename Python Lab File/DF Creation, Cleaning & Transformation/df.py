import pandas as pd
import numpy as np

print("--- STEP 1: DATAFRAME BANANA ---")

# Data taiyar kar rahe hain (Dictionary format mein)
# Note: 'Amit' do baar hai (Duplicate) aur ek jagah Marks gayab hain (np.nan)
data = {
    'Name': ['Amit', 'Neha', 'Rahul', 'Amit', 'Priya', 'Sumit'],
    'Gender': ['M', 'F', 'M', 'M', 'F', 'M'],
    'Marks': [85, 92, np.nan, 85, 78, 45], 
    'Age': [20, 21, 22, 20, 21, 23]
}

# Dictionary ko Table (DataFrame) mein convert karna
df = pd.DataFrame(data)

print("Original Table:")
print(df)
print("\nTable Shape (Rows, Columns):", df.shape)


print("\n--- STEP 2: DATA CLEANING (SAFAI) ---")

# A. Duplicates Hatana
# Pehle check karo kitne duplicates hain
print("Duplicate Rows found:", df.duplicated().sum())

# Ab duplicates hata do (drop_duplicates)
df = df.drop_duplicates(keep='first')
print("Duplicates hata diye gaye.")

# B. Missing Value (NaN) Bharna
# Marks column mein ek jagah khali hai (NaN). Wahan hum Average Marks bhar denge.
avg_marks = df['Marks'].mean()
df['Marks'] = df['Marks'].fillna(avg_marks)

print(f"Missing Marks ki jagah Average ({avg_marks}) bhar diya.")


print("\n--- STEP 3: DATA TRANSFORMATION (BADLAV) ---")

# A. Map Function (Code ko Full Name banana)
# M -> Male, F -> Female
gender_dict = {'M': 'Male', 'F': 'Female'}
df['Gender'] = df['Gender'].map(gender_dict)
print("Gender codes 'M/F' ko 'Male/Female' mein badal diya.")

# B. Binning (Marks ko Grades mein badalna)
# 0-50: Fail, 50-75: Pass, 75-100: Excellent
bins = [0, 50, 75, 100]
labels = ['Fail', 'Pass', 'Excellent']

# pd.cut() function numbers ko category mein todta hai
df['Grade'] = pd.cut(df['Marks'], bins=bins, labels=labels)
print("Marks ke hisaab se Grades de diye.")


print("\n--- FINAL RESULT ---")
print(df)