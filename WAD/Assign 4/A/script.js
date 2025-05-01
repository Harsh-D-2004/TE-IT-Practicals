$(document).ready(function () {
  var products = [
    { id: 1, name: "T-Shirt", price: 300 },
    { id: 2, name: "Sneakers", price: 1500 },
    { id: 3, name: "Cap", price: 200 },
    { id: 4, name: "Scarf", price: 900 },
    { id: 5, name: "Belt", price: 300 }
  ];

  var cart = [];

  products.forEach(function (product) {
    $("#product-list").append(
      `<div class="ui-body ui-body-a ui-corner-all ui-shadow">
        <h3>${product.name}</h3>
        <p>Price: ₹${product.price}</p>
        <a href="#" class="ui-btn ui-btn-inline ui-mini" onclick="addToCart(${product.id})">Add to Cart</a>
      </div><br>`
    );
  });

  window.addToCart = function (productId) {
    var product = products.find(p => p.id === productId);
    cart.push(product);
    renderCart();
  };

  function renderCart() {
    $("#cart").empty();
    cart.forEach(function (item, index) {
      $("#cart").append(
        `<div class="ui-body ui-body-b ui-corner-all ui-shadow">
          ${item.name} - ₹${item.price}
          <a href="#" class="ui-btn ui-btn-inline ui-mini ui-btn-b" onclick="removeFromCart(${index})">Remove</a>
        </div><br>`
      );
    });
  }

  window.removeFromCart = function (index) {
    cart.splice(index, 1);
    renderCart();
  };
});
