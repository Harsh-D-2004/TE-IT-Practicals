$(document).ready(function() {
    var products = [
      { id: 1, name: "T-Shirt", price: 300 },
      { id: 2, name: "Sneakers", price: 1500 },
      { id: 3, name: "Cap", price: 200 },
      { id: 4, name: "Scarf", price: 900 },
      { id: 5, name: "Belt", price: 300 }
    ];
  
    var cart = [];
  
    products.forEach(function(product) {
      $("#product-list").append(
        `<div>
          <strong>${product.name}</strong><br>
          Price: ₹${product.price}<br>
          <button onclick="addToCart(${product.id})">Add to Cart</button>
        </div>`
      );
    });
  
    window.addToCart = function(productId) {
      var product = products.find(p => p.id === productId);
      cart.push(product);
      renderCart();
    }
  
    function renderCart() {
      $("#cart").empty();
      cart.forEach(function(item, index) {
        $("#cart").append(
          `<div>
            ${item.name} - ₹${item.price}
            <button onclick="removeFromCart(${index})">Remove</button>
          </div>`
        );
      });
    }
  
    window.removeFromCart = function(index) {
      cart.splice(index, 1);
      renderCart();
    }
  });
  