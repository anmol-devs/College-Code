import React from "react";
import { useSelector } from "react-redux";

const StudentList = () => {
  const students = useSelector((state) => state.students);

  return (
    <div>
      <h2>Registered Students</h2>

      {students.length === 0 ? (
        <p>No students yet</p>
      ) : (
        <ul>
          {students.map((student) => (
            <li key={student.id}>
              <b>{student.name}</b> | {student.email} | {student.course}
            </li>
          ))}
        </ul>
      )}
    </div>
  );
};

export default StudentList;