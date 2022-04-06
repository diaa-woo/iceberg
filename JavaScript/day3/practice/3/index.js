let hello = "hello";

localStorage.setItem("hello", JSON.stringify(hello));

let ValueLocalStorage = localStorage.getItem("hello");
console.log(ValueLocalStorage);
localStorage.clear(); 
ValueLocalStorage = localStorage.getItem("hello");
console.log(ValueLocalStorage);