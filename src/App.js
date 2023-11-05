import React from "react"
import Header from "./Header"
import MainBody from "./MainBody"
import Footer from "./Footer"
import TextBox from "./TextBox"


class App extends React.Component{
    render(){
        return(
            <div>
                <Header/>
                <Footer />
            </div>
        )    
    }    
}

export default App