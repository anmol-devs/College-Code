import React, { Component } from "react";
class StudentClass extends Component {
  componentDidMount() {
    console.log("StudentClass Component Mounted");
  }

  componentWillUnmount() {
    console.log("StudentClass Component Unmounted");
  }

  render() {
    const students = [
      { name: "Yash", age: 20 },
      { name: "Prakhar", age: 22 },
      { name: "Pawan", age: 19 },
      { name: "Ananaya", age: 25 },
    ];

    return (
      <div>
        <h3>Studnet List (Class Component)</h3>
        <ul>
          {students.map((student, index) => (
            <li key={index}>
              {student.name} - {student.age} years
            </li>
          ))}
        </ul>
      </div>
    );
  }
}
export default StudentClass;