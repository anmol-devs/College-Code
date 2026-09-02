import React from 'react';
import styled from 'styled-components';

const Button = styled.button`
  background-color: ${(props) =>
    props.primary ? 'blue' : 'gray'};

  color: white;
  padding: 10px 20px;
  border: none;
  margin: 10px;
  cursor: pointer;
`;

function StyledButtons() {
  return (
    <div style={{ textAlign: 'center' }}>

      <Button primary>
        Primary Button
      </Button>

      <Button>
        Secondary Button
      </Button>

    </div>
  );
}

export default StyledButtons;