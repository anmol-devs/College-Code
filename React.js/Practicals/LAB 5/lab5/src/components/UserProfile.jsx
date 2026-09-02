import React, { useState, useEffect } from "react";
import InfoCard from "./InfoCard";

function UserProfile() {
    const [user, setUser] = useState({
        name: "Anmol Singh",
        role: "Admin",
    });
    const [showInfo, setShowInfo] = useState(false);
    //mounting of userprofile 
    useEffect(() => {
        console.log("User Profile Mounted");
        return () => {
            console.log("User Profile Unmounted");
        };
    }, []);

    const updateUser = () => {
        setUser({
            name: "Anmol Singh",
            role: "Senior Developer",
        });
    };

    return (
        <div style={{
            border: "3px solid black",
            padding: "20px",
            width: "350px",
            borderRadius: "10px",
            backgroundColor: "white"
        }}>
            <h2>User Profile</h2>

            <p><strong>Name:</strong> {user.name}</p>
            <p><strong>Role:</strong> {user.role}</p>

            <button onClick={updateUser}>Update User</button>

            <button onClick={() => setShowInfo(!showInfo)}
                style={{ marginLeft: "10px"}}>Toggle Infocard</button>

{/* indocard mounted inside userprofile */}
            {showInfo && (
                <InfoCard
                title= "Additional Info"
                content={`User ${user.name} work as ${user.role}`}
                />
            )}
        </div>
    );
}

export default UserProfile;