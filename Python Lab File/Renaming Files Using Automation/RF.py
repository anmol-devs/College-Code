import os

print("--- STEP 1: NAKLI FILES BANANA (Testing ke liye) ---")

# Ek naya folder banate hain 'MyFolder' naam ka
folder_name = "MyFolder"

# Agar folder nahi hai, toh bana do
if not os.path.exists(folder_name):
    os.mkdir(folder_name)

# Us folder mein 3 nakli files bana rahe hain
# Files ke naam honge: random1.txt, random2.txt, random3.txt
for i in range(1, 4):
    f = open(f"{folder_name}/random{i}.txt", "w")
    f.write("This is some dummy content.")
    f.close()

print(f"3 Files created inside '{folder_name}'. Check kar lo.\n")


print("--- STEP 2: RENAMING (Main Aim) ---")

# Folder ke andar ki saari files ki list nikalo
files = os.listdir(folder_name)

# Loop chalao har file par
# enumerate(files, 1) ka matlab hai ginti 1 se shuru karo (0 se nahi)
for count, filename in enumerate(files, 1):
    
    # Purana naam (Old Path)
    # Ex: MyFolder/random1.txt
    old_path = f"{folder_name}/{filename}"
    
    # Naya naam (New Path) -> Hum naam rakh rahe hain "File_1.txt", "File_2.txt"
    new_filename = f"File_{count}.txt"
    new_path = f"{folder_name}/{new_filename}"
    
    # Rename karne ka main function
    os.rename(old_path, new_path)
    
    print(f"Renamed: {filename}  -->  {new_filename}")

print("\nSuccess! Saari files rename ho gayi hain.")