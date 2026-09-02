import React, { useEffect } from "react";

function studentFunctional() {
  // eslint-disable-next-line react-hooks/rules-of-hooks
  useEffect(() => {
    console.log("Functional Component Mounted");

    return () => {
      console.log("Functional Component Unmount");
    };
  }, []);
  const students = [
    { name: "Yash", age: 21 },
    { name: "Prakhar", age: 22 },
  ];
  return (
    <div>
      <h3>Student List(Functional Component)</h3>
      <ul>
        {students.map((students, index) => (
          <li key={index}>
            {students.name} - {students.age} years
          </li>
        ))}
      </ul>
    </div>
  );
}
export default studentFunctional;