document.getElementById("registrationForm").addEventListener("submit", function(event) {
    event.preventDefault(); // Prevent form refresh

    // Get input values
    let userData = {
        name: document.getElementById("name").value,
        email: document.getElementById("email").value,
        password: document.getElementById("password").value
    };

    // Mock AJAX POST request
    let xhr = new XMLHttpRequest();
    xhr.open("POST", "https://jsonplaceholder.typicode.com/posts", true);
    xhr.setRequestHeader("Content-Type", "application/json");

    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4 && xhr.status === 201) {
            console.log("User registered:", userData);

            // Store in local storage
            let users = JSON.parse(localStorage.getItem("users")) || [];
            users.push(userData);
            localStorage.setItem("users", JSON.stringify(users));

            // Redirect to list page
            window.location.href = "list.html";
        }
    };

    xhr.send(JSON.stringify(userData));
});
