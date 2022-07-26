
const nav_items = document.querySelectorAll('.nav_item')
console.log(nav_items)

let arr = new Array();

for (let i=0; i<nav_items.length; i++){
  arr.push(nav_items[i].textContent)
  
}
console.log(arr)