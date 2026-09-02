const student = {
    "Full Name": "Anmol Singh",
    "Name": "Anmol",
    "age": 20,
    "marks": 95,
    "address": {
        "city": "Jaipur",
        "state": "Raj",
    }
}

// HOW TO ACCESS DATA:
console.log(student); // saara object access ho jaaega

console.log(student.Name); // student object me koi particular key access krne ke liye apne . ka use krte hai
console.log(student.age);

console.log(student.address.state); // object ke andr object (nested object) ko access aise krenge

console.log(student["Name"]); // ye dusra treeka hai access krne ka and ye tb use kr skte hai jb key/property ke name me space ho and ye . se nhi hota
console.log(student["Age"]);
console.log(student["address"]); // sirf address likhenge string me to address ki dono properties aa jaaengi
console.log(student["address"]["city"]); // nested object me particular value access krne ke liye
console.log(student["Full Name"]);


// HOW TO UPDATE DATA:
student.age = 19
console.log(student);

student.marks = 97;
console.log(student);

student["Full Name"] = "Anmol Bhambra"
console.log(student);

student.address.city = "Hanumangarh"
console.log(student);

student["address"]["state"] = "Rajasthan"
console.log(student);


// HOW TO DELETE DATA:
delete student.age
console.log(student);

delete student.address.city
console.log(student);

delete student["address"]["city"]
console.log(student);