document.getElementById("registrationForm").addEventListener("submit", function(event) {
    event.preventDefault(); 


    let userData = {
        name: document.getElementById("name").value,
        email: document.getElementById("email").value,
        password: document.getElementById("password").value
    };

    let xhr = new XMLHttpRequest();
    xhr.open("POST", "https://jsonplaceholder.typicode.com/posts", true);
    xhr.setRequestHeader("Content-Type", "application/json");

    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4 && xhr.status === 201) {
            console.log("User registered:", userData);

            let users = JSON.parse(localStorage.getItem("users")) || [];
            users.push(userData);
            localStorage.setItem("users", JSON.stringify(users));

            window.location.href = "list.html";
        }
    };

    xhr.send(JSON.stringify(userData));
});
