import React, { useRef } from "react";
import { useDispatch } from "react-redux";
import { addStudent } from "../features/students/studentSlice";

const RegistrationForm = () => {
  const nameRef = useRef();
  const emailRef = useRef();
  const courseRef = useRef();

  const dispatch = useDispatch();

  const handleSubmit = (e) => {
    e.preventDefault();

    const student = {
      id: Date.now(),
      name: nameRef.current.value,
      email: emailRef.current.value,
      course: courseRef.current.value,
    };

    dispatch(addStudent(student));

    // Clear form
    nameRef.current.value = "";
    emailRef.current.value = "";
    courseRef.current.value = "";
  };

  return (
    <div>
      <h2>Student Registration</h2>

      <form onSubmit={handleSubmit}>
        <input type="text" placeholder="Name" ref={nameRef} required />
        <br /><br />

        <input type="email" placeholder="Email" ref={emailRef} required />
        <br /><br />

        <input type="text" placeholder="Course" ref={courseRef} required />
        <br /><br />

        <button type="submit">Register</button>
      </form>
    </div>
  );
};

export default RegistrationForm;