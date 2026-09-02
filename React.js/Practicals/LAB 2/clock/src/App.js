import React, { useState, useEffect } from "react";
import './App.css';

// Child Component (Uses Props)
function Greeting(props) {
  return (
    <div>
      <h2>Hello, {props.name}!</h2>
      <p>Course: {props.course}</p>
    </div>
  );
}

// Clock Component (Uses State)
function Clock() {
  const [time, setTime] = useState(new Date());

  useEffect(() => {
    const timer = setInterval(() => {
      setTime(new Date());
    }, 1000);

    return () => clearInterval(timer);
  }, []);

  return (
    <div>
      <h3>Current Time:</h3>
      <p>{time.toLocaleTimeString()}</p>
    </div>
  );
}

// Main Component
function App() {
  const [subject, setSubject] = useState("React Basics");

  const getWelcomeMessage = () => {
    return "Welcome to React Class!";
  };

  return (
    <div className="container">
      <h1 title="React Introduction">{getWelcomeMessage()}</h1>

      <div>
        <Greeting name="Anmol" course={subject} />
        <Greeting name="Student" course="Frontend Development" />
      </div>

      <Clock />

      <button onClick={() => setSubject("Advanced React")}>
        Change Course
      </button>
    </div>
  );
}

export default App;