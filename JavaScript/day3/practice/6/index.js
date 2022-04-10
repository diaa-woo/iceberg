const imgs = [
    "images/hip1.jpg",
    "images/hip2.jpg",
    "images/hip3.jpg"
]

for (let i = 0; i<3; i++) {
    document.getElementById('container').innerHTML = `<img class="team-img" src="images/hip${i}.jpg">`
} 