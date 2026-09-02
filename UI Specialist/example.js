// let student = {
//     name: "John Doe",
//     age: 20,
//     course: "Computer Science",
//     greet: function() {  //Anonymous Function: iska mtlb hai ki jiska koi name nhi hai.
//         console.log("Hello");
//         return "Welcome to the course!";
//     }
// }
// console.log(student["greet"]());
// console.log(student.greet());

// function Student(name , age){
//     this.Studentname = name
//     this.Studentage = age // ab yaha this ki vjah se apne ko baar baar alg se new values nhi deni pdegi student function ko for key:value pairs. Aage apne variable me new object me values pass kar denge
// }
// s1 = new Student()
// console.log(typeof s1) // s1 ek object hai

// console.log(typeof Student) // ye ek function return krega

// console.log(this) // isko print krwane par {} bracket aayega, means empty object. yaha node ke empty object pr point kar rha ahi jo global object hai & agar browser pr krte hai to vaha par console.log() windows ka function hai to windows ka object pr point krega 

// s1 = new Student() // this keyword point krta hai ek object ko

// alert("Chal hatt") // isse alert ka popup aayega

// let p1 = new Student("Anmol", 20) // new keyword se apne function ko object me convert kr skte hai
// console.log(p1) // abi to empty object aayega
// console.log(p1.studentage);

// let p2 = new Student("Vishu", 18)
// console.log(p2) // abi to empty object aayega

// let data = {
//     name: "Anmol Singh",
//     age: 20,
//     course: "Computer Science",
//     greet: function() {
//         console.log("Hello");
//         return "Welcome to the course!";
//     }
// }


function greet(state1, state2){
    console.log(state1, state2) // this koi object ko point krta hai, and agar apne
}

let person = {
    "name": "Anmol",
    "age": 20
}

states = ["Rajasthan", "Punjab"]

// call() and apply() dono outer function ko call krte hai
greet.call(person, "Rajasthan", "Punjab") // yaha do value undefined aa rhi hai agar this.state1, this.state2 krke krenge

greet.apply(person, states) //apply() strings wgera nhi accept krta