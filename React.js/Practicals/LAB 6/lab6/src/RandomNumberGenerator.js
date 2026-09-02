import React, { useState } from "react";

function RandomNumberGenerator() {

  const [randomNumber, setRandomNumber] = useState(generateRandomNumber());

  function generateRandomNumber() {
    return Math.floor(Math.random() * 1000);
  }

  const generateNewNumber = () => {
    setRandomNumber(generateRandomNumber());
  };

  return (
    <div style={{ textAlign: "center", marginTop: "50px"}}>
        <h2>Random Number: {randomNumber}</h2>

        <button onClick={generateNewNumber}>
            Generate Random Number
        </button>
    </div>
  );
}

export default RandomNumberGenerator;