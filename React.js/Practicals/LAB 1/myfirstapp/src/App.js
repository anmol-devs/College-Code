class student {
  constructor(name, age, grade) {
    this.name = name;
    this.age = age;
    this.grade = grade;
  }

  displayDetails(course, sem) {
    console.log("Name: " + this.name);
    console.log("Age: " + this.age);
    console.log("Grade: " + this.grade);
    console.log("Course: " + course);
    console.log("Semester: " + sem);
  }
}

const student1 = new student("Alice", 20, "A");
student1.displayDetails("Computer Science", 3);