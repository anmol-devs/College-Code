import React, { Component } from "react";
class CourseList extends Component {
  render() {
    const courses = [
      "Web Developmen",
      "React JS",
      "Cyber Security",
      "Data Structures",
      "Machine Learning",
    ];
    return (
      <div>
        <h2> Courses: </h2>
        <ul>
          {courses.map((course, index) => (
            <li key={index}>{course}</li>
          ))}
        </ul>
      </div>
    );
  }
}
export default CourseList;