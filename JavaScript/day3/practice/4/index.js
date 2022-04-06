let data = [
    {
        player: "Jane",
        score: 52
    }, 
    {
        player: "Mark",
        score: 41
    }
]
const callJaneBtn = document.getElementById('jane-btn');

callJaneBtn.addEventListener("click", function() {
    console.log(data[1].score);
})