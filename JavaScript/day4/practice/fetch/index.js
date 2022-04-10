fetch('https://jsonplaceholder.typicode.com/comments/1')
    .then(response => response.json())
    .then(json => console.log(json));

    fetch('https://jsonplaceholder.typicode.com/posts', {
        method: 'POST',
        body: JSON.stringify({
          title: 'test',
          body: 'why',
          userId: '777',
        }),
        headers: {
          'Content-type': 'application/json; charset=UTF-8',
        },
      })
        .then((response) => response.json())
        .then((json) => console.log(json));