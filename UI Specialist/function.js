function greet(Name) {
    console.log("Mood Gorning,", Name, "😊"); // jo bhi code apne function ke andr likhte hai use function expressin kehte h
}

//CALLING THE FUNCTION
greet("Anmol") // jab apne javascript me kisi function ko call krte hai to ise function invoke kahte hai
greet("Everyone")
greet() // ab agr koi value pass nhi krenge to undefined aayega


// STORING THE FUNCTION IN A VARIABLE
let greet = function(Name) { // jab apne kisi function ko variable me store krte hai to use anonymous bnana pdta hai and iske liye fucntion ko koi name nhi denge
    console.log("Mood Gorning,", Name, "😊"); 
}
greet("Anmol") // sirf greet likhne se print nhi hoga kyoki varibale me function hai to parenthesis use krne pdenge

console.log(x);
var x = 10 // ab isko run krenge to output undefined aayega kyoki apne call pahle kar rhe hai and declare baad me
console.log(x);

console.log("Hello Guys"); 
var x = 67
console.log(x);
var z = 89
console.log(z);

console.log(x);
let x = 9 
// jab apno ne var use kra tha to undefined aa rha tha and ab apne ne let use kra hai to error aayega ki can not access x before its intialization
// jab apne kisi variable ko uske intialization se pehle access krenge to use hoisting kehte hai, function ko declare krne se pehle access kre to hoising kehte hai
// and is case me jo upr variable hoga jaise ki x vo aise zone me hai jise kehte hai TDZ (Temporal Dead Zone). Jab bhi apne kisi variable ko declare krte hai let ya const se and intialization se pehle krte hai to use TDZ kehte hai
// var use krte hai to error nhi aata to pta nhi lgta ki kya glti hai and let and const me pta lag jata hai ki error kya hai, and TDZ mtlb apne use access to kar skte hai but error aayega