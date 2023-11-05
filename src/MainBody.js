import React from "react"
import ArticleBlock from "./ArticleBlock"
import data from "./temp.json"
import TextBox from "./TextBox"
import Form from "./Form"


class MainBodyTemp extends React.Component{
    constructor(){
        super()
        this.state={
            val:1,
            text:"Post an article" 
        }
        this.flip = this.flip.bind(this)
        this.formshow = this.formshow.bind(this)
    }

    flip(){
        this.setState(prevState=>{
            if(prevState.val === 1){
                return{
                    val:2,
                    text:"Go Back"
                }
            }
            else{
                return{
                    val:1,
                    text:"Post a quote"
                }
            }
                
            
        })    
    }

    formshow(){
        this.setState(pervState=>{
            return{
                val:3,
                text:"Go Back"
            }
        })
    }


    render(){
        return(
            <div>
                <div className="topnav">
                <a href="#">All Quotes</a>
                <a href="#">Trending Posts</a>
                <button onClick={this.formshow} id="login">Login</button>
                </div>
            <div>
                <button onClick={this.flip} id="postarticle">{`${this.state.text}`}</button>
            </div>
            <div>
            {(this.state.val === 1) && (data.map(temp=>(
                        <ArticleBlock text={temp} key={temp} />)))}
            {(this.state.val === 2) && (<TextBox />)}
            {(this.state.val === 3) && (<Form />)}
            </div>
            </div>
        )
    }
}

export default MainBodyTemp