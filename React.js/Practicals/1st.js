// Using class keyword class, creating object and passing parameters to the method()

class Student {
  constructor(name , age){
    this.name = name;
    this.age = age;
  }
  displayDetails(course , semester){
    console.log("Name : " + this.name);
    console.log("Age : " + this.age);
    console.log("course : " + course);
    console.log("semester : " + semester);
  }
}


const student1 = new Student("John" , 20);
student1.displayDetails("CSE" , 4);