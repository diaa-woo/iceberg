async function getRandJokes() {
    let getJokes = new Promise( (resolve, reject) => {
        setTimeout( () => {
            fetch('https://api.chucknorris.io/jokes/random')
                .then(response => response.json())
                .then(json => resolve(json.value));
        }, 1000);
    });
    let result = await getJokes;
    console.log(result);
}

getRandJokes();
