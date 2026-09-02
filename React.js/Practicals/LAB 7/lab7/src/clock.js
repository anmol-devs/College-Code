import React, { Component } from "react";

class Clock extends Component {
    constructor(props) {
        super(props);
        this.state = {
            time: new Date()
        };
        console.log("Constructor: Clock Initialized");
    }

    componentDidMount() {
        console.log("Clock Mounted");
        this.timer = setInterval(() => {
            this.setState({ time: new Date() });
        }, 1000);
    }

    componentDidUpdate() {
        console.log("Clock Updated");   
    }

    componentWillUnmount() {
       console.log("Clock Unmounted");
       clearInterval(this.timer);
    }

    render() {
        return (
            <div>
                <h2>Current Time:</h2>
                <h3>{this.state.time.toLocaleTimeString()}</h3>
            </div>
        );
    }
}

export default Clock;