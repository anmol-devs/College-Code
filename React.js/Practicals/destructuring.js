const numbers = [1, 2, 3, 4, 5];
const [first, second, third, , fifth] = numbers;
console.log(first, second, fifth);
// request and response
// after execution - the array is assigned to a variable (at the backend)

//
const [x = 0, y = 0] = [1];
console.log(x, y);

// rest operator ---> used in function
// spread operator  ---> used in array , but syntax same as that of rest operator

const numbers1 = [55, 7, 9, 6, 44];
const [firstNum, secondNum, ...rest] = numbers1;
console.log(firstNum);
console.log(rest);

// swapping values
let p = 5,
  q = 10;
[p, q] = [q, p]; // destructuring
console.log(p, q);

// array destruction
const user = {
  name: "john",
  age: 30,
  email: "jon@email.com",
  address: {
    city: "NYC",
    country: "USA",
  },
};

const {
  address: { city, country },
} = user;
console.log(city, country);

//example :
const original = [1, 2, 4, 5];
const copy = [...original]; // spread and destruturing togather
console.log(copy);

// mergin
const arr1 = [1, 2, 3];
const arr2 = [4, 5, 6];
const merged = [...arr1, ...arr2]; // although arrays can be merged using loops , but here we used spread operator
const newArray = [0, ...arr1, 4];
console.log(newArray);
console.log(merged);

// converting string into array

const str = "hello";
const chars = [...str];
console.log(chars);

// function arguments

const numbers3 = [1, 2, 3];
// console.log(Math.min(numbers3)); // here the whole array is being passed , that's why the output is 
console.log(Math.min(...numbers3));

// objects can also be merged using spread operators , same as that of array
const obj1 = {a:1,b:2};
const obj2 = {d:4,b:3}; // b will be overwritten 
const objMerged = {...obj1 , ...obj2};
console.log(objMerged);

// rest operator as parameter ---> will pass the arguments one by one from an array or any iterable

function sum(...num){
  return num.reduce((total , nums) => total + nums, 0);}// by default starting value will also be 0
  // total ---> accumulator
  console.log(sum(1,2,3,4));

  