import React from 'react';

function InlineStyle() {

  const style = {
    color: 'white',
    backgroundColor: 'blue',
    padding: '15px',
    textAlign: 'center'
  };

  return (
    <h1 style={style}>
      Inline Styling Example
    </h1>
  );
}

export default InlineStyle;