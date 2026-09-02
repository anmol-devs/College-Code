import React, { useState } from "react";

function App() {

  const [count, setCount] = useState(0);
  const [name, setName] = useState("");
  const [show, setShow] = useState(false);

  return (
    <div style={{ textAlign: "center", marginTop: "40px" }}>
      <h1>React Functionalities Demo</h1>

      {/* Counter Section */}
      <h2>Counter: {count}</h2>

      <button onClick={() => setCount(count + 1)}>
        Increase
      </button>

      <button onClick={() => setCount(count - 1)}>
        Decrease
      </button>

      <hr />

      {/* Input Handling Section */}
      <h2>Enter Your Name</h2>

      <input
        type="text"
        placeholder="Enter name"
        onChange={(e) => setName(e.target.value)}
      />

      <h3>Hello {name}</h3>

      <hr />

      {/* Conditional Rendering */}
      <button onClick={() => setShow(!show)}>
        Toggle Message
      </button>

      {show && <h2>Welcome to JECRC BTech 4th sem.</h2>}

    </div>
  );
}

export default App;