let string1 = "좋아하는 과일";
let array1 = ["사과", "바나나", "딸기"]
let string2 = "싫어하는 채소";
let array2 = ["시금치", "오이"];

function generateSentence(desc, arr) {
    console.log("제가 " + desc + " "+arr.length +"은 " + arr[0] + ", " + arr[1] + ", " + arr[2] + " 입니다.");
}

generateSentence(string1, array1);