import React from "react"

class Form extends React.Component{
    render(){
        return(
            <form className="formbox">
                <label>Username</label><br></br>
                <input></input><br></br>
                <label>Password</label><br></br>
                <input></input><br></br>
                <input type="submit" title="Submit"></input>
            </form>
        )
    }
}

export default Form 