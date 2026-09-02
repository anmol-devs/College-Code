import React, { useEffect } from "react";

function InfoCard({ title, content }) {

    useEffect(() => {
        console.log(`${title} Mounted`);

        return () => {
            console.log(`${title} Unmounted`);
        };
    }, [title]);

    return (
        <div style={{
            border: "2px solid #444",
            padding: "15px",
            margin: "10px",
            borderRadius: "8px",
            backgroundColor: "#f4f4f4"
        }}>
            <h3>{title}</h3>
            <p>{content}</p>
        </div>
    );
}

export default InfoCard;