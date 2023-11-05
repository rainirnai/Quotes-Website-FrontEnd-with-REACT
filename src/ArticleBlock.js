import React from "react"

class ArticleBlock extends React.Component{
    constructor(props){
        super(props)
        this.state = {
            Ucount : this.props.text.upvote,
            Dcount: this.props.text.downvote
        }
        this.handleUVote = this.handleUVote.bind(this)
        this.handleDVote = this.handleDVote.bind(this)

    }


    handleUVote(){
        this.setState(prevState=>{
            return{
                Ucount : prevState.Ucount + 1
            }
        })
        
    }

    handleDVote(){
        this.setState(prevState=>{
            return{
                Dcount : prevState.Dcount + 1 
            }
        })
    }

    render(){
        return(
        <div className="card">
            <p id="quotetext">{`${this.props.text.body}`}</p>
            <hr/>
            <text className="UDVal">{this.state.Ucount}</text>
            <button type="button" className="UVote" onClick={this.handleUVote}>&#128077;Upvote</button>
            <text className="UDVal">{this.state.Dcount}</text>
            <button type="button" className="DVote" onClick={this.handleDVote}>&#128078;Downvote</button>
            <text style={{float:"right"}}>- {this.props.text.saidby}</text>
        </div>
        )
    }
}

export default ArticleBlock