import React, { useState } from "react";

function App() {
  const [inputText, setInputText] = useState("");
  const [displayText, setDisplayText] = useState("");

  // Dynamic course list (STATE)
  const [courses, setCourses] = useState([
    "React JS",
    "Node JS"
  ]);

  const [newCourse, setNewCourse] = useState("");

  // Handle typing
  const handleChange = (e) => {
    setInputText(e.target.value);
  };

  // Update text
  const handleClick = () => {
    setDisplayText(inputText);
  };

  // Add new course (DYNAMIC PART)
  const handleAddCourse = () => {
    if (newCourse.trim() !== "") {
      setCourses([...courses, newCourse]); // updating state
      setNewCourse("");
    }
  };


  return (
    <div style={styles.container}>
      <div style={styles.card}>
        <h1 style={styles.heading}> Lab 8: Dynamic React App</h1>

        {/* onChange */}
        <div style={styles.section}>
          <h2>1. onChange Event</h2>
          <input
            type="text"
            placeholder="Enter text..."
            value={inputText}
            onChange={handleChange}
            style={styles.input}
          />
          <p>Typed Text: {inputText}</p>
        </div>

        {/* onClick */}
        <div style={styles.section}>
          <h2>2. onClick Event</h2>
          <button style={styles.button} onClick={handleClick}>
            Update Text
          </button>
          <p>Updated Text: {displayText}</p>
        </div>

        {/* Dynamic Course Section */}
        <div style={styles.section}>
          <h2>3. Dynamic Course List</h2>

          {/* Add Course */}
          <input
            type="text"
            placeholder="Add new course"
            value={newCourse}
            onChange={(e) => setNewCourse(e.target.value)}
            style={styles.input}
          />
          <button style={styles.addBtn} onClick={handleAddCourse}>
            Add Course
          </button>

          {/* Course List */}
          <ul style={styles.list}>
            {courses.map((course, index) => (
              <li key={index} style={styles.listItem}>
                {/* <button
                  style={styles.courseButton}
                  onClick={() => handleCourseClick(course)}
                > */}
                  {course}
                {/* </button> */}
              </li>
            ))}
          </ul>
        </div>
      </div>
    </div>
  );
}

// Styles
const styles = {
  container: {
    display: "flex",
    justifyContent: "center",
    alignItems: "center",
    height: "100vh",
    background: "linear-gradient(to right, #667eea, #764ba2)"
  },
  card: {
    backgroundColor: "#fff",
    padding: "30px",
    borderRadius: "15px",
    textAlign: "center",
    width: "400px",
    boxShadow: "0 10px 25px rgba(0,0,0,0.3)"
  },
  heading: {
    color: "#2c3e50"
  },
  section: {
    marginBottom: "20px"
  },
  input: {
    padding: "10px",
    width: "80%",
    margin: "10px 0",
    borderRadius: "8px",
    border: "1px solid #ccc"
  },
  button: {
    padding: "10px 20px",
    backgroundColor: "#3498db",
    color: "#fff",
    border: "none",
    borderRadius: "8px",
    cursor: "pointer"
  },
  addBtn: {
    padding: "10px 15px",
    backgroundColor: "#e67e22",
    color: "#fff",
    border: "none",
    borderRadius: "8px",
    cursor: "pointer",
    marginLeft: "10px"
  },
  list: {
    listStyle: "none",
    padding: 0
  },
  listItem: {
    margin: "8px 0"
  },
  courseButton: {
    padding: "8px 15px",
    backgroundColor: "#2ecc71",
    color: "#fff",
    border: "none",
    borderRadius: "6px",
    cursor: "pointer"
  }
};

export default App;