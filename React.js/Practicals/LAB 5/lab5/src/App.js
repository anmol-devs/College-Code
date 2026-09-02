// how to render multiple components and render child component in the parent component
//condition rendering
// components get mounted and unmounted

import React, { useState } from "react";
import UserProfile from "./components/UserProfile";
import TaskManager from "./components/TaskManager";

function App() {
  const [showProfile, setShowProfile] = useState(true);
  const [showTaskManager, setShowTaskManager] = useState(true);

  return (
    <div style={{ textAlign: "center", marginTop: "40px" }}>
      <h1> Advanced React Lab - Mounting and Unmounting Demo</h1>
      <div style={{ marginBottom: "20px" }}>
        <button onClick={() => setShowProfile(!showProfile)}>
          Toggle User Profile
        </button>
        <button
          onClick={() => setShowTaskManager(!showTaskManager)}
          style={{ marginLeft: "10px" }}
        >
          Toggle Task Manager
        </button>
      </div>
      <div style={{ display: "flex", justifyContent: "center", gap: "40px" }}>
        {showProfile && <UserProfile />}
        {showTaskManager && <TaskManager />}
      </div>
    </div>
  )};

  export default App;