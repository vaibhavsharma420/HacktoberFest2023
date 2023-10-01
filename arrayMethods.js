// Create an array
const fruits = ["Banana", "Orange", "Apple", "Mango"];

// Iterate over the array using forEach()
fruits.forEach((fruit) => {
  console.log(fruit);
});

// Check if the array contains a specific element using includes()
const isOrangeIncluded = fruits.includes("Orange");
console.log(isOrangeIncluded); // true

// Add a new element to the end of the array using push()
fruits.push("Lemon");
console.log(fruits); // ["Banana", "Orange", "Apple", "Mango", "Lemon"]

// Create a new array containing only the fruits that start with the letter "A" using filter()
const fruitsStartingWithA = fruits.filter((fruit) => {
  return fruit[0] === "A";
});
console.log(fruitsStartingWithA); // ["Apple"]

// Calculate the total number of fruits in the array using reduce()
const totalFruits = fruits.reduce((accumulator, currentValue) => {
  return accumulator + 1;
}, 0);
console.log(totalFruits); // 5

// Sort the array in ascending order using sort()
fruits.sort();
console.log(fruits); // ["Apple", "Banana", "Lemon", "Mango", "Orange"]

// Create a new array containing the first two fruits in the original array using slice()
const firstTwoFruits = fruits.slice(0, 2);
console.log(firstTwoFruits); // ["Apple", "Banana"]

// Remove the first element of the array and insert the new element "Kiwi" at the beginning using splice()
fruits.splice(0, 1, "Kiwi");
console.log(fruits); // ["Kiwi", "Apple", "Banana", "Lemon", "Orange"]
