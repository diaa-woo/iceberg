let fruits = ['banana', 'apple', 'pineapple', 'strawberry', 'orange'];

for(let i = 0; i<fruits.length; i++) {
    console.log(fruits[i]);
}
console.log('.');
fruits.pop();  //배열 맨 뒤에 있는 원소 삭제
for(let i = 0; i<fruits.length; i++) {
    console.log(fruits[i]);
}
console.log('.');
fruits.push('banana');  //배열 맨 뒤에서 부터 괄호안의 원소 추가
for(let i = 0; i<fruits.length; i++) {
    console.log(fruits[i]);
}
console.log('.');
fruits.shift('banana'); //배열 맨 앞에서 부터 괄호안의 원소 추가
for(let i = 0; i<fruits.length; i++) {
    console.log(fruits[i]);
}
console.log('.');
fruits.unshift(); //배열 맨 뒤에 있는 원소 삭제