import React from "react";
import RegistrationForm from "./components/registrationForm";
import StudentList from "./components/studentList";

function App() {
  return (
    <div style={{ textAlign: "center" }}>
      <h1>React + Redux Practical Lab</h1>

      <RegistrationForm />
      <hr />
      <StudentList />
    </div>
  );
}

export default App;