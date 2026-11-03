// The sample page's script. It sets text with textContent, never as markup.

// The item's title, which the module puts in the page's address.
const title = new URLSearchParams(location.search).get("title");
if (title) {
  document.getElementById("title").textContent = title;
  document.title = title;
}

document.getElementById("origin").textContent = location.origin;

// A file of the module, from the same origin. The policy allows no other.
const list = document.getElementById("greetings");
fetch("greetings.json")
  .then((response) => response.json())
  .then((greetings) => {
    list.replaceChildren(
      ...greetings.map((greeting) => {
        const item = document.createElement("li");
        item.textContent = `${greeting.language}: ${greeting.text}`;
        return item;
      })
    );
  })
  .catch((error) => {
    list.replaceChildren(Object.assign(document.createElement("li"), { textContent: `Not loaded: ${error}` }));
  });

const countButton = document.getElementById("count");
const key = "count";

function showCount() {
  const count = Number(localStorage.getItem(key) || 0);
  countButton.textContent = `Clicked ${count} ${count === 1 ? "time" : "times"}`;
}

countButton.addEventListener("click", () => {
  localStorage.setItem(key, String(Number(localStorage.getItem(key) || 0) + 1));
  showCount();
});
document.getElementById("reset").addEventListener("click", () => {
  localStorage.removeItem(key);
  showCount();
});
showCount();
