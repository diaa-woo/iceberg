let string1 = "좋아하는 과일";
let array1 = ["사과", "바나나", "딸기"]
let string2 = "싫어하는 채소";
let array2 = ["시금치", "오이"];
let string = "";

function generateSentence(desc, arr) {
    string += "제가 " + string1 + " "+ arr.length + "개는 ";
    for(let i = 0; i<arr.length; i++) {
        string += arr[i];
        if(i != arr.length -1) string += ", "; 
    }
    string += "입니다.";
    return string;
}

console.log(generateSentence(string1, array1));
console.log(generateSentence(string2, array2));