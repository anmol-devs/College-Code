import React, { useState } from "react";
import CourseList from "./courseList";
import StudentClass from "./studentClass";
import StudentFunctional from "./studentFunctional";

function App() {
  const [showCourse, setShowCourses] = useState(false);
  const [showStudent, setShowStudents] = useState(false);
  return (
    <div style={{ padding: "20px" }}>
      <h1>React Mount and Unmount Example</h1>
      <button onClick={() => setShowCourses(!showCourse)}>
        Toggle Course List
      </button>
      <br></br>
      <button onClick={() => setShowStudents(!showStudent)}>
        Toggle Student List
      </button>
      <hr />

      {showCourse && <CourseList />}
      {showStudent && <StudentClass />}
      <StudentFunctional />
    </div>
  );
}

export default App;