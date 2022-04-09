function addressMaker(address) {
    const newAddress = {
        city: address.city,
        state: address.state,
        country: 'United States'
    };
    const {city, state, country} = newAddress;
    console.log(newAddress);
}

addressMaker({city: 'Austin', state: 'Texas'});