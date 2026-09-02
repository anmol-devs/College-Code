# --- STEP 0: Pehle ek sample file bana lete hain (Sirf testing ke liye) ---
# Agar aapke paas pehle se file hai toh ye step hata sakte hain
content = "Ye hai ek temporary content in the source file!!"
f = open("source.txt", "w")
f.write(content)
f.close()
print("Note: 'source.txt' file bana di gayi hai testing ke liye.\n")

# --- MAIN PRACTICAL CODE STARTS HERE ---

# 1. Jis file se copy karna hai usse kholo (Read Mode 'r')
file_read = open("source.txt", "r")

# 2. Saara data padh lo
data = file_read.read()

# 3. Jis file mein copy karna hai usse kholo (Write Mode 'w')
# Agar file nahi hogi toh Python khud bana dega
file_write = open("destination.txt", "w")

# 4. Data ko nayi file mein likh do (Copying)
file_write.write(data)

# 5. Word Counting Logic
# split() function pure sentence ko tod kar list bana deta hai words ki
# Jaise "Hello world" ban jayega ['Hello', 'world']
words_list = data.split()
total_words = len(words_list)

# 6. Files ko band karna zaroori hai (Save karne ke liye)
file_read.close()
file_write.close()

# 7. Output show karo
print("Success! Data copied from 'source.txt' to 'destination.txt'")
print("Original Content:", data)
print("Total number of words:", total_words)