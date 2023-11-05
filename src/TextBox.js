import React from "react"

class TextBox extends React.Component{
    render(){
        return(
            <div>
                <form>
                    <textarea rows="20" cols="150" style={{marginTop:"20px"}}>Enter your text here</textarea>
                    <button id="Submitbutton">Submit</button>
                </form>
            </div>
        )
    }
}

export default TextBox 
