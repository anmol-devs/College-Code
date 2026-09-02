import React, { useState } from "react";
import InfoCard from "./InfoCard";

function TaskManager() {
    const [tasks, setTasks] = useState("Complete React Lab");

    const updateTask = () => {
        setTasks("Prepare Advanced React Notes");
    };

    return(

        <div style={{
            border: "2px solid black",
            padding: "15px",
            margin: "10px",
            borderRadius: "8px",
            backgroundColor: "white"
        }}>
            <h2>Hello</h2>
            { <InfoCard
                title={`Task Manager: ${tasks}`}
                />}

            <button onClick={updateTask} style={{ marginTop: "10px"}}>Update Task</button>
        </div>
    );
}
export default TaskManager;