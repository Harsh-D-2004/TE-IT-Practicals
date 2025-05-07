
document.getElementById("form").addEventListener("submit" , async function(e){
    e.preventDefault();
    

    const formData = new FormData(this);
    const data = new URLSearchParams(formData);

    const response = await fetch("/submit" , {
        method : "POST" ,
        headers : {
            "Content-Type" : "application/x-www-form-urlencoded"
        } ,
        body : data
    })
    
    const result = await response.text();
    alert(result);
});