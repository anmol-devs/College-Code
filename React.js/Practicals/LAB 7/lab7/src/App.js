import React, { Component } from "react";
import Clock from "./clock";

class App extends Component {
  constructor(props) {
    super(props);
    this.state = {
      showClock: true
    };
  }

  toggleClock = () => {
    this.setState({ showClock: !this.state.showClock });
  };

  render() {
    return (
      <div style={{ textAlign: "center" }}>
        <h1>Lifecycle Methods Lab</h1>

        <button onClick={this.toggleClock}>
          Toggle Clock
        </button>

        {/* Multiple Elements */}
        {/* <Logger /> */}

        {this.state.showClock && <Clock />}
      </div>
    );
  }
}

export default App;