const printUserData = () => {
    return new Promise( (resolve, reject) => {
        const error = true;
        if(error) {
            reject("error");
        }
        else {
            resolve("user data");
        }
    })
}

printUserData()
.catch((error) => console.log(error))
.then((success) => console.log(success));